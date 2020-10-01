#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 100
class SegTree{
    SegTree* node;
    ll N;
    
    SegTree(vector<ll> arr, ll N)
    {
        this->N=N;
        SegTree node=new SegTree[getSize(N)];
         buildTree(arr,1,0,N-1);
    }
    ll getSize(ll N)
    {
        ll size=1;
        for(;size<N; size<<=1);
        return size<<1;
    }
    void assign(ll val)
    {
       
    }
    SegTree* getValue(ll lo, ll hi)
    {
        SegTree res=getValue(1,0,N-1,lo,hi);
        return res.getValue();
    }
    void update(ll idx, ll val)
    {
        update(1,0, N-1,idx,val);
    }
    void buildTree(vector<ll>, ll idx, ll lo, ll hi);
    void merge(ll a, ll b);
    SegTree* getValue(vector<ll> a,ll left, ll right, ll lo, ll hi)
    void update(ll,ll,ll,ll,ll);
};
void buildTree(vector<ll> a, ll idx, ll lo, ll hi)
{
    if(lo==hi)
    {
        node[idx]=a[lo];
        return;
    }
    
    ll left=2*idx;
    ll right=left+1;
    ll mid=(lo+hi)/2;
    
    buildTree(a,left,mid+1,hi);
    buildTree(a,right,lo,mid);
    node[idx].merge(node[left], node[right]);
}
SegTree getValue(ll idx,ll left, ll right, ll lo, ll hi)
{
    if(lo==left && hi==right)
    {
       return node[idx];
    }
    
    mid=(lo+hi)/2;
    if(mid<lo)
        return getValue(2*idx+1,mid+1,right,lo,hi);
    else if(mid>=hi)
        return getValue(2*idx,left,mid,lo,hi);
        
        
    SegTree leftTree=getValue(2*idx,left,mid,lo,mid);
    SegTree rightTree=getValue(2*idx+1,mid+1,right,mid+1,hi);
    SegTree res;
    res.merge(leftTree,rightTree);
    return res;
}
void update(ll sidx,ll lo, ll hi, ll index, ll val)
{
    if(lo==hi)
    {
        node[sidx]=val;
        return;
    }
    
    ll left=2*sidx; ll right=2*sidx+1; ll mid=(lo+hi)/2;
    if(index<=mid)
     update(left,lo,mid,index,val);
    else
     update(right,mid+1,hi,index,val);
     
     
    node[sidx],merge(node[left],node[right]);
}
int main()
{
    ll N;
    cin>>N;
    vector<ll> arr;
    
    for(ll i=0; i<N; i++)
    {
       ll x;
       cin>>x;
       arr.push_back(x);
    }
    SegTree obj(arr,N);
    return 0;
}
