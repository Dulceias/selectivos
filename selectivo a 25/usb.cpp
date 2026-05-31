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
 
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll n;
    cin >> n;
    
    vector<pair<int, string> > vp;
    vp.resize(n + 1);

    forn(i, 0, n){
        cin >> vp[i].F >> vp[i].S;
    }

    sort(vp.begin(), vp.end());

    ll pc = 0, tot = 0;

    for(auto p : vp){
        if(p.S == "USB" && a > 0){
            tot += p.F;
            a--;
            pc++;
        } else if(p.S == "USB" && c > 0){
            tot += p.F;
            c--;
            pc++;
        }

        if(p.S == "PS/2" && b > 0){
            tot += p.F;
            b--;
            pc++;
        } else if(p.S == "PS/2" && c > 0){
            tot += p.F;
            c--;
            pc++;
        }
    }

    cout << pc << " " << tot;
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}