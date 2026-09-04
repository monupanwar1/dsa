#include <iostream>
#include <vector>
using namespace std;

vector<int> getFloorCeil(vector<int> &arr, int x)
{
  vector<int> ans;

  int floor = -1;
  int ceil = -1;

  int n = arr.size();

  int low = 0;
  int high = n - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
    {
      floor = arr[mid];
      ceil = arr[mid];
      break;
    }

    if (arr[mid] < x)
    {
      floor = arr[mid];
      low = mid + 1;
    }
    else
    {
      ceil = arr[mid];
      high = mid - 1;
    }

  }
  
  return {floor, ceil};
}

int main()
{
  vector<int> arr = {1, 3, 5, 7, 9};
  int x = 6;

  vector<int> ans = getFloorCeil(arr, x);

  cout << ans[0] << " " << ans[1];

  return 0;
}