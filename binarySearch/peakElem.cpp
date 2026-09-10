#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &arr)
{

  int n = arr.size();

  for (int i = 0; i < n; i++)
  {

    if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
    {
      return i;
    }
  }
}

int findPeakElementBS(vector<int> &arr)
{

  int n = arr.size();

  int low = 0;
  int high = n - 1;

  while (low < high)
  {

    int mid = low + (high - low) / 2;

    if (arr[mid] < arr[mid + 1])
    {
      low = mid + 1;
    }
    else
    {
      high = mid;
    }
  }
  return low;
}

int main()
{
  vector<int> arr = {1, 2, 3, 1};

  cout << findPeakElement(arr);
  cout << findPeakElementBS(arr);

  return 0;
}