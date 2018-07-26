#include <iostream>
 
void printArray(int *array, int n);
void merger(int arr[], int lo, int  mi, int hi);
void mergeSortHelper(int arr[], int lo, int hi);
void mergeSort(int arr[], int arr_size);
 
int main()
{
  int array[] = {94, 42, 50, 95, 333, 65, 54, 456, 1, 1234};
  int n = sizeof(array)/sizeof(array[0]);
  std::cout << "Before merge Sort :" << std::endl;
  printArray(array, n);
  mergeSort(array, n);
  std::cout << "After merge Sort :" << std::endl;
  printArray(array, n);
  return (0);
}
 
 
void printArray(int *array, int n)
{
  for (int i = 0; i < n; ++i)
    std::cout << array[i] << " " << std::flush;
  std::cout << std::endl;
}
 
void merger(int arr[], int lo, int  mi, int hi)
{
    int *temp = new int[hi-lo+1];//temporary merger array
    int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
    int k = 0;//k is for the temporary array
    while(i <= mi && j <=hi){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    //rest elements of left-half
    while(i <= mi)
        temp[k++] = arr[i++];
    //rest elements of right-half
    while(j <= hi)
        temp[k++] = arr[j++];
    //copy the mergered temporary array to the original array
    for(k = 0, i = lo; i <= hi; ++i, ++k)
        arr[i] = temp[k];
 
    delete []temp;
}
 
void mergeSortHelper(int arr[], int lo, int hi)
{
    int mid;
    if(lo < hi)
    {
        mid = (lo + hi) >> 1;
        mergeSortHelper(arr, lo, mid);
        mergeSortHelper(arr, mid+1, hi);
        merger(arr, lo, mid, hi);
    }
}
 
void mergeSort(int arr[], int arr_size)
{
    mergeSortHelper(arr, 0, arr_size-1);
}