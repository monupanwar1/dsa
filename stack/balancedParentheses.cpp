#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
  while (true)
  {
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
      if (i + 1 < s.size() && ((s[i] == '(' && s[i + 1] == ')') ||
                               (s[i] == '{' && s[i + 1] == '}') ||
                               (s[i] == '[' && s[i + 1] == ']')))
      {
        i++;
      }
      else
      {
        temp += s[i];
      }
    }
    if (temp == s)
    {
      break;
    }
    s = temp;
  }
  return s.empty();
}

bool isValidOpt(string s)
{
  stack<char> st;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
      st.push(s[i]);
    }
    else
    {
      if (st.empty())
      {
        return false;
      }
      if (
          (s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))
      {
        st.pop();
      }
      else
      {
        return false;
      }
    }
  }
  return st.empty();
}

int main()
{

  string s = "{[()]}";

  if (isValid(s))
  {
    cout << "Balanced";
  }
  else
  {
    cout << "Not Balanced";
  }

  cout << "__________2_____________" << endl;

  if (isValidOpt(s))
  {
    cout << "Balanced";
  }
  else
  {
    cout << "Not Balanced";
  }

  return 0;
}
