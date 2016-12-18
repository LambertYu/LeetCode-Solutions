#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target);
int findPivot(vector<int>& arr, int low, int high, bool increase);
int binarySearch(vector<int>& arr, int low, int high, int key, bool increase);

int search(vector<int>& nums, int target) {
        int begin = 0;
        if(nums.size() <= 4){
          for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) return i;
          }
          return -1;
        }
        int count = 0;
        bool increase = false;
        for(int i = 0; i < 3; i++){
          if(nums[i] < nums[i+1]) count++;
        }
        if(count >= 2) increase = true;

        int base = nums.size();
        int low = 0;
        int high = base - 1;
        //int mid = (low+high) / 2;
        int pivot = 0;
        pivot = findPivot(nums, low, high, increase);

        int index1 = binarySearch(nums,low, pivot, target, increase);
        int index2 = binarySearch(nums,pivot+1, high, target, increase);


        return (index1 == -1) ? ((index2 == -1) ? -1 : index2) : index1;
}

int findPivot(vector<int>& arr, int low, int high, bool increase) {
  if(low > high) return -1;
  if(low == high) return low;
  int mid = low + (high - low) / 2;
  if(increase){
    if(arr[mid] > arr[low] && arr[mid] > arr[mid+1]){
      return mid;
    }
    if(arr[mid] < arr[low] && arr[mid] < arr[mid-1]){
      return mid - 1;
    }
    if(arr[mid] >= arr[low]){
      return findPivot(arr, mid+1, high, increase);
    }
    return findPivot(arr, low, mid-1, increase);
  }else{
    if(arr[mid] < arr[low] && arr[mid] < arr[mid+1]){
      return mid;
    }
    if(arr[mid] > arr[low] && arr[mid] > arr[mid-1]){
      return mid - 1;
    }
    if(arr[mid] >= arr[low]){
      return findPivot(arr, low, mid-1, increase);
    }
    return findPivot(arr, mid+1, high, increase);
  }
}

int binarySearch(vector<int>& arr, int low, int high, int key, bool increase){
   if (high < low)
       return -1;
   int mid = low + (high - low)/2;  /*(low + high)/2;*/
   if (key == arr[mid])
       return mid;
   if(increase){
     if (key > arr[mid])
         return binarySearch(arr, (mid + 1), high, key, increase);
     return binarySearch(arr, low, (mid -1), key, increase);
   }else{
     if (key > arr[mid])
         return binarySearch(arr, low, (mid - 1), key, increase);
     return binarySearch(arr, (mid+1), high, key, increase);
   }

}
int main(){
  vector<int> vec,vec2;
  //[4,5,6,7,0,1,2]
  for (size_t i = 0; i < 7; i++) {
    vec.push_back( (i+4)%8 );
    cout << (i+4)%8  << " ";
  }
  cout << endl;
  vec2.push_back(1);
  int target = 2;
  int index = search(vec,target);
  //int index = search(vec2,1);
  cout << index << '\n';
}
