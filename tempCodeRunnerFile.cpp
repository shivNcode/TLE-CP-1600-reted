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

int check(vector<int>& temp , int n){
    int l = 0 , r = temp.size()-1;
    int ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(temp[mid]<=n){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ans+1;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    vector<int> temp;
    for(int i=1;i<=2023;i++){
        temp.push_back((i*(i+1))/2);
    }

    cout << endl;
    vector<int> dp(1e6+1 , 0);
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 9+1;
    int val = 1e6;
    for(int i=4;i<=val;i++){
        int n =i;
        // Replace check(temp, n) with:
        auto it = upper_bound(temp.begin(), temp.end(), n);
        int row = distance(temp.begin(), it);

// This returns the count of triangular numbers <= n.


        if(n!=temp[row-1]) row++;
        bool leftE = false;
        bool rightE = false;
        if((row-2>=0 && n-1==temp[row-2])){
            leftE = true;
        }
        if(n==temp[row-1]){
            rightE = true;
        }
        if(leftE){
            dp[n] = (n*n) + dp[n-(row-1)];
        }
        if(rightE){
            dp[n] = (n*n) + dp[n-row];
        }
        else{
            dp[n] = (n*n) + dp[n-row] + dp[n-(row-1)];
        }
    }


    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << dp[x] << endl;

        // int n; cin >> n;

    }

    return 0;
}