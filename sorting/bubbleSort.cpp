#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n)
{
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j <i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int arr[] = {2, 9, 8, 1, 4, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}