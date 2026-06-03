#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define int long long
#define INF (int)1e18
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    string str;
    cin >> str;

    int k;
    cin >> k;

    int len = str.size();

    int cnt = 0;
    int cur = len;

    while (k - cur > 0)
    {
        k -= cur;
        cur--;
        cnt++;
    }

    string ans;
    stack<char> st;

    for (char ch : str)
    {
        while (!st.empty() && cnt > 0 && st.top() > ch)
        {
            st.pop();
            cnt--;
        }

        st.push(ch);
    }

    while (cnt > 0)
    {
        st.pop();
        cnt--;
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(all(ans));

    cout << ans[k - 1];
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