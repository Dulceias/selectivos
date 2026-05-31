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

ll count_swaps(vi s){
    ll n = s.size(), tot = 0;
    if(n / 2 == 1){
        if(s[0] > s[1]) return 1;
        else return 0;
    }

    bool pos = 1;
    forn(i, 1, n) if(abs(s[i]) != abs(s[i - 1])){pos = 0; break;}
    if(pos){
        ll cnt = 0;
        forn(i, 0, n){
            if(s[i] < 0){tot += abs(i - (cnt * 2)); cnt++;}
        } return tot;
    } pos = 1;

    forn(i, 0, n / 2) if(s[i] > 0 || s[i] != -s[i + (n / 2)]){pos = 0; break;}
    if(pos) return ((n / 2) * ((n / 2) - 1)) / 2;

    for(ll i = 0; i < n; i += 2){
        ll idx = 0;
        forn(j, i + 1, n) if(s[j] == -s[i]){idx = j; break;}
        ll a = s[i] > 0 ? 1 : 2;
        fornl(j, idx, i + a){swap(s[j], s[j - 1]); tot++;}
    } return tot;
    
}
