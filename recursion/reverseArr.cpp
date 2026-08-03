#include <iostream>
using namespace std;

void revArr(int l, int r, int arr[])
{
  if (l >= r)
    return;

  swap(arr[l], arr[r]);
  return revArr(l + 1, r - 1, arr);
}

int main()
{
  int arr[] = {1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int l = 0;
  int r = n - 1;
  revArr(l, r, arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}