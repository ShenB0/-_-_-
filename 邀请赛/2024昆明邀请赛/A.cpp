//记得考虑si==si-1
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

struct state{
    ll s, val, id;

    bool operator < (const state& st) const {
        if (s != st.s) {
            return s < st.s;
        } else if (val != st.val) {
            return val < st.val;
        } else {
            return id < st.id;
        }
    }
};

void init(){
    
}

void solve(){
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<vector<ll>> a(n, vector<ll>(m));
    vector<ll> c(n, 0);
    vector<state> v(n);
    for (int i = 0; i < n; i++){
        v[i] = {0, 0, i};
        cin >> v[i].s;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            
            if (a[i][j] == -1) c[i]++;
            else v[i].val += a[i][j];
        }
    }

    sort(v.begin(), v.end());

    int id0 = v[0].id;
    for (int i = 0; i < m; i++) {
        if (a[id0][i] == -1) {
            a[id0][i] = 0;
        }
    }
    
    for (int i = 1; i < n; i++) {
        auto [s, val, id] = v[i];
        
        if (val > v[i - 1].val) {
            for (int j = 0; j < m; j++) {
                if (a[id][j] == -1) {
                    a[id][j] = 0;
                }
            }
        } else {
            ll d = v[i - 1].val - val + (v[i - 1].s == s ? 0 : 1);
            ll cnt = d / k;
            ll rem = d % k;

            if (c[id] < cnt + (rem == 0 ? 0 : 1)) {
                cout << "No\n";
                return ;
            }

            int cur = 0;
            for (int j = 0; j < m; j++) {
                if (a[id][j] == -1) {
                    if (cur < cnt) {
                        a[id][j] = k;
                    } else if (cur == cnt) {
                        a[id][j] = rem;
                    } else {
                        a[id][j] = 0;
                    }
                    cur++;
                }
            }

            v[i].val = v[i - 1].val + (v[i - 1].s == s ? 0 : 1);
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
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
