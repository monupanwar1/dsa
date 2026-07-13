#include <iostream>
using namespace std;
#include <vector>

vector<int> divisor(int n)
{
  vector<int> list;

  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      list.push_back(i);
    }
  }
  return list;
}

int main()
{
  int n = 36;
  vector<int> ans = divisor(n);
  for (auto x : ans)
  {
    cout << x << " ";
  }

  return 0;
}