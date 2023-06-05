#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &matrix, int x, int y)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][y] != 0)
        {
            matrix[i][y] = 1e9;
        }
    }
    for (int j = 0; j < matrix[0].size(); j++)
    {
        if (matrix[x][j] != 0)
        {
            matrix[x][j] = 1e9;
        }
    }
}
void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int mod = 1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                solve(matrix, i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == mod)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
int main()
{

    return 0;
}