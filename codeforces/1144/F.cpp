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
const int N = 2e5 + 5;

vector<int> g[N];
int lev[N];
int n, m;

void dfs(int node, int l = 1)
{
    if(lev[node]) return;
    lev[node] = l;
    for(int i:g[node])
    {
        if(lev[i] == 0) 
            dfs(i, l+1);
    }
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n >> m; 
    vector<pair<int, int>> edges(m);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        edges[i] = {a, b};
    }
    dfs(1);
    bool check = true;
    for(int i=0;i<m;i++)
    {
        if((lev[edges[i].first] + lev[edges[i].second])%2 == 0)
        {
   //         pr(i, edges[i], lev[edges[i].first], lev[edges[i].second]);
            check = false;
        }
    }
    if(!check)
        cout << "NO\n";
    else 
    {
        cout << "YES\n";
        for(int i=0;i<m;i++)
        {
            if(lev[edges[i].first]%2) cout << "1";
            else cout << "0";
        }
        cout << "\n";
    }
    

    return 0;
}

