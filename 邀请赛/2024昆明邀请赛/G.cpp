//如代码判断条件所示，n==1 || n % 4 == 0时，其总xor==0致使全局失败
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
    cin >> n;
    
    if (n == 1 || n % 4 == 0) {
        cout << "impossible\n";
        return ;
    }

    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if ((cur ^ a[i]) == 0) {
            swap(a[i], a[i + 1]);
        }
        cur ^= a[i];
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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
