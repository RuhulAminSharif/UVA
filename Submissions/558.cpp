#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
#define inf 1e18
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;
    while( t-- ) {
        ll n, m; cin >> n >> m;
        vector<vector<ll>>edges( m, vector<ll>( 3 ) );
        for( ll i = 0; i < m; i += 1 ) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }
        vector<ll> dist( n, inf );
        dist[0] = 0LL;
        bool hasCycle = false;
        ll cycleNode = -1;
        for( ll i = 1; i <= n; i += 1 ) {
            for( ll j = 0; j < m; j += 1 ) {
                ll u = edges[j][0];
                ll v = edges[j][1];
                ll w = edges[j][2];
                if( dist[u] + w < dist[v] ) {
                    dist[v] = dist[u] + w ;
                    if( i == n ) {
                        hasCycle = true;
                    }
                }
            }
        }
        if( hasCycle ) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
    return 0;
}
