#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int noOfSubArr(vector<int> &arr, int k)
{
  int n = arr.size();
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    int sum = 0;

    for (int j = i; j < n; j++)
    {
      sum += arr[j];

      if (sum == k)
      {
        count += 1;
      }
    }
  }

  return count;
};

int noOfSubArr2(vector<int> &arr, int k)
{
  unordered_map<int, int> mp;
  mp[0] = 1;
  int n = arr.size();

  int prefixSum = 0;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    prefixSum += arr[i];

    int required = prefixSum - k;

    if (mp.find(required) != mp.end())
    {
      count += mp[required];
    }

    mp[prefixSum]++;
  }

  return count;
};

int main()
{
  vector<int> arr = {1, 2, 3, 1, 1, 1, 1};

  int k = 3;

  cout << noOfSubArr(arr, k);
  cout << endl;
  cout << noOfSubArr2(arr, k);

  return 0;
}