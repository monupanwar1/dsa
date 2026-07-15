#include <iostream>
using namespace std;

// brute

// int countOccurrence(int arr[], int n, int target)
// {
//   int count = 0;

//   for (int i = 0; i < n; i++)
//   {
//     if (arr[i] == target)
//     {
//       count += 1;
//     }
//   }
//   return count;
// }

// int main()
// {
//   int n;
//   cout << "Enter size of array: ";
//   cin >> n; // size

//   int arr[n];
//   cout << "Enter " << n << " elements: ";

//   // input elem
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }

//   int q;
//   cout << "How many queries do you want to ask? ";
//   cin >> q;
//   while (q--)
//   {
//     int number;
//     cout << "Enter number to search: ";
//     cin >> number;

//     cout << "Occurrence = " << countOccurrence(arr, n, number) << endl;
//   }
//   return 0;
// }

// prestore

int main()
{
  int n;
  cout << "enter size of arr";
  cin >> n;

  int arr[n];
  int maxElem = 0;

  cout << "Enter " << n << " elements: ";

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];

    if (arr[i] > maxElem)
    {
      maxElem = arr[i];
    }
  }

  int hash[maxElem + 1] = {0};

  // prestore
  for (int i = 0; i < n; i++)
  {
    hash[arr[i]]++;
  }

  int q;
  cout << "How many queries do you want to ask? ";
  cin >> q;

  while(q--){
    int number;
    cout << "Enter number to search: ";
    cin >> number;

    if(number<=maxElem)
      cout << "Occurrence = " << hash[number] << endl;
    else
      cout << "Occurrence = 0" << endl;
  }
  return 0;
}