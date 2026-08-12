#include <iostream>
#include <vector>
using namespace std;

int missingNo(vector<int> &arr, int n)
{
  for (int i = 1; i <= n; i++)

  {
    int flag = 0;
    for (int j = 0; j < n - 1; j++)
    {
      if (arr[j] == i)
      {
        flag = 1;
        break;
      }
    }

    if (flag == 0)
      return i;
  }
  return -1;
}

int main()
{

  vector<int> arr = {1, 3, 4};
  int n = arr.size();
  cout << missingNo(arr, n);
}