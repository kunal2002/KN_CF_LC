 // Obliviate, Mischief Managed!
#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define int long long
#define ar array
#define ll long long
#define FOR(n) for (int i = 0; i < n; ++i)
#define FOR1(n) for (int ii = 0; ii < n; ++ii)
#define pb(n) push_back(n)
#define rep(i,a,b) for(int i = a;i<b;++i)
#define all(x) x.begin(), x.end()
 
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
int merge(vector<int>& arr,int low,int mid,int high)
    {
    vector<int> temp; 
    int left = low;
    int right = mid + 1;   

    int cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); 
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; 
}
  long long mergeSort(vector<int>& arr,long long low ,long long high )
    {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  
        cnt += mergeSort(arr, mid + 1, high); 
        cnt += merge(arr, low, mid, high);  
        return cnt;
    }
void solve()
{  
    int n; cin >> n;
    vector<string> str, str1;
    rep(i, 0, n)
    {
        string hey; cin >> hey;
        // cout << hey << " ";
        str.push_back(hey);
    }
    rep(i, 0, n)
    {
        string hey; cin >> hey;
        // cout << hey << " ";
        str1.push_back(hey);
    }
    // cout << str << "\n" << str1 << "\n";
    map<string, int> mp;
    string t = "";
    int cnt = 1;
    rep(i, 0, str1.size())
        mp[str1[i]] = cnt++;
    
    // for(auto x : mp)
    //     cout << x.first << " " << x.second << "\n";
    t = "";
    vector<int> vec;
    rep(i, 0, str.size())
        vec.push_back(mp[str[i]]);
    // vector<int> vec(n);
    // cin >> vec;
    // cout << vec;
    long long inv = mergeSort(vec, 0, n - 1);
    cout << inv << "\n";
}
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   init();
   clock_t tt = clock();
   int t=1;
    cin>>t;
//   int i = 1;
   while(t--)
   {
      solve();
   }
   cerr << "RunTime: " << ((double)(clock() - tt) / CLOCKS_PER_SEC);
   return 0;
}
