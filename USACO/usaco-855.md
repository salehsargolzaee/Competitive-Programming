---
id: usaco-855
source: USACO Bronze 2018 December
title: Mixing Milk
---

[Problem link](http://www.usaco.org/index.php?page=viewproblem2&cpid=855#)

## Explanation

You can only simulate the process for the first 4 steps, after that the result will remain same for step 7, 10, 13... 100.

`(Notice that since the number of steps is 100 you can simulate all steps, in this case time complexity will be O(100) and it would pass)`
## Implementation

**Time Complexity:** $\mathcal{O}(1)$

<LanguageSection>

<CPPSection>

```cpp

#include<bits/stdc++.h>


using ll = long long;
const long long LL_INF = (long long) 2e18 + 5;

using namespace std;


void solve(){

   vector<ll> capacity(3), milk(3);

   for(int i=0; i<3; i++){
      cin>>capacity[i]>>milk[i];
   }

   for(int i=0; i<4;i++){
      ll pour_value = min(capacity[(i+1)%3]-milk[(i+1)%3], milk[i%3]);

      milk[(i+1)%3]+=pour_value;
      milk[i%3]-=pour_value;
   }
   
   for(int i=0; i<3; i++){
      cout<<milk[i]<<'\n';
   }
   
} 
 
int32_t main(){

   freopen("mixmilk.in", "r", stdin);
   freopen("mixmilk.out", "w", stdout);

   ios::sync_with_stdio(0); cin.tie(NULL);

   solve();
 
   return 0;
   
}



```

</CPPSection>


</LanguageSection>