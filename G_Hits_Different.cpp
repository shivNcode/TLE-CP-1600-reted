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

void Solve()
{
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 2023;
    int maxi = (row*(row+1))/2;
    vector<int> dp1(maxi , 0) , dp2(maxi, 0);
    dp1[0] = dp2[0] = 1;
    //dp[i] = (i*i) + dp[prevrow]
    int idx = 1;
    for(int r = 1;r<row;r++){
        int prevR = idx - r;
        for(int c = 0;c<=r;c++){
            int val  = (idx+1)*(idx+1);
            dp1[idx] = val + (c>0?dp1[prevR + c - 1]:0);
            dp2[idx] = dp1[idx] + (c<r?dp2[prevR + c]:0);
            idx++;
        }
    }
    //for(int i=0;i<4;i++) cout << dp2[i] << " ";

    int t = 1;
    cin >> t;
    while(t--){
        int n; cin >> n; n--;
        cout << dp2[n] << endl;
    }
    return 0;
}