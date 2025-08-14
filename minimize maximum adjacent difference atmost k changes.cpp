 // Obliviate, Mischief Managed!
// question : https://x.com/Resorcinolworks/status/1955983749012971764
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
bool check(vector<int>& vec, vector<int>& sortedels, int mid, int k)
{
    int n = vec.size(), m = sortedels.size();
    // create the left and right max possible thresholds for every element in sortedels
    // meaning, if we are going to put sortedels[j] at the current idx i, then the prev idx (i - 1) must 
    // be in the threshold [sortedels[j] - mid, sortedels[j] + mid], we do reverse of this in the actual for loop because we are calculating future from past but the logic holds
    // now we are going to create the dp such that we will take the cheapest paints it takes to create 
    // a valid array with the threshold condx satisfied till i - 1, and using that we will fill our present idx dp
    // to do this we will create a deque which will store the minimum repainting necessary within the limits of the threshold
    // i.e. [sortedels[j] - mid, sortedels[j] + mid]
    vector<int> left(m), right(m);
    int l = 0;
    for(int i = 0; i < m; i++)
    {
        while(l < m && (sortedels[i] - mid) > sortedels[l])
            l++;
        left[i] = l;
    }
    int r = m - 1;
    for(int i = m - 1; ~i; i--)
    {
        while(r >= 0 && (sortedels[i] + mid) < sortedels[r])
            r--;
        right[i] = r;
    }

    // now we will create the dp, it will be 2 rows, storing the prev and the curr state
    // the prev state will convey the best cost of repainting, it will naturally be of size m, 
    // the only thing to do now is to go for each element in the original array, substitue it with all the
    // original array values, check for all the values that might be in the threshold of the value we are substituting sortedels[j], i.e. [sortedels[j] - mid, sortedels[j] + mid]
    // fetch the best prev value we can find in that range, which corresponds to the best chances of repainting under <= k changes condx
    // and just add 1 if the current vec[i] value is not equal to the sortedels[j], if it's equal, just fill the curr dp with min of all valid prev fetched

    // we will use deque here to maintain the smallest prev cost possible in [sortedels[j] - mid, sortedels[j] + mid] , otherwise it will take another loop of possibly
    // O(m) and we are already having O(n * m), so it will go O(n * m * m) which i think will give TLE under the n <= 2000 constraints

    // Let's fill the best repainting cost possible for the first element as it doesn't have any element before it
    vector<int> prevdp(m), currdp(m);
    for(int i = 0; i < m; i++)
        prevdp[i] = (vec[0] == sortedels[i] ? 0 : 1);

    // now we will use this base case prev dp to fill the curr dp
    for(int i = 1; i < n; i++)
    {
        deque<int> dq;
        int fillR = -1;
        // substituting all original elements in vec
        for(int j = 0; j < m; j++)
        {
            // push all elements possible till right[j] i.e. the element till which the threshold allows 
            while(fillR < right[j])
            {
                fillR++;
                // kinda keeping a sliding window to keep the minimum prev cost at front, 
                // and deleting any element if found a better lower cost in the subsequent elements
                if(!dq.empty() && prevdp[dq.back()] >= prevdp[fillR])
                    dq.pop_back();
                dq.push_back(fillR);
            }
            // now we pushed elements from 0 to right[j] keeping a somewhat monotonical order in deque, now shrink it till left[j]
            // as we can't choose from elements lower than left[j] idx
            while(!dq.empty() && dq.front() < left[j])
                dq.pop_front();
            int repaintCost = (vec[i] == sortedels[j] ? 0 : 1);
            currdp[j] = prevdp[dq.front()] + repaintCost;
        }
        prevdp = currdp;
    }
    // the minimum cost after traversing through all elements in the original array and propagating the cheapest
    // cost to repaint, if it's under k element changes, then yes, this threshold is valid, otherwise no
    auto it = *min_element(all(prevdp));
    return (it <= k);
}
void solve()
{  
    int n, k; cin >> n >> k;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    vector<int> sortedels(vec);
    sort(all(sortedels));
    sortedels.erase(unique(all(sortedels)), sortedels.end());
    // do binary search on the minimum maximum diff possible 
    int lo = 0, hi = sortedels[sortedels.size() - 1] - sortedels[0];
    int ans = -1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(check(vec, sortedels, mid, k))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << "\n";
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
