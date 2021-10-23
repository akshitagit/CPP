#include <bits/stdc++.h>
using namespace std;
#define maxx 1000101
typedef long long ll;
ll arr[4*maxx],sgtree[4*maxx],lazy[4*maxx];

void add(int id,ll l,ll r,ll v){
	ll sz = r-l+1;
	ll mid = (l+r) >> 1;
	sgtree[id] += sz*v;
	lazy[id<<1] += v*(mid-l+1);
	lazy[id<<1|1] += v*(r-mid);
	lazy[id] = 0;
}
void update(int id,ll l, ll r,ll x,ll y,ll v){
	add(id,l,r,lazy[id]/(r-l+1));
	if(l >= x && r <= y) {add(id,l,r,v);}
	else if( l > y || r < x) ;
	else{
		ll m = (l+r) >> 1;
		update(id<<1,l,m,x,y,v);
		update(id<<1|1,m+1,r,x,y,v);
		sgtree[id] = sgtree[id<<1] + sgtree[id<<1|1];
	} 
	
}
ll query(int id,ll l,ll r,ll x,ll y){
	add(id,l,r,lazy[id]/(r-l+1));
	if( l >= x && r <= y){return sgtree[id];}
	else if( l > y || r < x) return 0ll;
	else{
		ll m = (l+r) >> 1;
		return query(id<<1,l,m,x,y) + query(id<<1|1,m+1,r,x,y);
	}
}
