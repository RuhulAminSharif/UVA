#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mx = 10005;
ll parent[mx<<1], _rank[mx<<1];
void make_Set()
{
    for(ll i=0; i<(mx<<1); i++){
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    make_Set();
    ll c, x, y;
    while(cin >> c >> x >> y){
        if(c==0 && x==0 && y==0) break;
        if(c==1)/*set friends*/{
            if(find_parent(x)==find_parent(y+n)||find_parent(y)==find_parent(x+n)) cout << -1 << endl;
            else{
                unionByRank(x,y);
                unionByRank(x+n,y+n);
            }
        }
        else if(c==2)/*set enemies*/{
            if(find_parent(x)==find_parent(y) || find_parent(x+n)==find_parent(y+n)) cout << -1 << endl;
            else{
                unionByRank(x,y+n);
                unionByRank(x+n,y);
            }
        }
        else if(c==3)/*are friends?*/{
            if(find_parent(x)==find_parent(y) || find_parent(x+n)==find_parent(y+n)) cout << 1;
            else cout << 0;
            cout << endl;
        }
        else/*are enemies?*/{
            if(find_parent(x)==find_parent(y+n)||find_parent(y)==find_parent(x+n)) cout << 1;
            else cout << 0;
            cout << endl;
        }
    }
    return 0;
}
