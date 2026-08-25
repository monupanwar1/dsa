#include <iostream>
#include <vector>
using namespace std;

int countInv(vector<int> &arr)
{
  int n = arr.size();
  int count = 0;

  for (int i = 0; i < n; i++)
  {

    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] > arr[j])
      {
        count++;
      }
    }
  }
  return count;
}
int main()
{
  vector<int> arr = {5, 3, 2, 4, 1};
  cout << countInv(arr);
}