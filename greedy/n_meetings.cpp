
#include <bits/stdc++.h>
using namespace std;

struct Meeting
{
  int idx;
  int start;
  int end;
};

struct Result
{
  int count;
  vector<int> indices;
};

bool compare(Meeting a, Meeting b)
{
  return a.end < b.end;
}

Result maxMeetings(vector<int> &start, vector<int> &end)
{
  int n = start.size();
  vector<Meeting> meetings;

  for (int i = 0; i < n; i++)
  {
    meetings.push_back({i, start[i], end[i]});
  }

  sort(meetings.begin(), meetings.end(), compare);

  int count = 0;
  int lastEnd = -1;
  vector<int> selected;

  for (auto meeting : meetings)
  {
    if (meeting.start > lastEnd)
    {
      count++;
      lastEnd = meeting.end;
      selected.push_back(meeting.idx);
    }
  }

  return {count, selected};
}

int main()
{
  vector<int> start = {1, 3, 0, 5, 8, 5};
  vector<int> end = {2, 4, 6, 7, 9, 9};

  Result result = maxMeetings(start, end);

  cout << "Maximum meetings: " << result.count << '\n';

  cout << "Selected indices: ";
  for (int idx : result.indices)
  {
    cout << idx << " ";
  }
  cout << '\n';

  return 0;
}
