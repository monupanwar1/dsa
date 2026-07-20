#include <iostream>
#include <vector>
using namespace std;

bool isPalidrom(vector<char> &arr)
{
  int left = 0;
  int right = arr.size() - 1;
  while (left < right)
  {
    if (arr[left] != arr[right])
    {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

int main()
{
  vector<char> arr = {'l', 'e', 'v', 'e', 'o'};

  if (isPalidrom(arr))
  {
    cout << "isPalidrom";
  }
  else
  {
    cout << "not a palidrom";
  }
}