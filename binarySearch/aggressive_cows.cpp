
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canWePlace(vector<int> &arr, int dist, int cows)
{
  int countCows = 1;
  int lastPlace = arr[0];

  int n = arr.size();

  for (int i = 1; i < n; i++)
  {
    if ((arr[i] - lastPlace) >= dist)
    {
      countCows += 1;
      lastPlace = arr[i];
    }
    if (countCows >= cows)
    {
      return true;
    }
    else
    {
    }
  }
  return false;
};

int aggressiveCows(vector<int> &arr, int cows)
{
  int n = arr.size();
  int ans = -1;

  sort(arr.begin(), arr.end());

  int max = *max_element(arr.begin(), arr.end());
  int min = *min_element(arr.begin(), arr.end());

  for (int i = 1; i <= (max - min); i++)
  {
    if (canWePlace(arr, i, cows))
    {
      ans = i;
    }
    else
    {
      break;
    }
  }

  return ans;
}

int aggressiveCowsBS(vector<int> &arr, int cows)
{
  int n = arr.size();

  sort(arr.begin(), arr.end());

  int low = 1;
  int high = arr[n - 1] - arr[0];
  int ans = -1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (canWePlace(arr, mid, cows))
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 2, 4, 8, 9};
  int cows = 3;

  cout << aggressiveCows(arr, cows);
  cout << endl;
  cout << aggressiveCowsBS(arr, cows);

  return 0;
}
