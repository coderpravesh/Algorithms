
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<int null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//list of functions: set.insert(val), *(set.find_by_order(order-1)), set.order_of_key(val) num of element smaller then val
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ld long double
#define ff first
#define ss second  
#define pb push_back
#define all(v) v.begin(),v.end()
#define ub(a,x) upper_bound(all(a),x)-a.begin()
#define lb(a,x) lower_bound(all(a),x)-a.begin()
#define prdec(k) cout<<fixed<<setprecision(k) ;
#define fr(a,b,c) for (ll a=b;a<c;a++)
#define take(xx,n) for (int i=0;i<n;i++) cin>>xx[i];
#define take1(xx,n) for (int i=1;i<=n;i++) cin>>xx[i];
const auto inf= LLONG_MAX ; 
ll mod = 998244353;
ll exp(ll x,ll y){ll res=1;x=x%mod;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
ll modinv(ll x){return exp(x,mod-2);}
ll add(ll a,ll b){a%=mod,b%=mod;a=((a+b)%mod+mod)%mod;return a;}
ll sub(ll a,ll b){a=((a-b)%mod+mod)%mod;return a;}
ll mul(ll a,ll b){a%=mod,b%=mod;a=((a*b)%mod+mod)%mod;return a;}
const int  N = 2e5+2 ;

ll dp[N], a[N], ans[N] ;
vector<int>  adj[N] ;

int dfs(int vx , int pr) {
    dp[vx] = 2*a[vx] -1 ; 
    for (auto x : adj[vx]) {
        if (x == pr) continue ;
        dp[vx] += max(0,dfs(x,vx)) ;
    }

    return dp[vx] ;
}

void dfs1(int vx , int pr ) {
    ans[vx] = dp[vx] ;
    for (auto x : adj[vx]) {
        if (x == pr) continue ;
        dp[vx] -= max((ll)0, dp[x]);
        dp[x] += max((ll)0, dp[vx]);
        dfs1(x,vx);
        dp[x] -= max((ll)0,dp[vx]);
        dp[vx] += max((ll)0,dp[x]) ;
    }

}

void solve(){
    ll sum=0,f=1,mx=0,mn=inf,n  ;
    cin >> n ;

    take1(a,n);
    fr(i,0,n-1) {
        int x,y;
        cin >> x >> y ;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,0);
    dfs1(1,0);

    for (int i = 0; i < n ; i++) 
        cout << ans[i+1] << ' ' ;

    return ;
       
}
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll t_case=1;
    // cin >> t_case ;
    fr(i,1,t_case+1){
        //cout<<"Case #"<<i<<": ";
        solve();
        cout<<"\n";
    }
    
    return 0;
}