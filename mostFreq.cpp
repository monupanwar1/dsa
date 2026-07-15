#include <iostream>
using namespace std;

int mostFreq(int arr[], int n, int target)
{
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
    {
      count += 1;
    }
  }
  return count;
}
int main()
{
  int arr[] = {
      1, 2,
      4

  };
  int n = sizeof(arr) / sizeof(arr[0]);
  int maxElem = arr[0];

  // brute
  // int ans = arr[0];

  // for (int i = 0; i < n; i++)
  // {

  //   int freq = mostFreq(arr, n, arr[i]);

  //   if (freq > maxFreq)
  //   {
  //     maxFreq = freq;
  //     ans = arr[i];
  //   }
  // }
  // cout << ans;

  // optimize
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > maxElem)
    {
      maxElem = arr[i];
    }
  }

  // hash
  int hash[maxElem + 1] = {0};
  int maxfreq = 0;
  int ans = arr[0];

  for (int i = 0; i < n; i++)
  {
    hash[arr[i]]++;
    if (hash[arr[i]] > maxfreq)
    {
      maxfreq = hash[arr[i]];
      ans = arr[i];
    }
  }

   cout << ans;
}