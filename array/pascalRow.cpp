#include <iostream>
#include <vector>
using namespace std;

vector<int> pascalRow(int n)
{
  vector<int> ans;
  int res = 1;
  for (int i = 0; i < n; i++)
  {
    ans.push_back(res);
    res *= (n - i);
    res /= (i + 1);
  }

  return ans;
}

int main()
{
  int n = 4;
  vector<int> ans = pascalRow(n);
  for (auto it : ans)
  {
    cout << it << " " << endl;
  }
}