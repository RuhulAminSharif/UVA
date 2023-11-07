#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mx = 30005;
ll parent[mx], _size[mx];
void make_Set(ll n)
{
    for(ll i=0;i<=n; i++){
        parent[i]=i;
        _size[i]=1;
    }
}
ll find_parent(ll x)
{
    if(parent[x]==x) return x;
    return parent[x] = find_parent(parent[x]);
}
void unionBySize(ll u, ll v)
{
    ll x = find_parent(u);
    ll y = find_parent(v);
    if(x!=y){
        if(_size[x]<_size[y]){
            parent[x] = y;
            _size[y] += _size[x];
        }else{
            parent[y] = x;
            _size[x] += _size[y];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        make_Set(n);
        for(ll i=0; i<m; i++){
            ll a, b; cin >> a >> b;
            unionBySize(a,b);
        }
        ll ans=0;
        for(ll i=1; i<=n; i++){
            ans = max(ans,_size[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
