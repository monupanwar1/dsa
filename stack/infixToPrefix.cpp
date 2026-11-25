#include <bits/stdc++.h>
using namespace std;

int priority(char ch)
{
  if (ch == '^')
    return 3;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;

  return -1;
}
string infixToPrefix(string s)
{
  reverse(s.begin(), s.end());

  // Swap brackets
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
      s[i] = ')';
    else if (s[i] == ')')
      s[i] = '(';
  }

  stack<char> st;
  string ans = "";

  for (int i = 0; i < s.size(); i++)
  {
    char ch = s[i];

    // Operand
    if (isalnum(ch))
    {
      ans += ch;
    }

    // Opening bracket
    else if (ch == '(')
    {
      st.push(ch);
    }

    // Closing bracket
    else if (ch == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        ans += st.top();
        st.pop();
      }

      if (!st.empty())
        st.pop();
    }

    // Operator
    else
    {
      while (!st.empty() && st.top() != '(' &&
             (priority(st.top()) > priority(ch) ||
              (priority(st.top()) == priority(ch) && ch == '^')))
      {
        ans += st.top();
        st.pop();
      }

      st.push(ch);
    }
  }

  // Pop remaining operators
  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }

  reverse(ans.begin(), ans.end());

  return ans;
}

int main()
{
  string s = "A+B*C";

  cout << "Infix: " << s << endl;
  cout << "Prefix: " << infixToPrefix(s) << endl;

  return 0;
}