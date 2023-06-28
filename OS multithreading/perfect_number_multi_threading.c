//AI20BTECH11010 - os - threads 
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int N;
#define range_numbers 10000 //if wanted more range of numbers can be changed 
int Num_thread_link[range_numbers];

struct parameters_of_thread {
  int ending_number;
  int starting_number;
  int thread_ID;
};

// this functions finds if a number is perfect or not
bool is_perfect_num(int num) {
  int i, sum_of_factors = 0;
  for (i = 1; i <= (int)(num / 2); i++) {
    if (num % i == 0)
      sum_of_factors += i;
  }
  if (sum_of_factors == num)
    return true;
  else
    return false; }


void* Perfects_find( void* arguments) {
  char file_name_string[30];

int beg_num=((struct parameters_of_thread *)arguments)->starting_number;
int last_num=((struct parameters_of_thread *)arguments)->ending_number;
int ID_num=((struct parameters_of_thread *)arguments)->thread_ID; 

 snprintf(file_name_string, 30, "OutFile%d",ID_num );
  FILE *fp_thread = fopen(file_name_string, "w");
  for (int j = beg_num; j <=last_num; j++) {
    if (is_perfect_num(j)) {
      fprintf(fp_thread, "%d : Is a perfect number\n", j);

       Num_thread_link[j] = ID_num ;}
      else {
      fprintf(fp_thread, "%d : Not a perfect number\n", j);
    
        Num_thread_link[j] = -1;
      }
    }
 fclose(fp_thread);

  return NULL;
  }

void outmain(int id_num, FILE* outfp) {
  fprintf(outfp, "Thread%d:", id_num);
  for (int j = 1; j <= N; j++) {
    if (Num_thread_link[j] == id_num && is_perfect_num(j)) {
      fprintf(outfp, " %d", j);
    }
  }
  fprintf(outfp, "\n");
}
/*
void outmain( int id_num ,FILE * outfp ) {

    fprintf(outfp,"Thread%d :",id_num);
    for(int j=1;j<=N;j++)
    {
        if(Num_thread_link[j]==id_num)
        fprintf(outfp,"%d ",j);
    
    }
    
  }
  
int main() {
  FILE *input_fp = fopen("input.txt", "r");
   FILE *output_fp = fopen("OutMain", "w");

  
  int K;
  fscanf(input_fp, "%d %d", &N, &K);
  fclose(input_fp);

  pthread_t Threads[K];
  double gap = (double)N / K ;
  
   struct parameters_of_thread *thread_parameters_store[K];
    for (int i = 0; i < K; i++)
    {
     thread_parameters_store[i] = malloc(sizeof(struct parameters_of_thread));
    }

  for (int i = 0; i < K; i++) {
    
      
    thread_parameters_store[i]->thread_ID = i+1;
    thread_parameters_store[i]->starting_number = ((int)gap * i) + 1;
    thread_parameters_store[i]->ending_number = (int)gap * (i + 1);
    
    if (i == K - 1) // last thread
    thread_parameters_store[i]->ending_number = N;
     

    if (pthread_create(&Threads[i], NULL,Perfects_find,thread_parameters_store[i]) != 0)
      fprintf(stderr, "Error:thread %d not created\n", i);
  }

  for (int i = 0; i < K; i++) {
    if (pthread_join(Threads[i], NULL) != 0)
      fprintf(stderr, "Error:thread %d not joined\n", i);
     }
     
  for(int i=0;i<K;i++)
    {
        outmain(i+1,output_fp);

    }
    
    for (int i = 0; i < K ; i++)
     {
         free(thread_parameters_store[i]);
    }
   fclose(output_fp);
   
   

  return EXIT_SUCCESS;
} */


int main() {
  FILE* input_fp = fopen("input.txt", "r");
  FILE* output_fp = fopen("OutMain", "w");

  int K;
  fscanf(input_fp, "%d %d", &N, &K);
  fclose(input_fp);

  pthread_t Threads[K];
  double gap = (double)N / K;

  struct parameters_of_thread* thread_parameters_store[K];
  for (int i = 0; i < K; i++) {
    thread_parameters_store[i] = malloc(sizeof(struct parameters_of_thread));
  }

  for (int i = 0; i < K; i++) {
    thread_parameters_store[i]->thread_ID = i + 1;
    thread_parameters_store[i]->starting_number = ((int)gap * i) + 1;
    thread_parameters_store[i]->ending_number = (int)gap * (i + 1);

    if (i == K - 1) // last thread
      thread_parameters_store[i]->ending_number = N;

    if (pthread_create(&Threads[i], NULL, Perfects_find, thread_parameters_store[i]) != 0)
      fprintf(stderr, "Error: thread %d not created\n", i);
  }

  for (int i = 0; i < K; i++) {
    if (pthread_join(Threads[i], NULL) != 0)
      fprintf(stderr, "Error: thread %d not joined\n", i);
  }

  for (int i = 0; i < K; i++) {
    outmain(i + 1, output_fp);
  }

  for (int i = 0; i < K; i++) {
    free(thread_parameters_store[i]);
  }
  fclose(output_fp);

  return EXIT_SUCCESS;
}
