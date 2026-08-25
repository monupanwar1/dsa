#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2)
{
  int n = arr1.size();
  int m = arr2.size();

  vector<int> ans;

  int i = 0;
  int j = 0;

  while (i < n && j < m)
  {

    if (arr1[i] <= arr2[j])
    {
      ans.push_back(arr1[i]);
      i++;
    }
    else
    {
      ans.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n)
  {
    ans.push_back(arr1[i]);
    i++;
  }

  // Remaining elements of arr2
  while (j < m)
  {
    ans.push_back(arr2[j]);
    j++;
  }
  // Put first n elements back into arr1
  for (int i = 0; i < n; i++)
  {
    arr1[i] = ans[i];
  }

  // Put remaining elements into arr2
  for (int i = 0; i < m; i++)
  {
    arr2[i] = ans[n + i];
  }
}
int main()
{
  vector<int> arr1 = {1, 4, 7, 8};
  vector<int> arr2 = {2, 3, 6, 9};

  merge(arr1, arr2);

  for (int x : arr1)
    cout << x << " ";

  cout << endl;

  for (int x : arr2)
    cout << x << " ";
}