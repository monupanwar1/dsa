#include <iostream>
using namespace std;

int sumOfarr(int i, int arr[], int n)
{

  if (i >= n)
  {
    return 0;
  }

  return arr[i] + sumOfarr(i + 1, arr, n);
}

int main()
{
  int i = 0;
  int arr[] = {2, 3, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << sumOfarr(i, arr, n);
  return 0;
}