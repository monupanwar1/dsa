#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sumofocc(vector<int> &arr)
{
  int n = arr.size();
  int maxFreq = 0;
  int minFreq = INT8_MAX;
  int minElem = 0;
  int maxElem = 0;

  for (int i = 0; i < n; i++)
  {
    bool vis = false;
    for (int j = 0; j < i; j++)
    {
      if (arr[i] == arr[j])
      {
        vis = true;
        break;
      }
    }

    if (vis)
    {
      continue;
    }

    int count = 0;

    for (int j = 0; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        count++;
      }
    }
    if (count > maxFreq)
    {
      maxFreq = count;
      maxElem = arr[i];
    }
    if (count < minFreq)
    {
      minFreq = count;
      minElem = arr[i];
    }
  }
  return maxElem + minElem;
}
int sumofocc1(vector<int> &arr)
{
  int n = arr.size();

  int maxi = arr[0];

  // find max

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > maxi)
    {
      maxi = arr[i];
    }
  }

  // freq
  vector<int> freq(maxi + 1, 0);

  // store freq
  for (int i = 0; i < n; i++)
  {
    freq[arr[i]]++;
  }

  // find elem
  int maxFreq = 0;
  int minFreq = INT8_MAX;
  int maxElem = 0;
  int minElem = 0;

  for (int i = 0; i <= maxi; i++)
  {
    if (freq[i] == 0)
      continue;

    if (freq[i] > maxFreq)
    {
      maxFreq = freq[i];
      maxElem = i;
    }
    if (freq[i] < minFreq)
    {
      minFreq = freq[i];
      minElem = i;
    }
  }
  return maxElem + minElem;
}
int sumofocc2(vector<int> &arr)
{
  unordered_map<int, int> mp;
  // store freq
  for (int x : arr)
  {
    mp[x]++;
  }

  int maxFreq = 0;
  int minFreq = INT8_MAX;

  int maxElem = 0;
  int minElem = 0;

  for (int x : arr)
  {
    if (mp[x] == -1)
      continue;

    int count = mp[x];

    if (count > maxFreq)
    {
      maxFreq = count;
      maxElem = x;
    }
    if (count < minFreq)
    {
      minFreq = mp[x];
      minElem = x;
    }
    mp[x] = -1;
  }
  return minElem + maxElem;
}
int main()
{
  vector<int> arr = {2, 3, 3, 3, 4, 5};
  cout << sumofocc(arr) << endl;
  cout << sumofocc1(arr) << endl;
  cout << sumofocc2(arr) << endl;
}