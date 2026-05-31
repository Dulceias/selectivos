#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;

#define mod 1000000007
#define inf 10000000000000
#define F first
#define S second
#define nd '\n'
#define forn(i, x, n) for (ll i = x; i < ll(n); i++)
#define fornl(i, x, n) for(ll i = x; i >= ll(n); i--)
#define cina(x) for(auto &c : x) cin >> c;
#define cingra(x, y, n) forn(i, y, n){ll a, b; cin >> a >> b; a--; b--; x[a].pb(b); x[b].pb(a);}
#define cingraw(x, y, n) forn(i, y, n){ll a, b, c; cin >> a >> b >> c; a--; b--; x[a].pb({b, c}); x[b].pb({a, c});}
#define fnd(x, y) find(x.begin(), x.end(), y)
#define srt(x) sort(x.begin(), x.end())
#define debug(x) cout << #x << " = " << x << nd;
#define debugv(x, s) cout << #x << " = "; forn(i, 0, s) cout << x[i] << " "; cout << nd;
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define freop(in, out) freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#define rmod(a, b) (a % mod - b % mod + mod) % mod
#define smod(a, b) (a % mod + b % mod) % mod
#define mmod(a, b) (a % mod) * (b % mod) % mod
#define yes cout << "YES" << nd
#define no cout << "NO" << nd
#define pb push_back
#define all(x) x.begin(), x.end()

vl mosaic(vi x, vi y, vi t, vi b, vi l, vi r){
    ll n = x.size(), q = t.size();
    vvl mat(n, vl(n, 0)), pref(n + 1, vl(n + 1, 0));
    forn(i, 0, n) mat[0][i] = x[i];
    forn(i, 0, n) mat[i][0] = y[i];

    forn(i, 1, n){
        forn(j, 1, n){
            if(!mat[i - 1][j] && !mat[i][j - 1]) mat[i][j] = 1;
        }
    }

    forn(i, 1, n + 1){
        forn(j, 1, n + 1){
            pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j]
                        + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    vl sum;
    forn(k, 0, q){
        ll tot = pref[b[k] + 1][r[k] + 1] - pref[t[k]][r[k] + 1]
                - pref[b[k] + 1][l[k]] + pref[t[k]][l[k]];
        sum.pb(tot);
    }
    return sum;
}

/*
if(n <= 200 && q <= 200){
    vvl mat(n, vl(n, 0));
    forn(i, 0, n) mat[0][i] = x[i];
    forn(i, 0, n) mat[i][0] = y[i];

    forn(i, 1, n){
        forn(j, 1, n){
            if(!mat[i - 1][j] && !mat[i][j - 1]) mat[i][j] = 1;
        }
    }

    vl sum;
    forn(k, 0, q){
        ll tot = 0;
        forn(i, t[k], b[k] + 1){
            forn(j, l[k], r[k] + 1) tot += mat[i][j];
        }
        sum.pb(tot);
    }
    return sum;
}
*/

/*
vl mat(n, 0), tot;
mat[0] = x[0];
forn(i, 1, n) mat[i] = mat[i - 1] + x[i];

forn(i, 0, q){
    tot.pb(l[i] == 0 ? mat[r[i]] : mat[r[i]] - mat[l[i] - 1]);
} return tot;
*/

/*
vl unx(n), uny(n);
vl tot, dox(n), doy(n);

uny[0] = x[1];
uny[1] = !x[1] && !y[1] ? 1 : 0;
forn(i, 2, n) uny[i] = !uny[i - 1] && !y[i] ? 1 : 0;

unx[0] = y[1];
unx[1] = !x[1] && !y[1] ? 1 : 0;
forn(i, 2, n) unx[i] = !unx[i - 1] && !x[i] ? 1 : 0;

if(n > 2){
    dox[2] = !unx[2] && !uny[2] ? 1 : 0;
    doy[2] = dox[2];

    forn(i, 3, n) dox[i] = !dox[i - 1] && !unx[i] ? 1 : 0;
    forn(i, 3, n) doy[i] = !doy[i - 1] && !uny[i] ? 1 : 0;
}

forn(i, 0, q){
    ll a = t[i], b = l[i];
    if(!a) tot.pb(x[b]);
    else if(!b) tot.pb(y[a]);
    else if(a == 1) tot.pb(unx[b]);
    else if(b == 1) tot.pb(uny[a]);
    else{
        if(a == b) tot.pb(dox[2]);
        else if(a > b) tot.pb(doy[a - b + 2]);
        else tot.pb(dox[b - a + 2]);
    }
}

return tot;
*/