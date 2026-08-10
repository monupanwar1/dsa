#include <iostream>
#include <vector>
using namespace std;

int maxConsecutive(vector<int> &arr)
{
  int maxi = 0;
  int count = 0;
  int n = arr.size();

  for (int i = 0; i <= n - 1; i++)
  {
    if (arr[i] == 1)
    {
      count += 1;
      maxi = max(maxi, count);
    }
    else
    {
      count = 0;
    }
  }
  return count;
}

int main()
{

  vector<int> arr = {0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1,1};
  cout << maxConsecutive(arr) << endl;
}