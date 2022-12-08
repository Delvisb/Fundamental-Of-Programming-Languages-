/*
Write a C program that does a large number of references to elements of two-dimensional arrays, using only subscribing. 
For example, you may do matrix multiplication or addition.  You can repeat the operation multiple times. Write a second 
program that does the same operations but uses pointers and pointer arithmetic for the storage-mapping function to do the 
array references. Compare the readability and time efficiency of the two programs and explain your opinion. 
*/

/*
Delvis Burgos
CSIT 313 Section 1 Lab 3
*/
#include <stdio.h>
#include <time.h>

int main(void){
  //Declaring and initializing the array for both methods
  int array[3][3];
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      array[i][j] = i+j;
      }
  }

  clock_t t;
  t = clock(); //Starting timer for subscribing method
  //displaying using subscribing
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("%4d", array[i][j]);
    } 
    printf("\n");
  }
  t = clock() - t;
  double time_taken1 = ((double)t)/CLOCKS_PER_SEC; 
  printf("The array addition took %f seconds to execute by subscribing \n", time_taken1);

  
  
  
  clock_t t2;
  t2 = clock(); //Starting timer for pointer method
  //displaying using pointers
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("%4d", *(*(array + i) + j));
    }
    printf("\n");
  }
  t2 = clock() - t2;
  double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; 
  printf("The array addition took %f seconds to execute by using pointers \n", time_taken2); 

  
  return 0;
}
