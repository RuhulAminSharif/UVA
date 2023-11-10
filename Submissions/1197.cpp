#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mx = 1e5+5;
vector<int> adj[mx];
vector<bool>vis(mx);
ll ans;
void dfs(int node)
{
    vis[node] = true;
    ans++;
    for(auto x : adj[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    while(cin >> n >> m){
        if(n==0 && m==0) break;
        for(ll i=0; i<n; i++){
            adj[i].clear();
            vis[i] = false;
        }
        for(ll i=0; i<m;i++){
            ll k, x, y; cin >> k >> x;
            for(ll j=1; j<k; j++){
                cin >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }
        ans = 0;
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
