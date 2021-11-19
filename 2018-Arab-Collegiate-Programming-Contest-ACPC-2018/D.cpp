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
const int MAXN = 1020;

int compress_grid[MAXN][MAXN];

void solve(){

  int row, col, choc; cin>>row>>col>>choc;

  For(i,0,MAXN)For(j,0,MAXN)compress_grid[i][j]=0;

  vector<pair<int,int>>  point(choc);
  vector<int> x,y;
  map<int, int> mpx,mpy;

  For(i, 0, choc){
    int xx, yy; cin>>xx>>yy;
    x.push_back(xx), y.push_back(yy);

    point[i] = {xx, yy};

  }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    x.resize(( unique(x.begin(),x.end()) -x.begin() ));
    y.resize(( unique(y.begin(),y.end()) -y.begin() ));

   for(auto i: point){
     int xx = lower_bound(x.begin(), x.end(), i.first)-(x.begin())+1;
     int yy = lower_bound(y.begin(), y.end(), i.second)-(y.begin())+1;
   
     mpx[xx] = i.first,
     mpy[yy] = i.second;

     compress_grid[xx][yy] = 1;

   }

   
   int ans = 0;
   
   For(i,1, x.size()+1){
    For(j, 1, y.size()+1){
      compress_grid[i][j] += compress_grid[i-1][j]+compress_grid[i][j-1]-compress_grid[i-1][j-1];

        if(compress_grid[i][j] &1){

          int col_difference = mpy[j+1];
          int row_difference = mpx[i+1];

          if(!col_difference)col_difference =  col+1;
          if (!row_difference)row_difference = row+1;
        
          col_difference-=mpy[j];
          row_difference-=mpx[i];
   
          ans+=col_difference*row_difference;
      }
    } 
   }

   cout<<ans<<' '<<(row*col)-ans<<'\n';




} 
 
 
int32_t main(){
   
   freopen("dull.in", "r", stdin);

   t_case
  	  solve();
 
   return 0;
   
}
