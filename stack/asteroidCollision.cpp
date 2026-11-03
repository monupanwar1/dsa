#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &asteroids)
{

  vector<int> st;
  for (int i = 0; i < asteroids.size(); i++)
  {
    int curr = asteroids[i];
    bool destroyed = false;

    while (!st.empty() && st.back() > 0 && curr < 0)
    {
      if (st.back() < abs(curr))
      {
        st.pop_back();
      }
      else if (st.back() == abs(curr))
      {
        st.pop_back();
        destroyed = true;
        break;
      }
      else
      {
        destroyed = true;
        break;
      }
    }

    
    if (!destroyed)

    {
      st.push_back(curr);
    }
  }
  return st;
};
int main()
{
  vector<int> asteroids = {5, 10, -5};

  vector<int> ans = asteroidCollision(asteroids);

  for (int x : ans)
  {
    cout << x << " ";
  }

  return 0;
}