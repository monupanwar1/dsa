
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool canWePlace(vector<int> &arr, double dist, int stations)
{
  int countStations = 0;

  int n = arr.size();

  for (int i = 1; i < n; i++)
  {
    double gap = arr[i] - arr[i - 1];

    countStations += ceil(gap / dist) - 1;

    if (countStations >= stations)
    {
      return true;
    }
  }
  return false;
}

double gasStation(vector<int> &arr, int stations)
{
  int n = arr.size();

  sort(arr.begin(), arr.end());

  int max = *max_element(arr.begin(), arr.end());
  int min = *min_element(arr.begin(), arr.end());

  double ans;

  for (double i = 1; i <= (max - min); i += 1)
  {
    if (canWePlace(arr, i, stations))
    {
      ans = i;
      break;
    }
  }

  return ans;
}

double gasStationBS(vector<int> &arr, int stations)
{
  int n = arr.size();

  sort(arr.begin(), arr.end());

  int max = *max_element(arr.begin(), arr.end());
  int min = *min_element(arr.begin(), arr.end());

  double low = 0.0;
  double high = max - min;

  double ans;

  while (low <= high)
  {
    double mid = low + (high - low) / 2.0;

    if (canWePlace(arr, mid, stations))
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
  vector<int> arr = {1, 2, 3, 7};

  int stations = 3;

  double ans = gasStation(arr, stations);
  double ans2 = gasStationBS(arr, stations);

  cout << "Minimum maximum distance = " << ans << endl;
  cout << "Minimum maximum distance = " << ans2 << endl;

  return 0;
}
