#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(vector<int> &arr, vector<int> &arr2)
{
  int n = arr.size();
  int n2 = arr2.size();
  vector<int> ans;

  for (int i = 0; i < n; i++)
  {
    int vis = 0;
    for (int j = 0; j < n2; j++)
    {

      if (arr[i] == arr2[j] && vis == 0)
      {
        ans.push_back(arr[i]);
        vis = 1;
        break;
      }
    }
  }
  return ans;
}

int main()
{

  vector<int> arr = {1, 3, 2, 0, 9, 5};
  vector<int> arr2 = {1, 2, 3, 4, 5};
  // int n = arr.size();
  // int n2 = arr.size();
  vector<int> ans = intersection(arr, arr2);
  for (auto it : ans)
  {
    cout << it << " ";
  }
}