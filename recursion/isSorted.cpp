#include <iostream>
using namespace std;
int checkSorted(int i, int n, int arr[])
{
  if (i >= n)
    return true;

  if (arr[i] < arr[i - 1])
    return false;

  checkSorted(i + 1, n, arr);
};
int main()
{
  int arr[] = {1, 2, 3, 1};
  int i = 1;
  int n = sizeof(arr) / sizeof(arr[0]);
  if (checkSorted(i, n, arr))
  {
    cout << "sorted";
  }
  else
  {
    cout << "not sorted";
  }
}