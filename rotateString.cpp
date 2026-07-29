#include <iostream>
using namespace std;


bool rotateString(string s, string goal)
{
  if (s.size() != goal.size())
    return false;
  string left = "";
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    left += s[i];
    string right = s.substr(i + 1);

    if (right + left == goal)
      return true;
  }
  return false;
}

bool rotateString1(string s, string goal)
{
  if (s.size() != goal.size())
    return false;

  if (s == goal)
    return true;

  return (s + s).find(goal) != string::npos;
}

int main()
{
  string s = "abcde";
  string goal = "cdeab";
  cout << (rotateString(s, goal) ? "True" : "False")<<endl;
  cout << (rotateString1(s, goal) ? "True" : "False");
}