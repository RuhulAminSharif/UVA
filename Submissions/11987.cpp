#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mx = 1e5+10;
ll parent[2*mx], _size[mx], sum[2*mx];
void make_Set(ll n)
{
    for(ll i=0, j=n+1; i<=n; i++, j++){
        parent[i] = parent[j] = j;
        sum[j] = i;
        _size[j] = 1;
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
            sum[y] += sum[x];
        }else{
            parent[y] = x;
            _size[x] += _size[y];
            sum[x] += sum[y];
        }
    }
}
void moveP(ll p, ll q)
{
    ll x = find_parent(p);
    ll y = find_parent(q);
    if(x!=y){
        sum[x] -= p;
        _size[x] -= 1;
        sum[y] += p;
        _size[y] += 1;
        parent[p] = y;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    while(cin >> n >> m){
        make_Set(n);
        for(ll i=0; i<m; i++){
            ll c, p, q;
            cin >> c;
            if(c==1||c==2){
                cin >> p >> q;
                if(c==1) unionBySize(p,q);
                else moveP(p,q);
            }else{
                cin >> p;
                ll x = find_parent(p);
                cout << _size[x] << " " << sum[x] << endl;
            }
        }
    }
    return 0;
}