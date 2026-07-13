#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{

  for (int i = 0; i < n - 1; i++)
  {

    if (arr[i] > arr[i + 1])
    {
      return false;
    }
    }
  return true;
}
int main()
{
  int arr[] = {4};
  int n = sizeof(arr) / sizeof(arr[0]);
  if (isSorted(arr, n))
  {
    cout << "sorted";
  }
  else
  {
    cout << "not sorted";
  }
  return 0;
}
