/* Write three functions in C or C++: one that declares a large integer array statically (static array), one that declares the same large array on the 
stack ( local array variable), and one that creates the same large array from the heap (malloc). You may randomly fill in the values of these array 
elements. You may also try different array sizes, such as 1000, 5000 etc. Call each of the subprograms a large number of times ( at least 100,000) 
and output the time required by each function. Explain the results from the perspectives of array memory allocation and deallocation. 
*/

#include <iostream>
#include <time.h>

using namespace std; 

int main() { 
  clock_t t;
  t = clock();
  
  void fun1();
  t = clock() - t;
  double time_taken1 = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("fun1() for static array took %f seconds to execute \n", time_taken1);
  
  void fun2();
  t = clock() - t;
  double time_taken2 = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("fun2() for local array took %f seconds to execute \n", time_taken2);

  
  void fun3();
  t = clock() - t;
  double time_taken3 = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("fun3() for the heap array took %f seconds to execute \n", time_taken3);
  return 0;
}

//declaring a large integer array statically (static array)
void staticArray(){
  int static a[5000];
}

//declaring the same large array on the stack (local array variable)
void stackArray(){
  int a[5000];
}

//creating the same large array from the heap (malloc)
void heapArray(){
  int *p = (int *) malloc (5000*sizeof(int));
}

//Calling each of the subprograms a large number of times(at least 100,000)
void fun1(){
  int i = 100000;
  while(i!= 0){ //while i doesn't equal 0, decrement i 
    i--;
    stackArray();
  } 
}
void fun2(){
  int i = 100000;
  while(i!= 0){ //while i doesn't equal 0, decrement i 
    i--;

    stackArray();
  } 
}
void fun3(){
  int i = 100000;
  while(i!= 0){ //while i doesn't equal 0, decrement i 
    i--;
    heapArray(); 
  } 
}

/* Explanation for results from the perspective of memory allocation and deallocation: The stactic array memory allocation, or fun1(), is faster than 
stack & heap array memory allocation as the results show. This is because of their data structures, and how the data is accessed. Static allows 
preallocation before execution, whereas dynamic must first search for free storage to accomplish the allocation. Stack is faster than heap because the 
variables are stored directly to the memory. On the other hand, heap's allocation is performed when during runtime therefore it must then search this 
memory causing it to be slower. */
