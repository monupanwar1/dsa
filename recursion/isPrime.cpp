#include <iostream>
using namespace std;

bool isPrime(int i, int n)
{
  if (n <= 1)
    return false;

  if (i * i > n)
  {
    return true;
  }
  if (n % i == 0)
    return false;

  return isPrime(i + 1, n);
};

int main()
{
  int i = 2;
  int n = 2;
  cout << (isPrime(i, n) ? "Prime" : "non prime");
}