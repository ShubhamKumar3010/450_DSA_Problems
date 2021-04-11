#include <iostream>
using namespace std;
using ll = long long int;
ll min (ll x, ll y){
    if(x < y){
        return x;
    }
    return y;
}

int main() {
 ll t;
 cin>>t;
 while(t--){
     ll n, m, k;
     cin>>n>>m>>k;
     double mat[n + 1][m + 1];
     for(ll i = 0;i <= n; i++){
         for(ll j = 0; j <= m; j++){
             if(i == 0 || j == 0){
                 mat[i][j] = 0;
             }
             else{
                 cin>>mat[i][j];
             }
         }
     }
     for(ll i = 0; i <= n; i++){
         double pre = 0;
         for(ll j = 0; j <= m; j++){
             mat[i][j] += pre;
             pre = mat[i][j];
         }
     }
     for(ll j = 0; j <= m; j++){
         double pre = 0;
         for(ll i = 0; i <= n; i++){
             mat[i][j] += pre;
             pre = mat[i][j];
         }
     }
     ll z = min(n, m);
     ll ans = 0;
     for(ll len = 1; len <= z; len++){
         for(ll i = len; i <= n; i++){
             for(ll j = len; j <= m; j++){
                 if((mat[i][j] + mat[i - len][j - len] - mat[i][j - len] - mat[i - len][j])/(len * len) >= k){
                     ans++;
                 }
             }
         }
     }
     cout<<ans<<endl;
 }
}