---
id: usaco-665
source: USACO Bronze 2016 December
title: The Cow-Signal
---

[Problem link](http://www.usaco.org/index.php?page=viewproblem2&cpid=665)


## Implementation

**Time Complexity:** $\mathcal{O}(k^2*n*m)$

<LanguageSection>

<CPPSection>

```cpp

#include<bits/stdc++.h>

#define int long long

using ll = long long;
const long long LL_INF = (long long) 2e18 + 5;

using namespace std;

const int N = 1e5+10;


void solve(){

  int n,m, k; cin>>n>>m>>k;
  vector<string> v(k*n);

  for(int i =0; i<k*n; i++){

    if(i%k){
      v[i]= v[i-1];
      continue;
    }

    for(int j=0; j<m; j++){

      char a; cin>>a;

      for(int z=0; z<k; z++)
         v[i].push_back(a);
    }
  }

  for(auto i:v)cout<<i<<'\n';


   
} 
 
int32_t main(){
 

   freopen("cowsignal.in", "r", stdin);
   freopen("cowsignal.out", "w", stdout);
 

   ios::sync_with_stdio(0); cin.tie(NULL);


   solve();
 
   return 0;
   
}


```

</CPPSection>


</LanguageSection>