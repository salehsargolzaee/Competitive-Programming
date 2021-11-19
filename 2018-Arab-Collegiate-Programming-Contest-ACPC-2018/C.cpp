#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//////////////////////////////////////////
#define endl '\n'
#define pb push_back
#define gg exit(0)
#define inf 2147483647
#define linf 9223372036854775807LL
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ti tuple<int,int,int>
#define mp make_pair
#define mt make_tuple
#define vi vector<int>
#define vb vector<bool>
#define vpi vector<pi>
#define vpll vector<pll>
#define vll vector<ll>
#define vti  vector<ti>
#define vvi vector<vi>
#define F first
#define S second
#define tcase int tttttt;cin>>tttttt;while(tttttt--)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define mod ((int)1e9+7)

#define int long long
/////////////////////////////////////////
///////////////functions/////////////////

void solve(){
	int n,m;
	cin>>n>>m;
	map<string, ti> coffee;

	for(int i=0;i<n;i++){
		string s;
		int a,b,c;
		cin>>s>>a>>b>>c;
		coffee[s] = {a,b,c};
	}

	for(int i=0;i<m;i++){
		string a,b,c;
		cin>>a>>b>>c;
		int ans = 100 / m;
		if(b=="small"){
			ans += (get<0>(coffee[c]));
		}else if(b=="medium"){
			ans += (get<1>(coffee[c]));
		}else
			ans += (get<2>(coffee[c]));
		if(ans % 5 == 1) ans = (ans/5)*5;
		if(ans%5 == 4) ans = (ans/5+1)*5;
		cout<<a<<" "<<ans<<endl;
	}


}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("coffee.in", "r", stdin);
	//freopen("teleport.out", "w", stdout);
	///////////////////////////////////////////////
	tcase solve();
	return 0;
}
