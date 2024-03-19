#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> leftside;
unordered_map<int, bool> upperleft;
unordered_map<int, bool> lowerleft;

void printSol(vector<vector<char>> &board, int n)
{
    for (auto i : board)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char>> &board, int row, int col, int &n)
{
    // check on left side in straight line
    // Method 1 with O(n)
    // int i = row;
    // int j = 0;
    // for (; j <= col; j++)
    // {
    //     if (board[i][j] == 'Q')
    //     {
    //         return false;
    //     }
    // }

    if (leftside[row] == true)
    {
        return false;
    }

    // check for left upper dirn
    // Method 1 with O(n)

    if (upperleft[n - 1 + col - row] == true)
        return false;
    // j = col;

    // while (i >= 0 && j >= 0)
    // {
    //     if (board[i--][j--] == 'Q')
    //         return false;
    // }

    // // checking for left lower corner
    // // Method 1 with O(n)

    if (lowerleft[row + col] == true)
        return false;
    // i = row;
    // j = col;
    // while (i < n && j >= 0)
    // {
    //     if (board[i++][j--] == 'Q')
    //         return false;
    // }
    return true;
}

void solve(vector<vector<char>> &board, int col, int &n)
{
    // Base Condn
    
    if (col >= n)
    {
        printSol(board, n);
        cout << endl;
    }

    // Soln for 1 case
    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            leftside[row] = true;
            upperleft[n - 1 + col - row] = true;
            lowerleft[row + col] = true;

            solve(board, col + 1, n);

            // backtracking
            board[row][col] = '-';
            leftside[row] = false;
            upperleft[n - 1 + col - row] = false;
            lowerleft[row + col] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '-'));

    solve(board, 0, n);
    return 0;
}