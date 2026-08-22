#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int> &arr)
{
  int n = arr.size();

  vector<int> list;

  for (int i = 0; i < n; i++)
  {
    int count = 0;

    if (list.size() != 2)
    {
      for (int j = 0; j < n; j++)
      {
        if (arr[i] == arr[j])
        {
          count++;
        }
      }
      if (count > n / 3)
      {
        list.push_back(arr[i]);
      }
    }
    if (list.size() == 2)
      break;
  }
  return list;
};

int main()
{
  vector<int> arr = {1, 2, 1, 1, 3, 2, 2, 2};

  vector<int> ans = majorityElement(arr);

  for (auto it : ans)
  {
    cout << it << " ";
  }

  cout << endl;
}