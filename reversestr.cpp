#include <iostream>
#include <vector>
using namespace std;

void reverseStr(vector<char> &s)
{
  int left = 0;
  int right = s.size() - 1;

  while (left < right)
  {
    swap(s[left], s[right]);
    left++;
    right--;
  }
}

int main()
{
  vector<char> s = {'k', 'u', 'n', 'a', 'l'};
  reverseStr(s);
  for (auto it : s)
  {
    cout << it << " ";
  }
}