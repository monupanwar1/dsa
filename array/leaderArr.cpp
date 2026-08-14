#include <iostream>
#include <vector>
using namespace std;

vector<int> leaderArr(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans;

  for (int i = 0; i < n; i++)
  {
    bool leader = true;
    for (int j = i + 1; j < n; j++)
    {

      if (arr[j] > arr[i])
      {
        leader = false;
        break;
      }
    }
    if (leader == true)
      ans.push_back(arr[i]);
  }
  return ans;
}

int main()
{
  vector<int> arr = {10, 9, 8, 7, 6};
  vector<int> ans = leaderArr(arr);

  for (auto it : ans)
  {
    cout << it << " ";
  }
}