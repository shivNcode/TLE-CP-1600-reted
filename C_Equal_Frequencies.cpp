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

bool cmp(pair<char,int>& a , pair<char , int>& b){
    if(a.second!=b.second) return a.second<b.second;
    return a.first<b.first;
}

void Solve()
{
    int n; cin >> n;
    string str; cin >> str;
    vector<pair<char,int>> arr(26 , {'0' , 0});
    for(int i=0;i<26;i++){
        arr[i].first = i + 'a';
    }

    for(int i=0;i<n;i++){
        char ch = str[i];
        arr[ch - 'a'].first = str[i];
        arr[ch - 'a'].second++;
    }
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
    if(a.second != b.second) return a.second > b.second;
    return a.first < b.first;
});
    for(int i = 0;i<26;i++){
       // cout << arr[i].first << " " << arr[i].second << endl;
    }
    int ans = n ,  c = 0 , unchange = n;
    for(int k = 1;k<=26;k++){
         if(n % k) continue;
        unchange = 0;
        for(int i=0;i<k;i++){
            unchange+=(min(n/k , arr[i].second));
        }
        if(n - unchange < ans){
            c = k;
            ans = n - unchange;
        }
    }
    cout << ans << endl;
    // if(ans==0){
    //     cout << str << endl;
    //     return;
    // }
    map<char,int> mpp;
    string t(n , ' ');
    for(int i=0;i<c;i++){
        //cout << arr[i].first <<" " << n/ans << endl;
        mpp[arr[i].first] = n/c;
    }

    for(int i=0;i<n;i++){
        if(mpp[str[i]]>0){
            t[i] = str[i];
            mpp[str[i]]--;
        }
    }
    for(int i=0;i<n;i++){
        if(t[i]!=' ') continue;
        while(!mpp.empty() && (*mpp.begin()).second == 0 ) mpp.erase(mpp.begin());
        t[i] = (*mpp.begin()).first;
        mpp[(*mpp.begin()).first]--;
    }

    cout << t << endl;



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