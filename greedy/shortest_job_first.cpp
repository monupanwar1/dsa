
#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
  if (a != b)
  {
    return a < b;
  }
  return false;
}

double shortestJobFirst(int jobs[], int n)
{

  sort(jobs, jobs + n, compare);

  int waitingTime = 0;
  int totalWaitingTime = 0;

  for (int i = 0; i < n; i++)
  {
    totalWaitingTime += waitingTime;
    waitingTime += jobs[i];
  }

  return (double)totalWaitingTime / n;
}

int main()
{
  int jobs[] = {4, 3, 7, 1, 2};
  int n = sizeof(jobs) / sizeof(jobs[0]);

  cout << "Average Waiting Time: "
       << shortestJobFirst(jobs, n) << endl;

  return 0;
}
