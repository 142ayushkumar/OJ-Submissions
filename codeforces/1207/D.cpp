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

const int MOD = 998244353;

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    return a.second < b.second;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++) 
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(all(v));
    vector<int> fact(n+1);
    fact[0] = 1;
    for(int i=1;i<=n;i++)
        fact[i] = (fact[i-1]*i)%MOD;
    int ans = fact[n];
    int a = 1;
    int curr = v[0].first, num = 1;
    for(int i=1;i<n;i++)
    {
        if(v[i].first != curr)
        {
            a = (a*fact[num])%MOD;
            num = 1;
            curr = v[i].first;
        }
        else num++;
    }
    a = (a*fact[num])%MOD;
    //pr(a);

    ans = (ans - a + MOD)%MOD;
    sort(all(v), cmp);
    a = 1;
    curr = v[0].second;
    num = 1;
    for(int i=1;i<n;i++)
    {
        if(v[i].second != curr)
        {
            a = (a*fact[num])%MOD;
            num = 1;
            curr = v[i].second;
        }
        else num++;
    }
    a = (a*fact[num])%MOD;
    ans = (ans - a + MOD)%MOD;
    sort(all(v));
    a = 1;
    num = 1;
    int first = v[0].first, second = v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first != first || v[i].second != second)
        {
            a = (a*fact[num])%MOD;
            num = 1;
            first = v[i].first;
            second = v[i].second;
        }
        else num++;
    }
    a = (a*fact[num])%MOD;
    bool both_sorted = true;
    curr = v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].second < curr)
        {
            both_sorted = false;
        }
        curr = v[i].second;
    }
    if(!both_sorted) a = 0;
    ans = (ans + a)%MOD;
    cout << ans << "\n";
    return 0;
}

