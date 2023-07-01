#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    
    vector<int> check_valid( vector<vector<int>>&grid_copy , int row , int col )
    {
        
        vector<int> ans;
        vector<int> Heap(10 ,-1);
    
       
        for(int i=0 ; i<9;i++ )
        {   
         
            Heap[ grid_copy[row][i] ] = grid_copy[row][i] ;
           
           
            Heap[grid_copy[i][col] ] = grid_copy[i][col] ;
            
        }
        
       int r=row/3 , c=col/3;
       r*=3 ; c*=3;
       
       for(int i=0 ; i<3 ;i++ )
       { for(int j=0; j<3 ;j++)
       {  
           
           Heap[ grid_copy[ r+i ][c+j] ]= grid_copy[ r+i ][c+j];
           
       }
       } 
       
       for(int i=1 ; i<=9 ; i++)
       {
           if(Heap[i]==-1)
             ans.push_back(i);
       }
       
       return ans;
        
    }
    
    
    bool play_back( vector<vector<int>> &grid , int row , int col , vector<vector<int>>&final_ans)
    {
        
        
        
        if(row==-1 && col==-1)
          {
              final_ans = grid;
              return true;
          }
        
        vector<int> possi= check_valid(grid , row , col);
        
        if(possi.empty())
          return false;
        
       
        pair<int , int> next={-1 ,-1};
        
        for(int j=col+1 ; j<9 ;j++)
          { if(grid[row][j]==0)
              {
                  next={row , j};
                  break;
              }
          }
        
        if(next.first==-1 && next.second==-1) 
        {
        for(int i=row+1 ; i<9 ;i++)
        { int flag=0;
          for(int j=0 ; j<9 ;j++)
            {
               if(grid[i][j]==0) 
               {  flag=1;
                  next={ i , j};
                  break;
               }
            }
          
          if(flag==1)  
              break;
        }
            
        } 
    
        
        
        for(auto value: possi )  
        {  vector<vector<int>> grid_copy = grid;  
            
        grid_copy[row][col]=( value );
            
    bool op =play_back(  grid_copy , next.first , next.second , final_ans);
    
           if(op==true)
            return true;
               
        }
        
        return false;
        
    }
    

    
    bool SolveSudoku(int grid[N][N])  
    { 
       
       vector<vector<int>> final_ans;
       vector<vector<int>> grid_copy;
      
      int i,j;
       for(i=0 ;i<N ;i++) 
       { int flag=1;
           for(j=0 ;j<N ;j++)
           {
               if(grid[i][j]==0)
               {
                   flag=0; break;
               }
           }
           
           if(flag==0)
            break;
       }
       
       
       for(int i=0 ; i<N ;i++)
        { vector<int> rowww; 
        for(int j=0 ; j<N ;j++)
         {
             rowww.push_back(grid[i][j]);
             
         }
            grid_copy.push_back(rowww);
        }
        
        bool a= play_back(  grid_copy , i , j, final_ans);
        
        if(a==false)
          return false;
        else
        { 
            for(int i=0 ; i<N ;i++)
            { 
             for(int j=0 ; j<N ;j++)
             {
             grid[i][j] = final_ans[i][j];
             
               } }
            return true;
        }
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
         for(int i=0 ; i<N ;i++)
        { 
            for(int j=0 ; j<N ;j++)
             {
             cout<<grid[i][j]<<" ";}
             
            cout<<"\n";
            
        }
        
        
    }
};


int main() {
	
	ifstream inputFile("input.txt"); // Open the input file
	    ofstream outputFile("answer.txt"); // Open the output file


    int grid[N][N];

    // Read the Sudoku grid values from the file
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inputFile >> grid[i][j];
        }
    }

    inputFile.close(); // Close the input file
    
   		
	Solution ob;
	
	cout << "Input Grid:" << endl;
    ob.printGrid(grid);
    
    cout<<"\n";

		
		if (ob.SolveSudoku(grid) == true) {
	   
	   cout << "Output Grid:" << endl;	
            ob.printGrid(grid);  
            
        for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            outputFile << grid[i][j] << " ";
        }
        outputFile << endl;
    }
            
            }

        else
            cout << "No solution exists";  
        
    outputFile.close(); // Close the output file

	return 0;
}

