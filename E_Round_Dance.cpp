#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
using namespace std;

#define int long long
#define INF (int)1e18
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
vector<int> mark;
bool cycle = false;
void dfs(int node, int parent,
         vector<vector<int>>& adj,
         vector<int>& vis)
{
    vis[node] = 1;
    mark[node] = 1;

    for(auto child : adj[node]){
        if(!vis[child]){
            dfs(child, node, adj, vis);
        }
        else if(mark[child] && child != parent){
            cycle = true;
        }
    }

    mark[node] = 0;
}
struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()((p.first << 32) ^ p.second);
    }
};

void Solve()
{
    int n; cin >> n;
    set<pair<int,int>> st;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        if(!st.count({i,x}) && !st.count({x , i})){
            st.insert({i , x});
            st.insert({x , i});

            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    int maxi = 0;
    int mini = 0;
    // for(int i=1;i<=n;i++){
    //     cout << i << " : ";
    //     for(int j :adj[i]) cout << j << " ";
    //     cout << endl;
    // }
    vector<int> vis(n+1 , 0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            //cout << i << endl;
            cycle = false;
            mark.resize(n+1 , 0);
            dfs(i , -1 , adj , vis);
            //cout << endl;
            if(cycle){
                //cout << "yes\n";
                mini++;
            }
            else{
                //cout << "no\n";
                maxi++;
            }
        }
    }
    cout << ((maxi==0)?(mini):(mini+1)) << " " << maxi+mini << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}