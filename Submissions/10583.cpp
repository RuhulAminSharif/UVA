#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mx = 50005;
ll parent[mx], _rank[mx];
void make_Set(ll n)
{
    for(ll i=0;i<=n; i++){
        parent[i]=i;
        _rank[i]=0;
    }
}
ll find_parent(ll x)
{
    if(parent[x]==x) return x;
    return parent[x] = find_parent(parent[x]);
}
void unionByRank(ll u, ll v)
{
    ll x = find_parent(u);
    ll y = find_parent(v);
    if(x!=y){
        if(_rank[x]==_rank[y]){
            parent[y] = x;
            _rank[x] += 1;
        }else if(_rank[x]<_rank[y]){
            parent[x] = y;
        }else{
            parent[y] = x;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(1){
        ll n, m; cin >> n >> m;
        if( n==0 && m==0){
            break;
        }
        cout << "Case " << t++ << ": ";
        make_Set(n);
        for(ll i=0; i<m; i++){
            ll a, b; cin >> a >> b;
            unionByRank(a,b);
        }
        ll ans=0;
        for(ll i=1; i<=n; i++){
            if(parent[i]==i) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
