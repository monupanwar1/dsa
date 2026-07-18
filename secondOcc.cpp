#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int secondHighestOccurrence(vector<int> &arr)
{
  int n = arr.size();

  int maxFreq = 0;
  int secondFreq = 0;
  int maxEle = -1;
  int ans = -1;

  // check vis or not
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
      continue;

    int count = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[i] == arr[j])
        count++;
    }
    if (count > maxFreq)
    {
      secondFreq = maxFreq;
      ans = maxEle;
      maxFreq = count;
      maxEle = arr[i];
    }
    else if (count > secondFreq && count < maxFreq)
    {
      secondFreq = count;
      ans = arr[i];
    }
  }
  return ans;
}
int secondHighestOccurrence1(vector<int> &arr)
{

  // find max
  int maxi = arr[0];
  for (int x : arr)
  {
    if (x > maxi)
    {
      maxi = x;
    }
  }
  // prestore
  vector<int> freq(maxi + 1, 0);

  for (int x : arr)
    freq[x]++;

  int maxFreq = 0;
  int secondFreq = 0;

  int maxEle = -1;
  int ans = -1;

  // Traverse frequency array
  for (int i = 0; i <= maxi; i++)
  {
    if (freq[i] > maxFreq)
    {
      secondFreq = maxFreq;
      ans = maxEle;
      maxFreq = freq[i];
      maxEle = i;
    }
    else if (freq[i] > secondFreq && freq[i] < maxFreq)
    {
      secondFreq = freq[i];
      ans = i;
    }
  }
  return ans;
}

int secondHighestOccurrence2(vector<int> &arr)
{

  unordered_map<int, int> freq;

  for (int x : arr)
  {
    freq[x]++;
  }

  int maxFreq = 0;
  int secondFreq = 0;
  int maxEle = -1;
  int ans = -1;

  for (int x : arr)
  {
    if (freq[x] == -1)
    {
      continue;
    }
    int count = freq[x];

    if (count > maxFreq)
    {
      secondFreq = maxFreq;
      ans = maxEle;

      maxFreq = count;
      maxEle = x;
    }
    else if (count > secondFreq && count < maxFreq)
    {
      secondFreq = count;
      ans = x;
    }
    freq[x] = -1;
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4};
  cout << secondHighestOccurrence(arr);
  cout << secondHighestOccurrence1(arr);
  cout << secondHighestOccurrence2(arr);
}