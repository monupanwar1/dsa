#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &arr)
{
  int low = 0;
  int high = arr.size() - 1;

  while (low < high)
  {
    int mid = low + (high - low) / 2;

    if (arr[low] == arr[mid] && arr[mid] == arr[high])
    {
      low++;
      high--;
    }

    else if (arr[mid] > arr[high])
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
  vector<int> arr = {2, 2, 2, 0, 1, 2};

  cout << findMin(arr);

  return 0;
}