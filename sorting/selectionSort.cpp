#include <iostream>
#include <algorithm>
using namespace std;

int selectionSort(int arr[], int n)
{

  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i; j <= n - 1; j++)
    {
      int mini = i;
      {
        if (arr[j] < arr[mini])
        {
          mini = j;
        }
      }
      int temp = arr[mini];
      arr[mini] = arr[i];
      arr[i] = temp;
    }
  }
}

int main()
{
  int arr[] = {2, 9, 8, 1, 4, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}