#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxVal(vector<int> &piles)
{
  int n = piles.size();
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (ans < piles[i])
    {
      ans = piles[i];
    }
  }
  return ans;
}

int kokoBrute(vector<int> &piles, int h)
{

  int n = piles.size();

  int maxvalue = maxVal(piles);

  for (int speed = 1; speed <= maxvalue; speed++)
  {
    int hours = 0;

    for (int i = 0; i < n; i++)
    {
      hours += ceil((double)piles[i] / speed);
    }
    if (hours <= h)
    {
      return speed;
    }
  }
  return -1;
};

int kokoBS(vector<int> &piles, int h)
{

  int n = piles.size();
  int maxvalue = maxVal(piles);

  int low = 1;
  int high = maxvalue;
  int ans = -1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    int hours = 0;

    for (int i = 0; i < n; i++)
    {
      hours += ceil((double)piles[i] / mid);
    }
    if (hours <= h)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

int main()
{
  vector<int> piles = {3, 6, 7, 11};
  int h = 8;

  cout << "Brute Force Answer: "
       << kokoBrute(piles, h) << endl;

  cout << "Binary Search Answer: "
       << kokoBS(piles, h) << endl;

  return 0;
}