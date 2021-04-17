#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    int n;
    cin >> n;
    ll p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll x, k;
        cin >> x >> k;
        int startIndex = x - 1;
        int count = 0;
        if (p[startIndex] <= k)
        {
            k -= p[startIndex];
            p[startIndex] = 0;
        }
        else
        {
            p[startIndex] -= k;
            k = 0;
        }
        int temp_K = k;
        startIndex++;
        while (startIndex < n && k > 0)
        {
            if (p[startIndex] <= k)
            {
                k -= p[startIndex];
                p[startIndex] = 0;
            }
            else
            {
                p[startIndex] -= k;
                k = 0;
            }
            count++;
            startIndex++;
        }
        cout << (temp_K - k) * count << endl;
    }
}