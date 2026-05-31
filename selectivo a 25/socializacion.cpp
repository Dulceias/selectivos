#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;
 
#define F first
#define S second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back
#define tt int t; cin >> t
#define cout(x) cout << x << endl
#define forn(i, x, n) for (int i = x; i < int(n); i++)

ll n;

struct dsu{
    vl padres;
    dsu(ll n){
        padres.resize(n + 1);
        forn(i, 0, n) padres[i] = i;
    }

    ll find(ll a){
        if(padres[a] == a) return a;
        return padres[a] = find(padres[a]);
    }

    bool onion(ll x, ll y){
        ll a = find(x);
        ll b = find(y);

        if(a == b) return true;
        padres[b] = a;
        return false;
    }
};

void solve() {
    ll m;
    cin >> n >> m;

    map<string, int> mp;
    vii connects;
    ll num = 0;

    dsu connect(n);

    forn(i, 0, m){
        string a, b;
        cin >> a >> b;
        
        if(mp.find(a) == mp.end()){
            mp[a] = num;
            num++;
        }

        if(mp.find(b) == mp.end()){
            mp[b] = num;
            num++;
        }

        pii p;
        p.F = mp[a];
        p.S = mp[b];
        connects.pb(p);
    }

    for(auto p : connects){
        connect.onion(p.F, p.S);
    }

    ll padre = connect.find(0);
    bool pos = 1;

    forn(i, 0, n){
        if(connect.find(i) != padre){
            pos = 0;
            break;
        }
    }

    if(pos) cout << "SI" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    tt;
    while(t--) solve();
    return 0;
}

/*
ll conex = 0;
map<int, string> mp;

getline(cin, s);

for(auto c : s){
    if(c == " ") break;
    else{
        s1 += c;
    }
}
forn(i, s1.size() - 1, s.size()){
    s2 += s[i];
}
*/