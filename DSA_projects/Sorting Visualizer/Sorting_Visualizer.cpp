#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;


const int ARRAY_SIZE = 20;
const int MAX_VALUE = 100;
const int DELAY_MS = 1000;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
} 

void printArray_two_indexes(int arr[], int size , int first , int second)
{  
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     int color = 7 ;
  
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }


        if (i == first)
        {
            // Highlight the specified index with a different color
            SetConsoleTextAttribute(hConsole, 4 );  
        }
        else if(i==second )
        {  // Highlight the specified index with a different color
            SetConsoleTextAttribute(hConsole, 2 );  
		}
            
        else
        {
            SetConsoleTextAttribute(hConsole, color );
        }

        cout << arr[i];
    }
    cout << endl;

    // Reset console color
    SetConsoleTextAttribute(hConsole, 7);
}

void printArray_seg(int arr[], int size , int first , int second ,int high)
{  
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     int color = 7 ;
  
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }

        if(i==high )
        {  // Highlight the specified index with a different color
            SetConsoleTextAttribute(hConsole, 2 );  
		}
        else if (i >= first && i<=second)
        {
            // Highlight the specified index with a different color
            SetConsoleTextAttribute(hConsole, 4 );  
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 7 );
        }

        cout << arr[i];
    }
    cout << endl;

    // Reset console color
    SetConsoleTextAttribute(hConsole, 7);
}


void printArray_sections(int arr[], int size , int first , int mid ,int right)
{  
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     int color = 7 ;
  
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }

        if(i> mid && i<=right )
        {  // Highlight the specified index with a different color
            SetConsoleTextAttribute(hConsole, 2 );  
		}
        else if (i >= first && i<=mid)
        {
            // Highlight the specified index with a different color
            SetConsoleTextAttribute(hConsole, 4 );  
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 7 );
        }

        cout << arr[i];
    }
    cout << endl;

    // Reset console color
    SetConsoleTextAttribute(hConsole, 7);
}



void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size)
{   
bool swapped=false;

    for (int i = 0; i < size - 1; i++)
    {   
               
        swapped=false;
        
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                
				swapped=true; 
                
                  // Clear the console
                  system("cls") ;
                 
                 cout<<"Iteration:  " <<i+1<<"\n " ;
                    
                // Visualize the array
                printArray_two_indexes(arr, size , j , j+1);
                
                  
				  // Sleep for a short delay
                Sleep(DELAY_MS);

            }
        }
        
        if(swapped==false)
          return ;
    }
}



void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
    
        swap(&arr[i], &arr[minIndex]);

        // Clear the console
        system("cls");
        
        cout<<"Iteration:  " <<i+1<<"\n " ;
        
        // Visualize the array
        printArray_two_indexes(arr, size , i , minIndex);
     

        // Sleep for a short delay
        Sleep(DELAY_MS);
    }
}



void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;

            // Clear the console
            system("cls");

            cout<<"Iteration:  " <<i<<"   key :"<<key<<"\n " ;
            // Visualize the array
            printArray_seg(arr, size , 0 ,i , j+1);
      

            // Sleep for a short delay
            Sleep(DELAY_MS);
        }

        arr[j + 1] = key;
    }
}



void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;

        // Clear the console
        system("cls");

        // Visualize the array
        printArray_sections(arr, ARRAY_SIZE ,left ,mid , right);

        // Sleep for a short delay
        Sleep(DELAY_MS);
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;

        // Clear the console
        system("cls");

        // Visualize the array
        printArray_sections(arr, ARRAY_SIZE, left ,mid, right);

        // Sleep for a short delay
        Sleep(DELAY_MS);
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;

        // Clear the console
        system("cls");

        // Visualize the array
        printArray_sections(arr, ARRAY_SIZE , left ,mid, right);

        // Sleep for a short delay
        Sleep(DELAY_MS);
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
            
            // Clear the console
            system("cls");

            // Visualize the array
           // printArray(arr, ARRAY_SIZE);
            printArray_seg(arr, ARRAY_SIZE , low ,high , high );


            // Sleep for a short delay
            Sleep(DELAY_MS);
        }
    }

    int t=arr[i+1];
    arr[i+1] =arr[high];
    arr[high] =t;
	
    // Clear the console
    system("cls");

    // Visualize the array
    //printArray(arr, ARRAY_SIZE);
    printArray_seg(arr, ARRAY_SIZE , low ,high , i+1 );

    // Sleep for a short delay
    Sleep(DELAY_MS);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



void heapify(int arr[], int size, int rootIndex)
{
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    if (leftChild < size && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != rootIndex)
    {
        std::swap(arr[rootIndex], arr[largest]);

        // Clear the console
        system("cls");

        // Visualize the array
        printArray_two_indexes(arr, ARRAY_SIZE , rootIndex , largest);

        // Sleep for a short delay
        Sleep(DELAY_MS);

        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        int temp = arr[i];
		arr[i] =arr[0];
		arr[0] = temp;
		
		//std::swap(arr[0], arr[i]);

        // Clear the console
        system("cls");

        // Visualize the array
        printArray_seg(arr, ARRAY_SIZE , i, size - 1 , 0);

        // Sleep for a short delay
        Sleep(DELAY_MS);

        heapify(arr, i, 0);
    }
}


int main()
{
    // Initialize random seed
    srand(time(0));

    // Create and populate an array with random values
    int arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % MAX_VALUE + 1;
    }

    // Print the unsorted array
    cout << "Unsorted array:" << endl;
    printArray(arr, ARRAY_SIZE);
    
    char choice;
    
    cout<<"\nGoing to sort in ascending order.\nEnter which sorting you want to see:\n";
    cout<<"For Bubble Sort enter :b\n";
     cout<<"For Selection Sort enter :s\n";
      cout<<"For Insertion Sort enter :i\n";
       cout<<"For Merge Sort enter :m\n";
        cout<<"For Quick Sort enter :q\n";
         cout<<"For Heap Sort enter :h\n";
         
    cin>>choice;
    
	switch(choice)
    {
	case 'b':
    {// Sort the array using bubble sort and visualize the process
    bubbleSort(arr, ARRAY_SIZE);
    break;}
    
    case 's':
    {  // Sort the array using selection sort and visualize the process
    selectionSort(arr, ARRAY_SIZE);
     break;}
    
    case 'i':
     { // Sort the array using insertion sort and visualize the process
    insertionSort(arr, ARRAY_SIZE);
     break;}
    
    case 'm':
    {
    // Sort the array using merge sort and visualize the process
    mergeSort(arr, 0, ARRAY_SIZE - 1);
     break;}
    
    case 'q':
    { // Sort the array using quicksort and visualize the process
    quickSort(arr, 0, ARRAY_SIZE - 1);
     break;}
    
    case 'h':
    { // Sort the array using heapsort and visualize the process
    heapSort(arr, ARRAY_SIZE);
     break;}
    
    default: break;
  
	}
    // Clear the console
    system("cls");
    // Print the sorted array
    cout << "Sorted array:" << endl;
    printArray(arr, ARRAY_SIZE);

    return 0;
}

