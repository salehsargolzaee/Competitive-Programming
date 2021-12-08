---
id: usaco-891
source: USACO Bronze 2019 January 
title: Shell Game
---

[Problem link](http://www.usaco.org/index.php?page=viewproblem2&cpid=891)

## Explanation

Just simulate process of game and calculate score for all of these three cases:
1. Pebble is under first shell
2. Pebble is under second shell
3. Pebble is under third shell
The you can take the maximum score out of these three cases.

## Implementation

**Time Complexity:** $\mathcal{O}(N)$

<LanguageSection>

<CPPSection>

```cpp

#include<bits/stdc++.h>


using ll = long long;
const long long LL_INF = (long long) 2e18 + 5;

using namespace std;


void solve(){
    
    // shells[i] => Store which shell is at position 'i'
    // score[i] => Store score of Elsie if pebble is under 'i'th shell

    array<int, 3> score{}, shells{0, 1, 2};
    
    int swaps, ans=0; cin>>swaps;

    while(swaps--){
      int a, b, guess; cin>>a>>b>>guess;
      a--, b--, guess--;
      
      swap(shells[a], shells[b]);

      ans=max(ans,++score[shells[guess]]);

    }
    
    cout<<ans<<'\n';
   
   
} 
 
int32_t main(){
 
   freopen("shell.in", "r", stdin);
   freopen("shell.out", "w", stdout);

   ios::sync_with_stdio(0); cin.tie(NULL);

   solve();
 
   return 0;
   
}

```

</CPPSection>


</LanguageSection>