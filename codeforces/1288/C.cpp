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

const int N = 1000 + 15;
int ncr[N][N];
int nck(int n, int k)
{
    if(n < 0) return 0;
    if(n < k) return 0;
    if(n == k)
    {
        ncr[n][k] = 1;
        return ncr[n][k];
    }
    if(k == 0)
    {
        ncr[n][k] = 0;
        return 1;
    }
    if(ncr[n][k] != -1) return ncr[n][k];
    ncr[n][k] = nck(n-1, k) + nck(n-1, k-1);
    ncr[n][k] %= M;
    return ncr[n][k];
}



int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    memset(ncr, -1, sizeof(ncr));
    for(int i=1;i<=n;i++)
    {
        int z = n-i+1;
        int curr = nck(z+m-2, z-1)*nck(i+m-1, i-1);
        if(curr > M) curr %= M;
        ans += curr;
        if(ans > M) ans %= M;
    }
    cout << ans << "\n";
    return 0;
}

