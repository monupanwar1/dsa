#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possible(vector<int> &bloomDay, int day, int m, int k)
{
  int bouquets = 0;
  int flowers = 0;

  for (int bloom : bloomDay)
  {

    if (bloom <= day)
    {
      flowers += 1;

      if (flowers == k)
      {
        bouquets += 1;
        flowers = 0;
      }
    }
    else
    {
      flowers = 0;
    }
  }
  return bouquets >= m;
}

bool possible1(vector<int> &bloomDay, int day, int m, int k)
{
  int bouquets = 0;
  int flowers = 0;

  int n = bloomDay.size();

  for (int i = 0; i < n; i++)
  {

    if (bloomDay[i] <= day)
    {
      flowers += 1;

      if (flowers == k)
      {
        bouquets += 1;
        flowers = 0;
      }
    }
    else
    {
      flowers = 0;
    }
  }
  return bouquets >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{

  if ((long long)m * k > bloomDay.size())
  {
    return -1;
  }
  int low = *min_element(bloomDay.begin(), bloomDay.end());
  int high = *max_element(bloomDay.begin(), bloomDay.end());

  for (int day = low; day <= high; day++)
  {
    if (possible(bloomDay, day, m, k))
    {
      return day;
    }
  }
  return -1;
}

int minDaysBS(vector<int> &bloomDay, int m, int k)
{

  int ans = -1;

  int low = *min_element(bloomDay.begin(), bloomDay.end());
  int high = *max_element(bloomDay.begin(), bloomDay.end());

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (possible(bloomDay, mid, m, k))
    {
      ans = mid;
      high = mid - 1; // try smaller day
    }
    else
    {
      low = mid + 1; // need more days
    }
  }
  return ans;
}

int main()
{
  vector<int> bloomDay = {1, 2, 3, 4, 5, 6};

  int m = 3;
  int k = 2;

  cout << minDays(bloomDay, m, k) << endl;
  cout << minDaysBS(bloomDay, m, k) << endl;

  return 0;
}