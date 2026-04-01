#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateBrute(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    vector<vector<int>> rotated(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            rotated[j][n-1-i] = matrix[i][j];
        }
    }

    return rotated;
}

int main()
{
    vector<vector<int>> matrix =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> ans = rotateBrute(matrix);

    for(auto row : ans)
    {
        for(int x : row)
            cout << x << " ";
        cout << endl;
    }
}
