#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SecondLarg(vector<int> &arr)
{
  sort(arr.begin(), arr.end());

  int n = arr.size();
  int largest = n;
  int secondLargest = 0;

  for (int i = n - 2; i >= 0; i--)
  {
    if (arr[i] != largest)
    {
      secondLargest = arr[i];
      break;
    }
  }
  return secondLargest;
}

int SecondLarg1(vector<int> &arr)
{

  int n = arr.size();

  int largest = arr[0];
  int secondLargest = 0;

  for (int i = 1; i < n; i++)
  {
    if (arr[i] > largest)
    {
      secondLargest = largest;
      largest = arr[i];
    }
    else if (arr[i] > secondLargest && arr[i] != largest)
    {
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}

int main()
{
  vector<int> arr = {2, 3, 9, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << SecondLarg(arr) << endl;

  cout << SecondLarg1(arr);
}