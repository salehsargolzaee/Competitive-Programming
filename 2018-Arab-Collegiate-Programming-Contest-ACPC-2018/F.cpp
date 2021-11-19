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
const int MAXN = 320;


double dp[MAXN][2][MAXN][MAXN];

void solve(){


   int n,k ; cin>>n>>k; 

   vector<vector<int>> v(n, vector<int> (n));
   
   For(i,0,n)For(j,0,n)cin>>v[i][j];
   For(i,0,MAXN)For(j,0,2)For(m,0,MAXN)For(n,0,MAXN)dp[i][j][m][n]=0;

   vector<vector<double>>  p(n, vector<double> (n));

   double total_matrices = 0;

   For(i,0,n){
    For(j,0,n){
      total_matrices += (n-i)*(n-j);
    }
   }

   For(i,0,n){
    For(j,0,n){
      p[i][j]= (i+1)*(j+1)*(n-i)*(n-j)/total_matrices;
      dp[0][v[i][j]][i][j]+=1;
    }
   }

   For(m,1,k+1){
    For(s,0,2){
      For(i,0,n){
       For(j,0,n){
          dp[m][s][i][j]=p[i][j]*dp[m-1][s^1][i][j]+(1-p[i][j])*dp[m-1][s][i][j];
       }
      }
    }
   }


   double ans= 0;
   For(i,0,n){
    For(j,0,n){
      ans+= dp[k][1][i][j];
    }
   }

   cout<<fixed<<setprecision(5)<<ans<<'\n';

  
   

} 
int32_t main(){

   freopen("fetiera.in", "r", stdin);

   fastio
   t_case
     solve();
 
   return 0;
   
}
