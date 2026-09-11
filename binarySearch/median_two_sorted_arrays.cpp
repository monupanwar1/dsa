#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedian(vector<int> &a, vector<int> &b)
{
  vector<int> ans;

  int i = 0;
  int j = 0;

  while (i < a.size() && j < b.size())
  {
    if (a[i] <= b[j])
    {
      ans.push_back(a[i]);
      i++;
    }
    else
    {
      ans.push_back(b[j]);
      j++;
    }
  }

  while (i < a.size())
  {
    ans.push_back(a[i]);
    i++;
  }

  while (j < b.size())
  {
    ans.push_back(b[j]);
    j++;
  }

  int n = ans.size();

  if (n % 2 == 1)
  {
    return ans[n / 2];
  }

  return (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
}

double findMedianBS(vector<int> &a, vector<int> &b)
{
  // Always binary search on the smaller array
  if (a.size() > b.size())
  {
    swap(a, b);
  }

  int n = a.size();
  int m = b.size();

  int low = 0;
  int high = n;

  int totalLeft = (n + m + 1) / 2;

  while (low <= high)
  {
    int cutA = low + (high - low) / 2;
    int cutB = totalLeft - cutA;

    int leftA = (cutA == 0) ? INT_MIN : a[cutA - 1];
    int rightA = (cutA == n) ? INT_MAX : a[cutA];

    int leftB = (cutB == 0) ? INT_MIN : b[cutB - 1];
    int rightB = (cutB == m) ? INT_MAX : b[cutB];

    // Cut A is too far right
    if (leftA > rightB)
    {
      high = cutA - 1;
    }

    // Cut A is too far left
    else if (leftB > rightA)
    {
      low = cutA + 1;
    }

    // Correct partition
    else
    {
      // Odd
      if ((n + m) % 2 == 1)
      {
        return max(leftA, leftB);
      }

      // Even
      int leftMax = max(leftA, leftB);
      int rightMin = min(rightA, rightB);

      return (leftMax + rightMin) / 2.0;
    }
  }

  return 0.0;
}

int main()
{
  vector<int> a = {1, 3};
  vector<int> b = {2, 4};

  double ans = findMedian(a, b);
  double ans2 = findMedianBS(a, b);

  cout << "Linear Median = " << ans << endl;
  cout << "BS Median = " << ans2 << endl;

  return 0;
}