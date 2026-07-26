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
    int n , k; cin >> n >> k;
    string a , b; cin >> a >> b;
    vector<int> pos(26 , -1);
    vector<char> ch;
    for(int i=0;i<n;i++){
        if(pos[a[i] - 'a']==-1){
            pos[a[i] - 'a'] = ch.size();
            ch.push_back(a[i]);
        }
    }
    int val = (int)ch.size();
    int cn = min(k , val);
    int maxi = 0;
    for(int cm=0;cm<(1LL<<val);cm++){
         if (__builtin_popcountll(cm) != cn) continue;
        int ans = 0 , temp = 0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i] || (cm & (1<<pos[a[i]-'a']))) temp++;
            else{
                ans+=((temp*(temp+1))/2);
                temp = 0;
            }
        }
        ans+=((temp*(temp+1))/2);
        maxi = max(maxi , ans);

    }
    cout << maxi << endl;
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