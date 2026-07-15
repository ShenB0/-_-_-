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
const int N = 2e5 + 10;

void init(){
    
}

void solve(){
    int n;
    ll k, m;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;

    ll tot = 0;
    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = k - a[i] % k;
        tot += a[i] / k;
    }

    sort(d.begin(), d.end());

    for (int i = 0; i < n; i++) {
        if (d[i] > 0 && (m - d[i]) >= 0) {
            tot++;
            m -= d[i];
        } else {
            break;
        }
    }

    tot += m / k;

    cout << tot << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();

    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
