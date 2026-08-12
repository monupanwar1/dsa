#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> unionNo(vector<int> &arr, vector<int> &arr2)
{
  set<int> st;

  for (auto it : arr)
  {
    st.insert(it);
  }

  for (auto it : arr2)
  {
    st.insert(it);
  }

  vector<int> uni;

  for (auto it : st)
  {
    uni.push_back(it);
  }

  return uni;
}
int main()
{

  vector<int> arr = {1, 3, 2};
  vector<int> arr2 = {1, 3, 4};
  // int n = arr.size();
  // int n2 = arr.size();
  vector<int> ans = unionNo(arr, arr2);
  for (auto it : ans)
  {
    cout << it << "";
  }
}