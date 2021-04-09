#include <iostream>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[n][m];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        //for rows
        for(ll i=0;i<n;i++){
            ll prev = 0;
            for(ll j=0;j<m;j++){
                a[i][j]+= prev;
                prev = a[i][j];
            }
        }
        //for columns 
        for(ll i=0;i<m;i++){
            ll prev=0;
            for(ll j=0;j<n;j++){
                a[j][i]+=prev;
                prev = a[j][i];
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}