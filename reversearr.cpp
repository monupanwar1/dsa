#include <iostream>
using namespace std;

void reversearrr(int arr[],int n ){
  int temp[n];

  for(int i =0;i<n;i++){
    temp[n-i-1]=arr[i];
  }
  for(int i =0;i<n;i++){
    arr[i]=temp[i];
  }
}

void reversearr(int arr[], int n)
{
  int left = 0;
  int right = n - 1;
  int temp;
  while (left < right)

  {
    // temp = arr[left];
    // arr[left] = arr[right];
    // arr[right] = temp;

    swap(arr[left],arr[right]);

    left++;
    right--;
  }
 
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  reversearrr(arr, n);

  for(int i =0;i<n;i++){
    cout << arr[i] << " ";
  }
  return 0;
}