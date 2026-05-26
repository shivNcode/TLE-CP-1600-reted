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
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    //cout << n << endl;
    string temp = s;
    sort(temp.begin() , temp.end() , greater<char>());
    //cout << temp << endl;
    int val = n;
    int cnt = 0;
    while(k-val>0){
        k-=val;
        val--;
        cnt++;
    }
   // cout << cnt << endl;
    map<char,int> mpp;
    for(int i=0;i<cnt;i++){
        mpp[temp[i]]++;
    }
    //cout << k << endl;
    for(int i=0;i<n;i++){
       // cout << s[i] << " ";
        if(k==0 && mpp[s[i]]<=0){
            cout << s[i];
            //cout << "got " <<endl;
            break;
        }
        if(mpp[s[i]]>0){
            //cout << 1 << " "<< endl;

            mpp[s[i]]--;
        }else{
             //cout << 2 << " " <<endl;
            k--;
        }
        if(k==0 && mpp[s[i]]<=0){
            cout << s[i];
            //cout << "got " <<endl;
            break;
        }
    }
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
   // cout << endl;

    return 0;
}
