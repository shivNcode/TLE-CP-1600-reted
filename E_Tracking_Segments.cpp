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
bool check(int v , int n , vector<pair<int,int>>& prr , vector<int>& que){
    vector<int> arr(n);
    for(int i=0;i<v;i++){
        arr[que[i]-1] = 1;
    }
    vector<int> pre(n+1 , 0);
    for(int i=0;i<n;i++){
         pre[i + 1] = pre[i] + arr[i];
    }
    int m = prr.size();
    for(int i=0;i<m;i++){
        int l = prr[i].first;
        int r = prr[i].second;
        int ones = pre[r] - pre[l-1];
        int len  = r - l + 1;

        if(ones > len/2)
            return true;
    }
    return false;
}
void Solve()
{
    int n , m ; cin >> n >> m;
    vector<pair<int,int>> prr(m);
    for(int i=0;i<m;i++){
        cin >> prr[i].first >> prr[i].second;
    }
    int q ; cin >> q;
    vector<int> que(q);
    for(int i =0 ;i<q;i++){
        cin >> que[i];
    }
    int l = 0, r = q;
int ans = -1;

while(l <= r){
    int mid = (l + r) / 2;

    if(check(mid, n, prr, que)){
        ans = mid;
        r = mid - 1;
    }
    else{
        l = mid + 1;
    }
}

cout << ans << '\n';
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