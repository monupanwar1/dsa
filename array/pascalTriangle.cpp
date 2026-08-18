#include <iostream>
#include <vector>
using namespace std;

vector<int> pascalRow(int n)
{
  int res = 1;
  vector<int> ans;

  for (int i = 0; i <= n; i++)
  {
    ans.push_back(res);
    res *= (n - i);
    res /= (i + 1);
  }
  return ans;
}
int main()
{
  int n = 5;
  for (int i = 0; i < n; i++)
  {
    vector<int> ans = pascalRow(i);

    for (auto it : ans)
    {
      cout << it << " ";
    }
    cout << endl;
  }
  return 0;
}