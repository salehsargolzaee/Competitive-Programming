#include<bits/stdc++.h>
 
#define int long long
#define t_case int tt; cin>>tt; while (tt--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define For(i,j,k) for (int i=(int)(j);i<(int)(k);i++)
#define rFor(i,j,k) for (int i=(int)(k-1);i>=(int)(j);i--)
 
const long long LL_INF = (long long) 2e18 + 5;

const long long MOD = 1e9+7;
 
using namespace std;
 
/*--------------------------------------------------------------------------------*/
const int MAXN = 410;

void solve(){
    int n,k; cin>>n>>k;

    vector<int> v(n);

    For(i,0,n){
      cin>>v[i];
    }

    vector<bool> vis(n,0);

    sort(v.rbegin(), v.rend());

    int ans=0;
    for(int b = 20; b>=0;b--){
        if((1ll<<b)&ans or(!k))continue;
        For(i,0,n){
            if(v[i]&(1ll<<b) and !vis[i]){
              ans|=v[i];
              vis[i]=1;
              k--;
              break;
            }
        }
    }
    
    cout<<ans<<'\n';
} 
 
int32_t main(){
 

    freopen("looking.in", "r", stdin);

    fastio
     t_case
      solve();
 
    return 0;
   
}
