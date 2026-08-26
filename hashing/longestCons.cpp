#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool linearSearch(vector<int> &ans, int x)
{
  for (auto it : ans)
  {
    if (it == x)
      return true;
  }
  return false;
};

int longestConsecutive(vector<int> &arr)
{
  int n = arr.size();
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    int current = arr[i];
    int count = 1;

    while (linearSearch(arr, current + 1))
    {
      current++;
      count++;
    }

    ans = max(ans, count);
  }

  return ans;
}

int longestConsecutive2(vector<int> &arr)
{
  int n = arr.size();
  int ans = 0;

  unordered_set<int> st;

  for (auto it : arr)
  {
    st.insert(it);
  }

  for (int i = 0; i < n; i++)
  {
    int current = arr[i];
    int count = 1;

    if (st.find(current - 1) == st.end())
    {
      while (st.find(current + 1) != st.end())
      {
        current++;
        count++;
      }
    }

    ans = max(ans, count);
  }

  return ans;
}

int main()
{
  vector<int> arr = {100, 4, 200, 1, 3, 2};
  cout << longestConsecutive(arr);
  cout << longestConsecutive2(arr);
}