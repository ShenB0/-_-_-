//需要考虑首尾相同
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
    string s;
    cin >> s;
    
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - 1]) {
            rotate(s.begin(), s.begin() + i, s.end());
            break;
        }
    }

    int len = 1;
    ll cnt = 0;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            flag = flag | (len % 2 == 0);
            cnt += len / 2;
            len = 1;
        } else {
            len++;
        }
    }
    flag = flag | (len % 2 == 0);
    cnt += len / 2;

    if (flag && len != n) cnt--;

    cout << cnt << "\n";
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
