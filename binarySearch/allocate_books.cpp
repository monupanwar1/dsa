#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool weCanAllocate(vector<int> &arr, int pages, int students)
{
  int countStudents = 1;
  int countPages = 0;

  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    if (countPages + arr[i] <= pages)
    {
      countPages += arr[i];
    }
    else
    {
      countStudents += 1;

      countPages = arr[i];
    }
    if (countStudents > students)
    {
      return false;
    }
  }
  return true;
};

int allocateBooks(vector<int> &arr, int students)
{
  int n = arr.size();

  // atleast one book
  if (students > n)
  {
    return -1;
  }

  int low = *max_element(arr.begin(), arr.end());
  int high = 0;

  for (int pages : arr)
  {
    high += pages;
  }
  // max sum
  int ans = high;

  for (int pages = low; pages <= high; pages++)
  {
    if (weCanAllocate(arr, pages, students))
    {
      ans = pages;
      break;
    }
  }

  return ans;
}

int allocateBooksBS(vector<int> &arr, int students)
{
  int n = arr.size();

  // atleast one book
  if (students > n)
  {
    return -1;
  }

  int low = *max_element(arr.begin(), arr.end());
  int high = 0;
  int ans;

  for (int pages : arr)
  {
    high += pages;
  }

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (weCanAllocate(arr, mid, students))
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return ans;
}

int main()
{
  vector<int> arr = {12, 34, 67, 90};
  int students = 2;
  cout << allocateBooks(arr, students);
  cout << endl;
  cout << allocateBooksBS(arr, students);
  return 0;
}
