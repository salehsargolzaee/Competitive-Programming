---
id: usaco-783
source: USACO Bronze 2018 January 
title: Blocked Billboard II
---

[Problem link](http://www.usaco.org/index.php?page=viewproblem2&cpid=783)

## Explanation

There is only two cases in which the cow feed billboard will obscure lawnmower billboard:

1. width intersection of two billboard is equal width of lawnmower billboard:
   - in this case, we need to check if height of cow feed billboard is covering one or both sides of lawnmower billboard in the `Y` axis or not. We can find that by this logic:
   - if y cordinate of cow feed billboard upper right is greater than or equal y cordinate of lawnmower billboard upper right, then for sure it is obscuring top half of lawnmower billboard.
   - if y cordinate of cow feed billboard lower left is less than or equal y cordinate of lawnmower billboard lower left, then for sure it is obscuring bottom half of lawnmower billboard.
     
2. height intersection of two billboard is equal height of lawnmower billboard:
   - in this case, we need to check if width of cow feed billboard is covering one or both sides of lawnmower billboard in the `X` axis or not. We can find that by this logic:
   - if x cordinate of cow feed billboard upper right is greater than or equal x cordinate of lawnmower billboard upper right, then for sure it is obscuring right half of lawnmower billboard.
   - if x cordinate of cow feed billboard lower left is less than or equal x cordinate of lawnmower billboard lower left, then for sure it is obscuring left half of lawnmower billboard.

If one of the mentioned cases is true, we can subtract the intersect area of two billboard from area of lawnmower billboard.


## Implementation

**Time Complexity:** $\mathcal{O}(1)$

<LanguageSection>

<CPPSection>

```cpp

#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int intersect_area(pair<pair<int,int>, pair<int,int>> s1, 
                  pair<pair<int,int>, pair<int,int>> s2){

   int bl_a_x = s1.first.first, bl_a_y = s1.first.second, tr_a_x = s1.second.first, tr_a_y = s1.second.second;
   int bl_b_x = s2.first.first, bl_b_y = s2.first.second, tr_b_x = s2.second.first, tr_b_y = s2.second.second;

   return (
      (min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)) 
      * (min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y))
   );
}

void solve(){
   
   // cow feed billboard billboard = (x[0], y[0]), (x[1], y[1])
   // lawnmower billboard = (x[2], y[2]), (x[3], y[3])
   vector<int> x(4), y(4);
   
   for(int i= 0; i<4; i++){
      cin>>x[i]>>y[i];
   }

   int width = x[1]-x[0], height = y[1]-y[0];

   int ans = width*height;

   int intersection = intersect_area({{x[0], y[0]}, {x[1], y[1]}}, {{x[2],y[2]},{x[3], y[3]}});

   bool width_coverage = (min(x[1], x[3])-max(x[0], x[2])) == width;
   bool height_coverage = (min(y[1], y[3])-max(y[0], y[2])) == height;
   
   if(width_coverage and (y[3]>=y[1] or y[2]<=y[0])){

      ans-= intersection;

   }else if(height_coverage and (x[3]>=x[1] or x[2]<=x[0])){

      ans-=intersection;

   }

   cout<<ans<<'\n';

   
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