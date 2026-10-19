#include <bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int> &arr, vector<int> &dep)
{
  int n = arr.size();
  int maxPlatforms = 1;

  sort(arr.begin(), arr.end());
  sort(dep.begin(), dep.end());

  int s = 0;

  for (int i = 0; i < n; i++)
  {
    int platform = 1;

    for (int j = 0; j < n; j++)
    {
      if (i != j && arr[i] <= dep[j] && arr[j] <= dep[i])
      {
        platform++;
      }
    }
    maxPlatforms = max(maxPlatforms, platform);
  }
  return maxPlatforms;
}

int main()
{
  vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
  vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

  cout << minPlatforms(arr, dep) << endl;
  return 0;
}