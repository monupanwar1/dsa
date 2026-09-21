#include <bits/stdc++.h>
using namespace std;

bool solve(int idx, vector<vector<char>> &board, string word,
           int i, int j)
{
  // base case
  if (idx == word.size())
  {
    return true;
  }

  int n = board.size();
  int m = board[0].size();

  if (i < 0 || i >= n || j < 0 || j >= m)
  {
    return false;
  }

  if (board[i][j] == ' ' || board[i][j] != word[idx])
    return false;

 

  board[i][j] = ' ';

  if (solve(idx + 1, board, word, i - 1, j) || (solve(idx + 1, board, word, i + 1, j)) || (solve(idx + 1, board, word, i, j - 1)) || (solve(idx + 1, board, word, i, j + 1)))
  {
    board[i][j] = word[idx];
    return true;
  }

  board[i][j] = word[idx];
  return false;
}

bool check(vector<vector<char>> &board, string word)
{
  int n = board.size();
  int m = board[0].size();

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == word[0])
      {
        if (solve(0, board, word, i, j))
          return true;
      }
    }
  }
  return false;
};

int main()
{
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};

  string word = "ABCCED";

  cout << check(board, word);
}
