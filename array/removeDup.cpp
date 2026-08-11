#include <iostream>
#include <vector>
#include <set>
using namespace std;

void removeDup(vector<int> &arr, int n)
{

  set<int> s;

  for (auto it : arr)
  {
    s.insert(it);
  };

  arr.clear();

  for (auto it : s)
  {
    arr.push_back(it);
  };
}

int main()
{
  vector<int> arr = {2, 0, 4, 0, 4, 8};
  int n = arr.size();

  removeDup(arr, n);

  for (int it : arr)
  {
    cout << it << endl;
  }
}