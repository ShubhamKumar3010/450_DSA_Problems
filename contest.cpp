#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mat[1000][1000];
void matSolve()
{
    int count = 1;
    int count2 = 0;
    for (int i = 0; i <  1000; i++)
    {
        mat[i][0] = i + count;
        for (int j = 1; j < 1000; j++)
        {
            mat[i][j] = mat[i][j - 1] + j + count2;
        }
        count += i + 1;
        count2++;
    }
}
int main()
{
    matSolve();
    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int ans = 0;
        for (int i = x1; i <= x2; i++)
        {
            ans += mat[i][y1];
        }
        for (int i = y1+1; i <= y2; i++)
        {
            ans += mat[x2][i];
        }
        cout << ans << endl;
    }
}
