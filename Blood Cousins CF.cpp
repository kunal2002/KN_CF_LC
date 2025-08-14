 // Obliviate, Mischief Managed!
// Question Link : https://codeforces.com/contest/208/problem/E
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define int long long
#define ar array
#define ll long long
#define FOR(n) for (int i = 0; i < n; ++i)
#define FOR1(n) for (int ii = 0; ii < n; ++ii)
#define pb(n) push_back(n)
#define rep(i,a,b) for(int i = a;i<b;++i)
#define all(x) x.begin(), x.end()
#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#ifndef ONLINE_JUDGE
#define debug(x) cout<<#x<<" is "<<x<<endl;
#define debugv(v) cout<<#v<< " is :-"<<endl;for(auto it: (v))cout<<it<<" ";cout<<endl;
#define debug2d(v) cout<<#v<< " is :-"<<endl;cn=0;for(auto it: (v)) {cout<<cn<<" => ";cn++; for(auto j:it) cout<<j<<" ";cout<<endl;}
#define pline(x) cout<<x<<" line is reached"<<endl;
#define debugvp(v) cout<<#v<<" is :-"<<endl;for(auto i: v){cout<<"("<<i.ff<<","<<i.ss<<")"<<" ";}cout<<endl;
#define prline cout<<endl;
#define debugpair(p) cout<<#p<<" is ("<<p.ff<<","<<p.ss<<")"<<endl;
#define print(s) cout<<s<<endl;
#else
#define debug(x)
#define debugv(v)
#define debug2d(v)
#define pline(x)
#define debugvp(v)
#define prline
#define debugpair(p)
#define print(s) 
#endif

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
int fastpow(int a, int b)
{
    int res = 1;
    while(b > 0)
    {
        if((b&1))
            res *= a;
        a *= a;
        b = b >> 1;
    }
    return res;
}
int grdways(int n, int m)
{
    if(n == 1 || m == 1)
        return 1;
    return grdways(n-1,m) + grdways(n, m-1);
}
//Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{
  for (auto &it : v)
    cin >> it;
  return istream;
} 

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

// For Kickstart : cout << "Case #" << tt <<": " << ans << "\n";

void init()
{
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
}
ll nCr(int n, int r){
    ll p = 1, k = 1;
    if (n - r < r) r = n - r;
    if(r == 0) return 1;
    while (r) {
        p *= n; k *= r;
        ll m = __gcd(p, k);
        p /= m; k /= m;
        n--; r--;
    }
    return p;
}
int powr(int a, int b)
{
    int res = 1;
    while(b)
    {
        if((b&1))
            res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
}
int mult(int a, int b, int c)
{
    int res = 0;
    while(b)
    {
        if(b&1)
            res = res + a;
        res = res % MOD;
        a = 2 * a;
        a %= MOD;
        b = b >> 1;
    }
    return res;
}
struct BinaryLifter {
    int n, LOG;                 // n = nodes, LOG ~ ceil(log2(n)) + 1
    int root;
    vector<vector<int>> up;     // up[u][i] = 2^i-th ancestor of u (or -1)
    vector<int> depth;          // depth from root
    vector<vector<int>> g;      // adjacency list

    BinaryLifter(int N) : n(N), g(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void preprocess(const vector<int>& roots) {
        // root = R;
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;     // ensure 2^(LOG-1) >= n
        up.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);

        // DFS to fill parent (up[u][0]) and depth
        function<void(int,int)> dfs = [&](int u, int p) {
            up[u][0] = p;
            for (int i = 1; i < LOG; i++) {
                int mid = up[u][i-1];
                up[u][i] = (mid == -1) ? -1 : up[mid][i-1];
            }
            for (int v : g[u]) if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        };
        for(int r : roots)
            dfs(r, -1);
    }

    int kth_ancestor(int u, long long k) const {
        for (int i = LOG - 1; i >= 0 && u != -1; --i) {
            if (k & (1LL << i)) u = up[u][i];
        }
        return u; // -1 if it doesn't exist
    }

    // optional: lowest common ancestor in O(log n)
    int lca(int a, int b) const {
        if (depth[a] < depth[b]) swap(a, b);
        // lift a up to depth b
        int diff = depth[a] - depth[b];
        a = kth_ancestor(a, diff);
        if (a == b) return a;
        // lift both together while their 2^i-ancestors differ
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0]; // parent is LCA
    }

    // jump upward by exactly d steps, but stop at -1 if depth too small
    int jump_to_depth(int u, int target_depth) const {
        if (target_depth > depth[u]) return u;      // no jump needed
        return kth_ancestor(u, depth[u] - target_depth);
    }
};

void solve()
{  
    int n; cin >> n;
    vector<int> vec(n);
    vector<int> par(n);
    vector<int> roots;
    BinaryLifter bin(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
        int p = vec[i];
        if(p == 0)
        {
            par[i] = -1;
            roots.push_back(i);
        }
        else
        {
            --p;
            par[i] = p;
            bin.add_edge(i, p);
        }
    }
    bin.preprocess(roots);
    vector<int> tin(n), tout(n);
    int timer = 0, maxD = 0;
    vector<vector<int>> depthBkt(n); // depthBkt[d] = sorted list of tin's of nodes at depth d
    function<void(int, int)> DFSEuler = [&] (int u, int p) {
        tin[u] = timer++;
        maxD = max(maxD, bin.depth[u]);
        depthBkt[bin.depth[u]].push_back(tin[u]);
        for(int child : bin.g[u])
        {
            if(child != p)
            {
                DFSEuler(child, u);
            }
        }
        tout[u] = timer;
    };
    for(int r : roots)
        DFSEuler(r, -1);

    auto countInSubtreeAtDepth = [&] (int a, int d) -> int {
        if(a == -1) return 0;
        if(d < 0 || (int)depthBkt.size() <= d)
            return 0;
        auto &arr = depthBkt[d];
        int Lb = lower_bound(all(arr), tin[a]) - arr.begin();
        int Rb = upper_bound(all(arr), tout[a] - 1) - arr.begin();
        return Rb - Lb;
    };
    int m; cin >> m;
    while(m--)
    {
        int v, p; cin >> v >> p;
        v--;
        int a = bin.kth_ancestor(v, p);
        if(a == -1)
        {
            cout << 0 << " ";
            continue;
        }
        int d = bin.depth[v];
        int ans = countInSubtreeAtDepth(a, d);
        cout << ans - 1 << " ";
    }
}
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   init();
   clock_t tt = clock();
   int t=1;
    // cin>>t;
//   int i = 1;
   while(t--)
   {
      solve();
   }
   cerr << "RunTime: " << ((double)(clock() - tt) / CLOCKS_PER_SEC);
   return 0;
}
