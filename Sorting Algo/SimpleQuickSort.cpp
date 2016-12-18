#include <iostream>

/* no redundant members in the array */

void swap(int* a, int* b);
void quickSort(int arr[], int low, int high);
int partition (int arr[], int low, int high);
void printArray(int arr[], int size);

// Driver program to test above functions
int main(){
    //int arr[] = {10, 7, 8, 9, 3, 1, 5};
    int arr[] = {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

// A utility function to swap two elements
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low   --> Starting index,
   high  --> Ending index.
*/
void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        //printArray(arr, pi);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* This function takes last element as pivot, places  the pivot element
   at its correct position in sorted  array, and places all smaller (smaller
   than pivot) to left of pivot and all greater elements to right  of pivot */
int partition (int arr[], int low, int high){
   // Your code here
   int pivot = arr[high];

   int lessIndex = low - 1;
   int current = low;

   for(;current <= high - 1; ++current){
       if(arr[current] <= pivot){
           lessIndex++;
           swap(&arr[current],&arr[lessIndex]);
       }
   }
   swap(&arr[high],&arr[lessIndex+1]);
   return (lessIndex+1);
}

/* Function to print an array */
void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
