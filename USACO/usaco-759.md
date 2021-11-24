---
id: usaco-759
source: USACO 2017 December Contest, Bronze
title: Blocked Billboard
---

[Problem link](http://www.usaco.org/index.php?page=viewproblem2&cpid=759)

## Explanation

First we calculate the area of two billboard. It can be calculated with formula : (X cordinate of upper right - X cordinate of lower left) * (Y cordinate of upper right - Y cordinate of lower left)

Then simply subtract intersection with truck from area.
Intersection with each cordinate can be calculated with formula :
x cordinate intersection = max(0, min(X cordinate of billboard upper right, X cordinate of truck upper right)-max(X cordinate of billboard lower left, X cordinate of truck lower left));

y cordinate intersection = max(0, min(Y cordinate of billboard upper right, Y cordinate of truck upper right)-max(Y cordinate of billboard lower left, Y cordinate of truck lower left));

total intersection with each billboard = x cordinate intersection * y cordinate intersection


## Implementation

**Time Complexity:** $\mathcal{O}(1)$

<LanguageSection>

<CPPSection>

```cpp
#include<bits/stdc++.h>
 
#define t_case int tt; cin>>tt; while (tt--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define For(i,j,k) for (int i=(int)(j);i<(int)(k);i++)
#define rFor(i,j,k) for (int i=(int)(k-1);i>=(int)(j);i--)
 
const long long LL_INF = (long long) 2e18 + 5;

const long long MOD = 1e9+7;
 
using ll = long long;

using namespace std;
 
/*--------------------------------------------------------------------------------*/
const int MAXN = 320;



void solve(){

    // first billboard => x[0] and x[1], y[0], y[1]
    // second billboard => x[2] and x[3], y[2], y[3]
    // truck => x[4] and x[5], y[5] and y[6]
    vector<int> x(6),y(6);
    
    for(int i = 0; i<6; i++){
       cin>>x[i]>>y[i];
    }

    int intersection_with_first = 0, area_first = (x[1]-x[0])*(y[1]-y[0]);
    int intersection_with_second = 0, area_second = (x[3]-x[2])*(y[3]-y[2]);

    intersection_with_first = max(0, min(x[1], x[5])-max(x[0], x[4]));
    intersection_with_first *= max(0, min(y[1], y[5])-max(y[0], y[4]));

    intersection_with_second = max(0, min(x[3], x[5])-max(x[2], x[4]));
    intersection_with_second *= max(0, min(y[3], y[5])-max(y[2], y[4]));

    cout<<area_first - intersection_with_first + area_second - intersection_with_second;


} 
 
int32_t main(){
 

   freopen("billboard.in", "r", stdin);
   freopen("billboard.out", "w", stdout);


   ios::sync_with_stdio(0); cin.tie(NULL);

   solve();
 
   return 0;
   
}


```

</CPPSection>


</LanguageSection>