#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
 // write solution here.
 int n; cin >> n;
 vector<int> arr(n+1);
 for(int i=1;i<=n;i++){
     cin >> arr[i];
 }
 vector<bool> dp(n + 2 , false);
 dp[0] = dp[n+1] = true;
 for(int i=1;i<=n;i++){
     if(i+arr[i]+1<=n+1){
         dp[i] = dp[i+1+arr[i]] | dp[i];
     }
     if(i-arr[i]-1>=0){
         dp[i] = dp[i-arr[i]-1] | dp[i];
     }
     //cout << i << " " << arr[i] << " " << dp[i] << endl;
 }
 for(int i=n;i>=0;i--){
    if(i+arr[i]+1<=n+1){
         dp[i] = dp[i+1+arr[i]] | dp[i];
     }
     if(i-arr[i]-1>=0){
         dp[i] = dp[i-arr[i]-1] | dp[i];
     }
 }
 int cnt = 0;
 int i=1;
 while(i<=n && dp[i]==true){
     i++;
 }
 while(i<=n){
     if(dp[i] == true){
         cnt++;
     }
     i++;
 }
 if(dp[n]==false) cnt ++;
//  for(int i=1;i<=n;i++){
//     if(dp[i]==true){
//         cout << "YES\n";return;
//     }
//  }
//  cout << "NO\n";return;
for(int i=1;i<=n;i++){
    cout << dp[i] << " ";
}
cout << endl;
 cout << cnt << endl;


}

int32_t main(){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);

 	int t = 1;
 	cin >> t;
 	while (t--){
	 Solve();
 	}

	 return 0;
}

/*
Notes:

*/
