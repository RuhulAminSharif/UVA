#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;
    while( t-- ) {
        ll a, b; cin >> a >> b;
        if( a < b ) cout << "<" << endl;
        else if( a > b ) cout << ">" << endl;
        else cout << "=" << endl;
    }
    return 0;
}
