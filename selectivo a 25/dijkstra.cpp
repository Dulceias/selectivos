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
 
vector<vpl> graph;
vl dist;
ll inf = 1e18;

void dijkstra(ll nodo){
    priority_queue<pll> pq;
    pq.push({0, nodo});
    dist[nodo] = 0;

    while(!pq.empty()){
        ll nodoAct = pq.top().S;
        ll pesoAct = -pq.top().F;

        if(dist[nodoAct] != pesoAct) continue;

        for(auto vecino : graph[nodoAct]){
            ll nodoVecino = vecino.F;
            ll pesoArista = vecino.S;

            if(dist[nodoAct] + pesoArista < dist[nodoVecino]){
                dist[nodoVecino] = dist[nodoAct] + pesoArista;
                pq.push({-dist[nodoVecino], nodoVecino});
            }
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    
    graph.assign(n + 1, vpl());
    dist.assign(n + 1, inf);

    forn(i, 0, m){
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].pb({b, c});
    }

    dijkstra(0);

    forn(i, 0, n){
        cout << dist[i] << " ";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}