
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> temp;
    temp.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
      if (intervals[i][0] <= temp.back()[1])
      {
        temp.back()[1] = max(temp.back()[1], intervals[i][1]);
      }
      else
      {
        temp.push_back(intervals[i]);
      }
    }

    return temp;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> intervals = {
      {1, 3},
      {2, 6},
      {8, 10},
      {15, 18}};

  vector<vector<int>> result = sol.merge(intervals);

  cout << "Merged Intervals: ";
  for (auto interval : result)
  {
    cout << "[" << interval[0] << ", "
         << interval[1] << "] ";
  }

  cout << endl;
  return 0;
}
