// single.cpp

#include <iostream>
#include <vector>
using namespace std;

int findSingle(vector<int> &arr)
{
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    if (i == 0 && arr[i] != arr[i + 1])
    {

      return arr[i];
    }
    if (i == n - 1 && arr[i] != arr[i - 1])
    {

      return arr[i];
    }

    if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
    {
      return arr[i];
    }
  }
  return -1;
}
int main()
{
  vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5, 5};

  cout << findSingle(arr);

  return 0;
}