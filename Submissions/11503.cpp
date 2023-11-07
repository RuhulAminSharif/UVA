#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mx = 100005;
ll parent[mx], _size[mx];
void make_Set(ll n)
{
    for(ll i=0; i<=n; i++){
        parent[i] = i;
        _size[i] = 1;
    }
}
ll find_parent(ll x)
{
    if(parent[x]==x) return x;
    return parent[x] = find_parent(parent[x]);
}
ll unionBySize(ll u, ll v)
{
    ll x = find_parent(u);
    ll y = find_parent(v);
    if(x==y){
        return _size[x];
    }
    else if(_size[x]<_size[y]){
        parent[x] = y;
        _size[y] += _size[x];
        return _size[y];
    }
    else{
        parent[y] = x;
        _size[x] += _size[y];
        return _size[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1; cin >> t;
    while(t--){
        ll f; cin >> f;
        make_Set(f);
        map<string, ll>mpp;
        ll k=0;
        while(f--){
            string a, b; cin >> a >> b;
            if(mpp[a]==0){
                mpp[a] = ++k;
            }
            if(mpp[b]==0){
                mpp[b] = ++k;
            }
            cout << unionBySize(mpp[a], mpp[b]) << endl;
        }
    }
    return 0;
}
