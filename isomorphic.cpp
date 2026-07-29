#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t)
{
  // base case
  if (s.size() != t.size())
    return false;

  unordered_map<char, char> smap, tmap;

  for (int i = 0; i < s.size(); i++)
  {
    // early return
    if (smap.count(s[i]) && smap[s[i]] != t[i])
      return false;
    if (tmap.count(t[i]) && tmap[t[i]] != s[i])
      return false;

    // mapping
    smap[s[i]] = t[i];
    tmap[t[i]] = s[i];
  }
  return true;
}
int main()
{
  string s = "paper";
  string t = "title";

  cout << (isIsomorphic(s, t) ? "True" : "False");
}
