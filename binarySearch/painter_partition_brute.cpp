#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool weCanPaint(vector<int> &arr, int time, int painters)
{
  int countPainters = 1;
  int timePainter = 0;

  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    if (timePainter + arr[i] <= time)
    {
      timePainter += arr[i];
    }
    else
    {
      countPainters += 1;

      timePainter = arr[i];
    }
    if (countPainters > painters)
    {
      return false;
    }
  }
  return true;
};

int painterPartition(vector<int> &arr, int painters)
{
  int n = arr.size();

  // atleast one book
  if (painters > n)
  {
    return -1;
  }

  int low = *max_element(arr.begin(), arr.end());
  int high = 0;

  for (int time : arr)
  {
    high += time;
  }
  // max sum
  int ans = high;

  for (int time = low; time <= high; time++)
  {
    if (weCanPaint(arr, time, painters))
    {
      ans = time;
      break;
    }
  }

  return ans;
}

int painterPartitionBS(vector<int> &arr, int painters)
{
  int n = arr.size();

  // atleast one book
  if (painters > n)
  {
    return -1;
  }

  int low = *max_element(arr.begin(), arr.end());
  int high = 0;
  int ans;

  for (int time : arr)
  {
    high += time;
  }

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (weCanPaint(arr, mid, painters))
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return ans;
}

int main()
{
  vector<int> arr = {12, 34, 67, 90};
  int painters = 2;
  cout << painterPartition(arr, painters);
  cout << endl;
  cout << painterPartitionBS(arr, painters);
  return 0;
}
