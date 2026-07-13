#include <iostream>
#include <cmath>

using namespace std;

int lcm(int n1, int n2)
{
  int ans = max(n1, n2);

  while (true)
  {
    if (ans % n1 == 0 && ans % n2 == 0)
    {
      return ans;
    }
    ans++;
  }
}

int main()
{
  int n1 = 7, n2 = 3;
  cout << lcm(n1, n2);
  return 0;
}