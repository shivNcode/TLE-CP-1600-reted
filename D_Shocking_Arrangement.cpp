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
    int nt; cin >> nt;
    vector<int> arr(nt) , pos , neg;
    int mini = 1e9 , maxi = -1e9;
    for(int i=0;i<nt;i++){
        cin >> arr[i];
        if(arr[i]>=0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
        mini = min(mini , arr[i]);
        maxi = max(maxi , arr[i]);
    }
    int val = maxi - mini;
    sort(pos.begin() , pos.end() , greater<int>());
    sort(neg.begin() , neg.end());
    int sum = 0;
    //cout << val ;
    vector<int> ans;
    int p = 0 , n = 0;
    while(p<pos.size() && n<neg.size()){
        //cout << sum << endl;
        //cout << "1";
        if(abs(sum+pos[p])<val){
            sum+=pos[p];
            ans.push_back(pos[p]);
            p++;
            //cout << "1\n";
        }
        else if(abs(sum + neg[n])<val){
            ans.push_back(neg[n]);
            sum+=neg[n];
            n++;
            //cout << "2\n";
        }
        else{
            cout << "NO\n";
            return;

        }
    }
    while(n<neg.size()){
        sum+=neg[n];
        ans.push_back(neg[n]);
        n++;
    }
    while(p<pos.size()){
        sum+=pos[p];
        ans.push_back(pos[p]);
        p++;
    }
    if(sum<val){
        cout << "YES\n";
        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << endl;
    }
    else cout << "NO\n";


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