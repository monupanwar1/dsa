#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int xorSum(vector<int> &arr, int k)
{
  int n = arr.size();
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    int xorSum = 0;

    for (int j = i; j < n; j++)
    {
      xorSum ^= arr[j];

      if (xorSum == k)
      {
        count++;
      }
    }
  }

  return count;
}

int xorSum2(vector<int> &arr, int k)
{
  unordered_map<int, int> mp;
  mp[0] = 1;
  int n = arr.size();

  int prefixXor = 0;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    prefixXor ^= arr[i];

    int required = prefixXor ^ k;

    if (mp.find(required) != mp.end())
    {
      count += mp[required];
    }

    mp[prefixXor]++;
  }

  return count;
};

int main()
{
  vector<int> arr = {1, 2, 3, 1, 1, 1, 1};

  int k = 3;

  cout << xorSum(arr, k);
  cout << endl;
  cout << xorSum2(arr, k);

  return 0;
}