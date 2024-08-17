#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t; cin >> t;
    while( t-- ) {
        ll n; cin >> n;
        ll p; cin >> p;
        vector<ll> v(p);
        for( ll i = 0; i < p; i += 1 ) cin >> v[i];
        bool fg = false;
        for( ll i = 0; i < ( 1 << p); i += 1 ) {
            ll sum = 0;
            for( ll j = 0; j < p; j += 1 ) {
                if( i & ( 1 << j) ) {
                    sum += v[j];
                }
            }
            if( sum == n ) {
                fg = true;
                break;
            }
        }
        if( fg ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
