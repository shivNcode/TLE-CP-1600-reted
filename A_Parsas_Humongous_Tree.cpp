#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

#define int long long
#define INF (int)1e18
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void dfs(int parent , int child , vector<vector<int>>& dp , vector<vector<int>>& adj ,
vector<pair<int,int>>& prr){
    for(auto it:adj[child]){
        if(it==parent) continue;
        dfs(child , it , dp , adj , prr);
        //dp[i][0] = sumOf(dp[child][0] + |l-i| , dp[child][1] + |r-i|)
        dp[child][0]+=(max(dp[it][0] + abs(prr[child].first - prr[it].first) ,
                            dp[it][1] + abs(prr[child].first - prr[it].second)));
        dp[child][1]+=(max(dp[it][0] + abs(prr[child].second - prr[it].first) ,
                            dp[it][1] + abs(prr[child].second - prr[it].second)));

    }
}


void Solve()
{
    int n; cin >> n;
    vector<pair<int,int>> prr(n+1);
    for(int i=1;i<=n;i++){
        cin >> prr[i].first >> prr[i].second;
    }
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n-1;i++){
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n+1 , vector<int>(2 , 0));
    //dp(parent , child , dp , adj , vis)
    dfs(-1 , 1 , dp , adj , prr);
    cout << max(dp[1][0] , dp[1][1]) << endl;

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