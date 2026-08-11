#include <iostream>
#include <vector>
using namespace std;

void moveZero(vector<int> &arr, int n)
{
  vector<int> temp;

  // store temp
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      temp.push_back(arr[i]);
    }
  }
  
  int n2 = temp.size();
  // add back
  for (int i = 0; i < n2; i++)
  {
    arr[i] = temp[i];
  }

  // fill remaning
  for (int i = n2; i < n; i++)
  {
    arr[i] = 0;
  }
}

int main()
{
  vector<int> arr = {2, 0, 4, 0, 5, 8};
  int n = arr.size();
  moveZero(arr, n);

  for (int it : arr)
  {
    cout << it << endl;
  }
}