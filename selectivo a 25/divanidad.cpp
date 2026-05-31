#include <bits/stdc++.h>
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
 
vvl graph;
vl vis;
vl dist;
ll inf = 1e18;

void bfs(ll nodo){
    queue<ll> q;
    q.push(nodo);
    dist[nodo] = 0;

    while(!q.empty()){
        ll nodoAct = q.front();
        vis[nodoAct] = 1;
        q.pop();

        for(auto vecino : graph[nodoAct]){
            if(!vis[vecino]){
                dist[vecino] = dist[nodoAct] + 1;
                q.push(vecino);
            }
        }
    }
}


void solve() {
    ll n, q;
    cin >> n >> q;
    
    graph.assign(n + 1, vl());
    
    forn(i, 0, n - 1){
        ll a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    forn(i, 0, q){
        dist.assign(n + 1, 0);
        vis.assign(n + 1, 0);

        ll x, y;
        cin >> x >> y;
        
        bfs(x);
        cout << dist[y] << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}