#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mx = 5*1e3+10;
ll c, r;
string s[mx];
map<string, string>parent;
map<string, ll>_size;
void make_Set()
{
    parent.clear();
    _size.clear();
    for(ll i=0; i<c; i+=1){
        parent[s[i]]=s[i];
        _size[s[i]]=1;
    }
}
string find_parent(string s)
{
    if(parent[s]==s) return s;
    return parent[s] = find_parent(parent[s]);
}
void unionBySize(string u, string v)
{
    string x = find_parent(u);
    string y = find_parent(v);
    if(x!=y){
        if(_size[x]==_size[y]){
            parent[y] = x;
            _size[x] += _size[y];
        }else if(_size[x]<_size[y]){
            parent[x] = y;
            _size[y] += _size[x];
        }else{
            parent[y] = x;
            _size[x] += _size[y];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> c >> r && c)
    {
        for(ll i=0; i<c; i++){
            cin >> s[i];
        }
        make_Set();
        for(ll i=0; i<r; i+=1){
            string a, b; cin >> a >> b;
            unionBySize(a,b);
        }
        ll mx = 0;
        for(auto it : _size){
            mx = max(it.second, mx);
        }
        cout << mx << endl;
        cin.ignore();
    }
    return 0;
}
