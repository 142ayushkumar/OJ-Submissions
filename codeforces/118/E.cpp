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

const int N = 1e5 + 5;
vector<int> graph[N];
int n;
vector<int> dp(N), lev(N, 0);
bool bridge = false;

void dfs(int node)
{
    dp[node] = 0;
    for(int i:graph[node])
    {
        if(lev[i] == 0)
        {
            lev[i] = lev[node] + 1;
            dfs(i);
            dp[node] += dp[i];
        }
        else if(lev[i] > lev[node])
            dp[node]--;
        else if(lev[i] < lev[node])
            dp[node]++;
    }

    dp[node]--;
    if(lev[node] > 1 and dp[node] == 0)
    {
        bridge = true;
    }
}

void f(int node, int p = 0)
{
    for(int i:graph[node])
    {
        if(lev[i] == 0)
        {
            cout << node << " " << i << "\n";
            lev[i] = lev[node] + 1;
            f(i, node);
        }
        else if(lev[i] < lev[node] and i != p) // backedge
        {
            cout << node << " " << i << "\n";
        }
    }
}


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n;
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    lev[1] = 1;
    dfs(1);
    if(bridge) cout << "0\n";
    else
    {
        lev.assign(N, 0);
        lev[1]  = 1;
        f(1);
    }
    return 0;
}

