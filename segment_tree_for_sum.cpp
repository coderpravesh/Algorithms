#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define ll long long int
#define ld long double
#define ff first
#define ss second  
#define endl '\n'
#define pb push_back
#define t_case ll tt; cin>>tt; while (tt--)
#define all(v) v.begin(),v.end()
#define ub(a,x) upper_bound(all(a),x)-a.begin()
#define lb(a,x) lower_bound(all(a),x)-a.begin()
#define prdec(k) cout<<fixed<<setprecision(k);
#define fr(a,b,c) for (ll a=b;a<c;a++)
#define take(xx,n) for (int i=0;i<n;i++) cin>>xx[i];
#define take1(xx,n) for (int i=1;i<=n;i++) cin>>xx[i];
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
const auto inf=LLONG_MAX; 
ll mod=1e9+7;
ll exp(ll x,ll y){ll res=1;x=x%mod;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
ll modinv(ll x){return exp(x,mod-2);}


struct segtree{
	int size=1;
	vector<long long > sums;
	
	void init(int n) { //it initilize 
		while(size<n ) size*=2;
		sums.assign(2*size,0ll);
	}
	
	void set(int i,int v,int x,int lx,int rx){
		if( rx-lx == 1) {
			sums[x]=v; 
			return ;
		}
		int m= (lx+rx)/2;
		if (i<m) {
			set(i,v,2*x+1,lx,m);
		}else {
			set(i,v,2*x+2,m,rx);
		}
		sums[x]=sums[2 * x + 1]+sums[2 * x + 2 ];
	}
	
	void set(int i,int  v) { // it sets the value
	
		set(i,v,0,0,size); // starting form root 
	
	}
	
	long long sum(int l,int r,int x,int lx,int rx){
		if (rx<=l || r<=lx ) return 0ll;
		if (l<=lx && rx<=r) return sums[x];
		int m=(lx+rx)/2;
		return sum(l,r,2*x+1,lx,m )+sum(l,r,2*x+2,m,rx);
	}
	
	long long sum(int l,int r){
		return sum(l,r,0,0,size);
	}

};

int main() 
{
	fastio
	
	ll sum=0,f=-1,ans=0,n,m=0,mx=-inf,mn=inf   ;cin >> n >>m;
	
	segtree st;
	st.init(n);
	
	for (int i =0; i<n; i++){
		int v; cin>> v;
		st.set(i,v);	
	}
	while (m--) {
		int op; cin>>op;
		if (op==1) {
			int i,v; cin>>i>>v;
			st.set(i,v);
		} else {
			int l, r; cin >> l >> r;
			cout<<st.sum(l,r)<<'\n';
		}
	}
	return 0;
}

