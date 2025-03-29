#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
#define inf 1e18
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, test = 0;
    while( cin >> n >> m && (n+m) ) {
        cout << "Scenario #" << ++test << endl;
        cout << "Minimum Number of Trips = ";
        vector<vector<pair<ll,ll>>> adj( n + 1 );
        for( ll i = 1; i <= m; i += 1 ) {
            ll u, v, w; cin >> u >> v >> w;
            adj[u].push_back( {v,w} );
            adj[v].push_back( {u,w} );
        }
        ll src, dst, tourist; cin >> src >> dst >> tourist;
        vector<ll> cap( n + 1, 0 );
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push( {inf, src} );
        cap[src] = inf;
        while( pq.size() > 0 ) {
            ll node = pq.top().second;
            ll currCap = pq.top().first;
            pq.pop();
            for( auto it : adj[node] ) {
                ll adjNode = it.first;
                ll adjCap = it.second;
                ll nextCap = min( currCap, adjCap );
                if( nextCap > cap[adjNode] ) {
                    cap[adjNode] = nextCap;
                    pq.push( { nextCap, adjNode } );
                }
            }
        }
        cout << ( tourist + cap[dst] - 2 ) / (cap[dst]-1) << endl;
        cout << endl;
    }
    return 0;
}
