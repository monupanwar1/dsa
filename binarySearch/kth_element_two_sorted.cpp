#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Time : O(n + m)
//  Space : O(n + m)

int kthElement(vector<int> &a, vector<int> &b, int k)
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
    ans.push_back(b[i]);
    j++;
  }

  return ans[k - 1];
};

int kthElementBS(vector<int> &a, vector<int> &b, int k)
{

  if (a.size() > b.size())
  {
    swap(a, b);
  }

  int n = a.size();
  int m = b.size();

  int totalLeft = k;

  int low = max(0, totalLeft - m);
  int high = min(k, n);

  while (low <= high)
  {
    int cutA = low + (high - low) / 2;
    int cutB = totalLeft - cutA;

    int leftA = (cutA == 0) ? INT_MIN : a[cutA - 1];
    int rightA = (cutA == n) ? INT_MAX : a[cutA];

    int leftB = (cutB == 0) ? INT_MIN : a[cutB - 1];
    int rightB = (cutB == n) ? INT_MAX : a[cutB];

    if (leftA <= rightB && leftB <= rightA)
    {
      return max(leftA, leftB);
    }
    if (leftA > rightB)
    {

      high = cutA - 1;
    }
    else
    {
      low = cutA + 1;
    }
  }
  return -1;
};

int main()
{
  vector<int> a = {2, 3, 6, 7, 9};
  vector<int> b = {1, 4, 8, 10};

  int k = 5;

  int ans = kthElement(a, b, k);
  int ans1 = kthElementBS(a, b, k);

  cout << "Kth element = " << ans << endl;
  cout << "Kth elementBS = " << ans << endl;

  return 0;
}