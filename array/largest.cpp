#include <iostream>
#include <vector>
using namespace std;

int largestElem(vector<int> &arr)
{
  int largest = 0;
  int ans = 0;
  int n = arr.size();

  for (int i = 0; i <= n - 1; i++)
  {
    if (arr[i] > largest)
    {
      ans = arr[i];
    }
  }
  return ans;
}
int smallestElem(vector<int> &arr)
{
  int smallest = 0;
  int ans = 0;
  int n = arr.size();

  for (int i = 0; i <= n - 1; i++)
  {
    if (arr[i] < smallest)
    {
      ans = arr[i];
    }
  }
  return ans;
}

int main()
{

  vector<int> arr = {2, 9, -1, 6, 20};
  cout << largestElem(arr) << endl;
  cout << smallestElem(arr);
}