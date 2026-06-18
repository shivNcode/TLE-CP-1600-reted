#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define int long long
#define INF (int)1e18
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
vector<int> depth;
int total = 0;
int x = -1;
vector<int> ans;
int dfs(int node , vector<vector<int>>& adj , vector<int>& vis , vector<int>& dist){
    //cout << node << endl;
    // if(adj[node].size()==0) {
    //     cout << node << endl;
    //     return 0;
    // }
    x++;
    vis[node]=1;
    for(auto it: adj[node]){
        if(vis[it]==0){
             dist[node]+=(1 + dfs(it , adj , vis , dist));
        }
    }

    //cout <<node << " " << x - dist[node] << endl;
    ans[node]=(x-dist[node]);
    x--;
    return dist[node];
}

void Solve()
{
    int n , k; cin >> n >> k;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u , v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist( n , 0);
    vector<int> vis( n , 0);
    vis[0] = 1;
    ans.assign(n , 0);
    dist[0] = dfs(0 , adj , vis , dist);
    for(int i=0;i<n;i++){
        //cout<< i << " " << dist[i] << "\n";
    }
    sort(ans.begin() , ans.end() , greater<int>());
    total = 0;
    for(int i=0;i<k;i++){
        total+=ans[i];

    }
    cout << total << endl;


}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}