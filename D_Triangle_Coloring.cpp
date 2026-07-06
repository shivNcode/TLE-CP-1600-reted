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
const int MOD = 998244353;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;

    vector<int> fact(n + 1), invFact(n + 1);
    fact[0] = 1;

    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[n] = power(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--)
        invFact[i - 1] = invFact[i] * i % MOD;

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void Solve()
{
    int n; cin >> n;
    vector<int> w(n);
    int sum = 1;
    for(int i=1;i<=n;i++){
        cin >> w[i-1];
        if(i%3==0){
            int p = i-1;
            int a = w[p];
            int b = w[p-1];
            int c = w[p-2];
            int val = 1;
            if(a==b && b==c){
                val = 3;
            }
            else if(a==b || a==c || b==c){
                if(a==b){
                    if(a>c){
                        val = 1;
                    }
                    else val = 2;
                }
                else if(b==c){
                    if(b>a) val = 1;
                    else val = 2;
                }
                else if(a==c){
                    if(a>b) val = 1;
                    else val = 2;
                }

            }
            //cout << val << endl;
            sum = sum * val % MOD;
        }
    }
   //int v = n/3;
    n= n/3;
    sum = sum * nCr(n, n / 2) % MOD;
    cout << sum << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}