#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &arr)
{
  int n = arr.size();

  int low = 0;
  int high = n - 1;

  while (low < high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] > arr[high])
    {
      low = mid + 1;
    }
    else
    {
      high = mid;
    }
  }
  return arr[low];
}

int main()
{
  vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

  cout << findMin(arr);

  return 0;
}