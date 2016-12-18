#include <iostream>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void swap(int* a, int* b);
void printArray(int A[], int size);

void merge(int arr[], int l, int m, int r){
  int n1 = m - l + 1;
  int n2 =  r - m;
  int left[n1], right[n2];
  for(int i = 0; i < n1; i++) left[i] = arr[l+i];
  for(int i = 0; i < n2; i++) right[i] = arr[m+i+1];
  int i = 0;
  int j = 0;
  while(i < n1 && j < n2 ){
    if(left[i] <= right[j]){
      arr[l+i+j] = left[i];
      i++;
    }else{
      arr[l+i+j] = right[j];
      j++;
    }
  }
  while(i < n1){
    arr[l+i+j] = left[i];
    i++;
  }
  while(j < n2){
    arr[l+i+j] = right[j];
    j++;
  }
}

// A utility function to swap two elements
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
