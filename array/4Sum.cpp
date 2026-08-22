#include <iostream>
#include <vector>

using namespace std;

vector<int> Sum(vector<int> &arr, int target)
{
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        for (int l = k + 1; l < n; l++)
        {
          if (arr[i] + arr[j] + arr[k] + arr[l] == target)
          {
            return {i, j, k, l};
          }
        }
      }
    }
    return {};
  }
}
bool Sum2(vector<int> &arr, int target)
{
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {

      for (int k = j + 1; k < n; k++)
      {
        for (int l = k + 1; l < n; l++)
        {
          if (arr[i] + arr[j] + arr[k] + arr[l] == target)
          {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main()

{
  vector<int> arr = {4, 7, 1, 9, 3, 6, 2};
  int target = 18;

  vector<int> ans = Sum(arr, target);

  for (auto it : ans)
  {
    cout << it << " ";
  }

  cout << endl;

  cout << Sum2(arr, target);
}