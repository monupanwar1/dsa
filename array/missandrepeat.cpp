#include <iostream>
#include <vector>
using namespace std;

vector<int> missAndRepeat(vector<int> &arr)
{
  int n = arr.size();

  int repeat = -1;
  int missing = -1;

  for (int i = 1; i <= n; i++)
  {
    int count = 0;

    for (int j = 0; j < n; j++)
    {
      if (arr[j] == i)
      {
        count++;
      }
    }

    if (count == 2)
      repeat = i;

    if (count == 0)
      missing = i;

    // Break when both are found
    if (repeat != -1 && missing != -1)
      break;
  }

  return {missing, repeat};
}
int main()
{
  vector<int> arr = {1, 1, 3, 4, 5};
  vector<int> ans = missAndRepeat(arr);
  for (auto it : ans)
  {
    cout << it << endl;
  }
}