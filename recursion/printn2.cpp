#include <iostream>
using namespace std;

// Tail Recursion

// 1 to n
void printTail(int i, int n)
{
  if (i > n)
    return;

  cout << i << " ";
  printTail(i + 1, n);
}

// n to 1
void printTail2(int n)
{
  if (n == 0)
    return;

  cout << n << " ";
  printTail2(n - 1);
}

// Head Recursion

// 1 to n
void printHead(int n)
{
  if (n == 0)
    return;

  printHead(n - 1);
  cout << n << " ";
}

// n to 1
void printHead2(int i, int n)
{
  if (i > n)
    return;

  printHead2(i + 1, n);
  cout << i << " ";
}

int main()
{
  int i = 1;
  int n = 20;

  cout << "_____TAIL_____" << endl;
  printTail(i, n);

  cout << "\n_____TAIL2_____" << endl;
  printTail2(n);

  cout << "\n_____HEAD_____" << endl;
  printHead(n);

  cout << "\n_____HEAD2_____" << endl;
  printHead2(i, n);

  return 0;
}