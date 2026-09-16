#include <iostream>
#include <vector>
using namespace std;

void generate(int idx, vector<int> &arr,
              vector<int> &list,
              vector<vector<int>> &ans)
{

  // Base case
  if (idx == arr.size())
  {
    ans.push_back(list);
    return;
  }

  // Take
  list.push_back(arr[idx]);
  generate(idx + 1, arr, list, ans);

  // Undo
  list.pop_back();  

  // Not take
  generate(idx + 1, arr, list, ans);
}

int main()
{

  vector<int> arr = {1, 2, 3};

  vector<int> list;
  vector<vector<int>> ans;

  generate(0, arr, list, ans);

  for (auto &subset : ans)
  {
    cout << "[ ";
    for (int x : subset)
    {
      cout << x << " ";
    }
    cout << "]\n";
  }

  return 0;
}