#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mx = 1e5+10;
ll parent[mx], _rank[mx];
void make_Set(ll n)
{
    for(ll i=0; i<=n; i+=1){
        parent[i] = i;
        _rank[i] = 0;
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
    ll t=1, n; cin >> t;
    while(t-- && cin >> n)
    {
        ll cnt=0, cnt1=0;
        make_Set(n);
        getchar();
        string s;
        while(getline(cin,s) && s!="")
        {
            ll a, b;
            char ch;
            sscanf(s.c_str(), "%c %lld %lld", &ch, &a, &b);
            if(ch=='c')
            {
                unionByRank(a,b);
            }
            else if(ch=='q')
            {
                ll x = find_parent(a), y = find_parent(b);
                if(x==y) cnt++;
                else cnt1++;
            }
        }
        cout << cnt << "," << cnt1 << endl;
        if(t) cout << endl;
    }
    return 0;
}
