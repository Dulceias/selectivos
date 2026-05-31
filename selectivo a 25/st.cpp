#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
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
#define forn(i, x, n) for (int i = x; i < n; i++)
 
vl st[900000], a[200000];

void build(ll nivel, ll l, ll r){
    if(l == r){
        st[nivel] = a[l];
        return;
    }

    ll m = (l + r) / 2, news = nivel * 2;
    build(news, l, m);
    build(news + 1, m + 1, r);
    st[nivel] = st[news] + st[news + 1];
}

void update(ll nivel, ll l, ll r, ll x, ll v){
    if(l == r){
        a[l] = v;
        st[nivel] = a[l];
        return;
    }

    ll m = (l + r) / 2, news = nivel * 2;

    if(x > m){
        update(news + 1, m + 1, r, x, v);
    } else {
        update(news, l, m, x, v);
    }
    st[nivel] = st[news] + st[news + 1];
}

ll query(ll nivel, ll l, ll r, ll x, ll y){
    if(x >= l && r <= y) return st[nivel];
    if(l > y || r < x) return 0;

    ll m = (l + r) / 2, news = nivel * 2;
    ll izq = query(news, l, m, x, y);
    ll der = query(news + 1, m + 1, r, x, y);
    return izq + der;
}

void solve() {
    ll n;
    cin >> n;

    forn(i, 0, n){
        cin >> a[i];
    }

    build(1, 1, n);

    ll q;
    cin >> q;
    while(q--){
        ll c, a, b;
        cin >> c >> a >> b;
        if(c == 1){
            update(1, 1, n, a, b);
        } else {
            cout << query(1, 1, n, a, b) << endl;
        }
    }

}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}