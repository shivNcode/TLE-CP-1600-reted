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
bool check(int val , vector<int>& arr , int k , int n){
    for(int i=0;i<n;i++){
        //cout << i << endl;
        int cost = k;
        int temp = val;
        for(int j=i;j<n;j++){
            //cout << arr[j] << " " << temp << " " << cost << endl;
            if(arr[j]>=temp){
                return true;
            }
            if(j==n-1) continue;
            int s = temp - arr[j];
            //cout << "used " << s << endl;
            cost-=(s);
            //cout << cost << endl;
            if(cost<0) break;
            temp--;
        }
        //cout << endl;
    }
    return false;
}
void Solve()
{
    int n , k; cin >> n >> k;
    int maxi = 0;
    vector<int> arr(n); for(int i=0;i<n;i++){ cin >> arr[i]; maxi = max(maxi , arr[i]);}
    int l = maxi , r = maxi+n;
    int ans = maxi;
    //cout << check(4 , arr , k , n) << endl;
    while(l<=r){
        int mid = (l + r)/2;
        //cout << mid << endl;
       // cout << "checking for mid = " << mid << endl;
        if(check(mid , arr , k , n)){
            //cout << "YES\n";
            //cout << mid << " ";
            ans = max(maxi , mid);
            l = mid+1;
        }
        else{
            //cout << "NO\n";
            r = mid - 1;
        }
    }
    cout << ans << endl;
    // cout << check(4 , arr , k , n) << endl;

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