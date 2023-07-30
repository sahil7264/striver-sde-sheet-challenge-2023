bool fill(int num , int arr[9][9], int i, int j)
{
    for (int p = 0; p < 9; p++)
    {
        if (arr[i][p] == num)
            return false;
    }
    for (int p = 0; p < 9; p++)
    {
        if (arr[p][j] == num)
            return false;
    }
    for (int p = 0; p < 9; p++)
    {
        if (arr[3 * (i / 3) + p / 3][3 * (j / 3) + p % 3] == num)
            return false;
    }
    return true;
}
void debug(int arr[9][9], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isway(int matrix[9][9])
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (matrix[x][y] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (fill(num, matrix, x, y))
                    {
                        matrix[x][y] = num;

                        if (isway(matrix))
                            return true;
                        else
                            matrix[x][y] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return isway(matrix);
}
