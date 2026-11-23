#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
  if (ch == '^')
    return 3;

  if (ch == '*' || ch == '/' || ch == '%')
    return 2;

  if (ch == '+' || ch == '-')
    return 1;

  return -1;
}

string infixToPostfix(string s)
{
  stack<char> st;
  string ans = "";

  for (int i = 0; i < s.length(); i++)
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

      st.pop();
    }
    // Operator
    else
    {
      while (!st.empty() &&
             precedence(st.top()) >= precedence(ch))
      {
        ans += st.top();
        st.pop();
      }

      st.push(ch);
    }
  }

  // Empty remaining stack
  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }

  return ans;
}

int main()
{
  string s = "A+B*C-D";

  cout << infixToPostfix(s);

  return 0;
}