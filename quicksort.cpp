#include<iostream>
using namespace std;
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
int partition (int array[], int low, int high) 
{ 
    int pivot = array[high];    
    int swapIndex  = (low - 1);   //swapping index.
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (array[j] < pivot) 
        { 
            swapIndex ++; 
            swap(&array[swapIndex], &array[j]); 
        } 
    } 
    swap(&array[swapIndex + 1], &array[high]); 
    return (swapIndex + 1); 
} 
void quickSort(int array[], int low, int high) 
{ 
    if (low < high) 
    { 
        int indexPI  = partition(array, low, high); 
        quickSort(array, low, indexPI  - 1);  
        quickSort(array, indexPI  + 1, high); 
    } 
} 
void display(int array[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<< array[i] <<" "; 
} 
  
int main() 
{ 
    int array[] = {7, 9, 1, 3, 5, 2, 6, 0, 4, 8}; 
    int size = sizeof(array)/sizeof(array[0]);
    
    cout<<"the before Sorting: \n";
    display(array, size);
    
    quickSort(array, 0, size-1); 
    
    cout<<"\n the After Sorting: \n"; 
    display(array, size); 
    
    return 0; 
}
