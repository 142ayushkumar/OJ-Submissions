#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define int long long
#define all(c) (c).begin(),(c).end()
#define M 1000000007
#define INF LLONG_MAX
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
// Use pr(a,b,c,d,e) or cerr<<anything or prc(v.begin(),v.end()) or prc(v,v+n)
//  


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, c;
    cin >> n >> c;
    vector<int> a(n), b(n), ra(n), rb(n);
    for(int i=0;i<n-1;i++)
    {
        cin >> a[i];
        ra[i] = a[i];
        if(i) ra[i] += ra[i-1];
    }
    for(int i=0;i<n-1;i++)
    {
        cin >> b[i];
        rb[i] = b[i];
        if(i) rb[i] += rb[i-1];
    }
    int dp[n][2];
     
    dp[0][0] = 0;
    dp[0][1] = c;
    set<pair<int, int>> sa, sb;
    for(int i=1;i<n;i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][0]) + a[i-1];
        dp[i][1] = min(dp[i-1][0] + c, dp[i-1][1]) + b[i-1];
    }
    for(int i=0;i<n;i++)
        cout << min(dp[i][0], dp[i][1]) << " ";
    cout << "\n";
    
    return 0;
}

