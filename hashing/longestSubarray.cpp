#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSub(vector<int> &arr, int k)
{
  int n = arr.size();
  int maxLen = 0;

  for (int i = 0; i < n; i++)
  {
    int sum = 0;

    for (int j = i; j < n; j++)
    {
      sum += arr[j];

      if (sum == k)
      {
        maxLen = max(maxLen, j - i + 1);
      }
    }
  }

  return maxLen;
};

int longestSub2(vector<int> &arr, int k)
{
  unordered_map<int, int> mp;
  mp[0] = -1;
  int n = arr.size();
  int prefixSum = 0;
  int maxLength = 0;

  for (int i = 0; i < n; i++)
  {
    prefixSum += arr[i];

    if (prefixSum == k)
    {
      maxLength = i + 1;
    }

    if (mp.find(prefixSum - k) != mp.end())
    {
      maxLength = max(maxLength, i - mp[prefixSum - k]);
    }

    if (mp.find(prefixSum) == mp.end())
    {
      mp[prefixSum] = i;
    }
  }

  return maxLength;
};

int main()
{
  vector<int> arr = {1, 2, 3, 1, 1, 1, 1};

  int k = 3;

  cout << longestSub(arr, k);
  cout << endl;
  cout << longestSub2(arr, k);

  return 0;
}