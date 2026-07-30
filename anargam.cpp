#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
  if (s.length() != t.length())
  {
    return false;
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  return s == t;
}

bool isAnagram1(string s, string t)
{
  if (s.length() != t.length())
  {
    return false;
  }

  unordered_map<char, int> mp;

  for (char ch : s)
  {
    mp[ch]++;
  }
  for (char ch : t)
  {
    
    if(mp.count(ch)==0)
      return false;

    mp[ch]--;


    if (mp[ch] == 0)
    {
      mp.erase(ch);
    }
  }

  return mp.empty();
}

int main()
{
  string s = "anagram";
  string t = "nagaram";
  if (isAnagram(s, t))
    cout << "True";
  else
    cout << "false";
  if (isAnagram1(s, t))
    cout << "True";
  else
    cout << "false";
}