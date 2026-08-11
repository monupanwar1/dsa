#include <iostream>
#include <vector>
using namespace std;

void leftRotate(vector<int> &arr, int n, int d)
{
  d = d % n;
  int temp[d];

  // store in temp
  for (int i = 0; i < d; i++)
  {
    temp[i] = arr[i];
  }

  // shifting
  for (int i = d; i < n; i++)
  {
    arr[i - d] = arr[i];
  }
  // restoring
  for (int i = n - d; i < n; i++)
  {
    arr[i] = temp[i - (n - d)];
  }
}

int main()
{
  vector<int> arr = {2, 4, 9, 1, 3};
  int n = arr.size();

  int d = 2;

  leftRotate(arr, n, d);
  for (auto it : arr)
  {
    cout << it << " ";
  }
}