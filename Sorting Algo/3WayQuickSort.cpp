#include <iostream>

/* redundant members considered in the array */

void swap(int* a, int* b);
void quickSort(int arr[], int low, int high);
void partition (int arr[], int left, int right, int& i, int& j);
void printArray(int arr[], int size);

// Driver program to test above functions
int main(){
    //int arr[] = {10, 7, 8, 9, 3, 1, 5};
    //int arr[] = {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4};
    int arr[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
    //int arr[] = {4, 39, 54, 14, 31, 89, 44, 34, 59, 64, 64, 11, 41};
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //int arr[] = {91, 82, 73, 64, 55, 46, 37, 28, 19, 10};
    //int arr[] = {4, 9, 4, 4, 9, 1, 1, 1};
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
        int i = low - 1;
        int j = high;
        partition(arr, low, high, i, j);
        // Separately sort elements before / partition and after partition
        //printArray(arr, pi);
        quickSort(arr, low, i);
        quickSort(arr, j, high);
    }
}

/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
void partition (int arr[], int left, int right, int& i, int& j){
   int pivot = arr[right];

   for(;left < j; left++){
     if(arr[left] < pivot){
       i++;
       swap(&arr[i],&arr[left]);
     }else if(arr[left] == pivot){
       j--;
       swap(&arr[j],&arr[left]);
       left--;
     }
   }
   int temp = j;
   left = i+1;
   for(;temp <= right; temp++,left++){
     swap(&arr[temp],&arr[left]);
   }
   j = left;
}

/* Function to print an array */
void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
