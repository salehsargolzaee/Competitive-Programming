---
id: usaco-663
source: USACO Bronze 2016 December
title: Square Pasture
---

[Problem link](http://www.usaco.org/index.php?page=viewproblem2&cpid=663)

## Explanation

First let's find the smallest rectangle that covers both pastures. 
In order to achive that, width of this rectangle would be from leftmost X to rightmost X 
in horizontal axis. We can calculate the width with this formula :

max(upper right x in both rectangular pastures) - min(lower left x in both rectangular pastures)

By the same logic, we can caculate its height with this formula :

max(upper right y in both rectangular pastures) - min(lower left y in both rectangular pastures)

Now in order to have a square we should take the maximum out of these two :

length_of_square = max(width, height)

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

   // first rectangle => bottom left = (x[0], y[0]), top right = (x[1], y[1])
   // second rectangle => bottom left = (x[2], y[2]), top right = (x[3], y[3])
   vector<int> x(4), y(4);

   for(int i=0; i<4; i++){
      cin>>x[i]>>y[i];
   }

   int max_width = max(x[1], x[3])-min(x[0], x[2]);
   int max_height = max(y[1], y[3])-min(y[0], y[2]);

   int square_length = max(max_height, max_width);

   cout<<square_length*square_length;

} 
 
int32_t main(){
 
   freopen("square.in", "r", stdin);
   freopen("square.out", "w", stdout);


   ios::sync_with_stdio(0); cin.tie(NULL);

   solve();
 
   return 0;
   
}

```

</CPPSection>


</LanguageSection>