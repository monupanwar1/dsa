#include <vector>
#include <iostream>
using namespace std;

void leftRotateOne(vector<int> &arr)
{
 
  if (arr.empty())
    return;

  int n = arr.size();
  int temp = arr[0];

  for (int i = 1; i < n; i++)
  {
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;
}

int main()
{

  vector<int> arr = {2, 3, 4, 1, 5, 8};
  leftRotateOne(arr);

  for (int it : arr)
  {
    cout << it << endl;
  }
}