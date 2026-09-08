#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int smallestDivisorBrute(vector<int> &arr, int threshold)
{
  int n = arr.size();

  int maxValue = *max_element(arr.begin(), arr.end());

  for (int divisor = 1; divisor <= maxValue; divisor++)
  {
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
      sum += ceil((double)arr[i] / divisor);
    }

    if (sum <= threshold)
    {
      return divisor;
    }
  }
  return -1;
}

int smallestDivisorBS(vector<int> &arr, int threshold)
{
  int n = arr.size();

  int low = 1;
  int high = *max_element(arr.begin(), arr.end());

  int ans = -1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
      sum += ceil((double)arr[i] / mid);
    }
    if (sum <= threshold)
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
  vector<int> arr = {1, 2, 5, 9};
  int threshold = 6;

  cout << "Brute Force Answer: "
       << smallestDivisorBrute(arr, threshold) << endl;

  cout << "Binary Search Answer: "
       << smallestDivisorBS(arr, threshold) << endl;

  return 0;
}