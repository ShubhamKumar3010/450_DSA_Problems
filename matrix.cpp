#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c);

bool searchMatrix(vector<vector<int>> &matrix, int target);

int rowWithMax1s(vector<vector<int>> arr, int n, int m);

int main()
{
    vector<vector<int>> matrix{{0, 1, 1, 1},
                               {0, 0, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    cout << rowWithMax1s(matrix, 4,4);
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[j][i]==1){
                return j;
            }
        }
    }
    return -1;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    bool found = false;
    int c = matrix[0].size();
    for (int i = 0; i < matrix.size(); i++)
    {
        if (target <= matrix[i][c - 1])
        {
            found = binary_search(matrix[i].begin(), matrix[i].end(), target);
            break;
        }
    }
    return found;
}

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    // code here
    vector<int> out;
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    //we will one variable direction to maintain the traversal.
    int dir = 1;
    //1-for left-right
    //2-for top-bottom
    //3-for righ-left
    //4-for bottom-up
    while (top <= bottom && left <= right)
    {
        if (dir == 1)
        {
            for (int i = left; i <= right; i++)
            {
                out.push_back(matrix[top][i]);
            }
            top++;
            dir = 2;
        }
        else if (dir == 2)
        {
            for (int i = top; i <= bottom; i++)
            {
                out.push_back(matrix[i][right]);
            }
            right--;
            dir = 3;
        }
        else if (dir == 3)
        {
            for (int i = right; i >= left; i--)
            {
                out.push_back(matrix[bottom][i]);
            }
            bottom--;
            dir = 4;
        }
        else if (dir == 4)
        {
            for (int i = bottom; i >= top; i--)
            {
                out.push_back(matrix[i][left]);
            }
            left++;
            dir = 1;
        }
    }
    return out;
}