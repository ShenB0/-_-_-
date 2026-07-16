#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define ALL(x) (x).begin(), (x).end()

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N = 3e5 + 10;

ll a[N], pref[N], suf[N], diff[N];

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << abs(a[1] + k) << "\n";
        return ;
    }

    // 初始化前缀，包含边界 pref[0] = 0
    pref[0] = 0;
    pref[1] = abs(a[1]); // 加上 abs
    for (int i = 2; i <= n; i++) {
        pref[i] = __gcd(pref[i - 1], abs(a[i])); // 加上 abs
    }

    // 初始化后缀
    suf[n + 1] = 0;
    suf[n] = abs(a[n]); // 加上 abs
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = __gcd(suf[i + 1], abs(a[i])); // 加上 abs
    }

    // 初始化差分
    for (int i = 1; i < n; i++) {
        diff[i] = abs(a[i] - a[i + 1]);
    }

    ll mx = pref[n];// 不取任何区间
    vector<ll> g; // 仅维护与 l 相关的部分：gcd(pref[l-1], diff[l...r-1])
    
    for (int r = 1; r <= n; r++) {
        vector<ll> ng;
        
        ng.push_back(pref[r - 1]);
        
        if (r > 1) {
            for (ll v : g) {
                ng.push_back(__gcd(v, diff[r - 1]));
            }
        }
        
        sort(ng.begin(), ng.end());
        ng.erase(unique(ng.begin(), ng.end()), ng.end());
        g = ng;
        
        ll G = __gcd(abs(a[r] + k), suf[r + 1]);
        for (ll v : g) {
            mx = max(mx, __gcd(v, G));
        }
    }

    cout << mx << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
