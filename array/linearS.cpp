#include <iostream>
using namespace std;

int linearSearch(int n, int arr[], int target)
{
  for (int i = 0; i <= n - 1; i++)
  {
    if (target == arr[i])
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {2, 5, 9, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  int target = 9;

  cout << linearSearch(n, arr, target);
}