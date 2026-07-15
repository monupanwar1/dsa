#include <iostream>
using namespace std;

int countOcc(char arr[], int n, int target)
{
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
    {
      count++;
    }
  }
  return count;
}

// int main()
// {
//   int n;

//   cout << "Enter number of characters: ";
//   cin >> n;

//   char arr[n];
//   cout << "Enter " << n << " characters: ";
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }
//   int q;
//   cout << "How many queries do you want to ask? ";
//   cin >> q;

//   while (q--)
//   {
//     char ch;
//     cout << "Enter character to search: ";
//     cin >> ch;
//     cout << "Occurrence = " << countOcc(arr, n, ch) << endl;
//   }
//   return 0;
// }

int main()
{
  int n;

  cout << "Enter number of characters: ";
  cin >> n;

  char arr[n];
  cout << "Enter " << n << " characters: ";

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int hash[256] = {0};

  for (int i = 0; i < n; i++)
  {
    hash[arr[i]]++;
  }
  int q;

  cout << "How many queries do you want to ask? ";
  cin >> q;
  while (q--)
  {
    char ch;
    cout << "Enter character to search: ";
    cin >> ch;

    cout << "Occurrence = " << hash[ch] << endl;
    }
  return 0;
}
