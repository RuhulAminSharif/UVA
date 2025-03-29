#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
const ll inf = 1e18;
ll node;
vector<vector<ll>> floydWarshall(vector<vector<ll>>& adjMat )
{
    vector<vector<ll>> dist( node + 1, vector<ll> ( node + 1, inf ));
    for( ll i = 1; i <= node; i += 1 ) {
        for( ll j = 1; j <= node; j += 1 ) {
            if( i == j ) dist[i][j] = 0;
            else dist[i][j] = adjMat[i][j];
        }
    }
    for( ll k = 1; k <= node; k += 1 ) {
        for( ll i = 1; i <= node; i += 1 ) {
            for( ll j = 1; j <= node; j += 1 ) {
                if( dist[i][k] < inf && dist[k][j] < inf ) {
                    dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
                }
            }
        }
    }
    return dist;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> node;
    vector<vector<ll>> adjMat( node + 1, vector<ll>( node + 1, inf ) );
    for( ll i = 2; i <= node; i += 1 ) {
        for( ll j = 1; j < i; j += 1 ) {
            string s; cin >> s;
            if( s == "x" ) continue;
            adjMat[i][j] = adjMat[j][i] = stoll(s);
        }
    }
    vector<vector<ll>> dist = floydWarshall( adjMat );
    ll ans = 0;
    for( ll i = 2; i <= node; i += 1 ) {
        ans = max( ans, dist[1][i] );
    }
    cout << ans << endl;
    return 0;
}
