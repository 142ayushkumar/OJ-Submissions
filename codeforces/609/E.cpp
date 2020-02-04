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
const int LOGN = 18;

int n, m;
vector<int> graph[N], cost[N];
vector<int> tree[N], tcost[N];
int lev[N], dp[N][LOGN], cdp[N][LOGN], vis[N];

void dfs(int node, int parent)
{
    dp[node][0] = parent;
    for(int ii=0;ii<tree[node].size();ii++)
    {
        int i = tree[node][ii];
        if(i ==  parent) continue;
        lev[i] = lev[node] + 1;
        cdp[i][0] = tcost[node][ii];
        dfs(i, node);
    }
}

void fill()
{
    for(int i=1;i<LOGN;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[j][i] = dp[dp[j][i-1]][i-1];
            cdp[j][i] = max(cdp[j][i-1], cdp[dp[j][i-1]][i-1]);
        }
    }
}

int max_path_cost(int a, int b)
{
    if(lev[a] > lev[b]) swap(a, b);
    int diff = lev[b] - lev[a];
    int ans = 0;
    for(int i=0;i<LOGN;i++)
    {
        if(diff&(1<<i))
        {
            diff -= (1<<i);
            ans = max(ans, cdp[b][i]);
            b = dp[b][i];
        }
    }
    if(a == b) return ans;
    for(int i=LOGN-1;i>=0;i--)
    {
        int x = dp[a][i], y = dp[b][i];
        if(x!=y) 
        {
            ans = max(ans, max(cdp[a][i], cdp[b][i]));
            a = x;
            b = y;
        }
    }
    // go 1 up
    ans = max(ans, max(cdp[a][0], cdp[b][0]));
    return ans;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n >> m;     
    vector<pair<int, int>> edges(m);
    vector<int> ecost(m);
    int u, v, w;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
        edges[i] = {u, v};
        ecost[i] = w;
    }
    vector<bool> used(n+1, false);
    priority_queue<vector<int>, vector<vector<int>>,  greater<vector<int>>> q;
    q.push({0, 1, -1});
    int mst = 0;
    while(!q.empty())
    {
        vector<int> front = q.top();
        q.pop();
        int node = front[1], node1 = front[2];
        if(used[node]) continue;
        if(node1 != -1)
        {
            tree[node].pb(node1);
            tcost[node].pb(front[0]);
            tree[node1].pb(node);
            tcost[node1].pb(front[0]);
        }
        mst += front[0];
        used[node] = true;
        for(int i=0;i<graph[node].size();i++)
        {
            int cnode = graph[node][i], ccost = cost[node][i];
            if(used[cnode]) continue;
            q.push({ccost, cnode, node});
        }
    }
    dfs(1, 0);
    fill();
    for(int i=0;i<m;i++)
    {
        int uu = edges[i].first, vv = edges[i].second;
        int z = max_path_cost(uu, vv);
        //pr(z, uu, vv);
        cout << mst - z + ecost[i] << "\n";
    }

    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=0;j<10;j++)
    //        cout << cdp[i][j] << " ";
    //    cout << "\n";
    //}
    //cout << "\n\n";
    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=0;j<10;j++)
    //        cout << dp[i][j] << " ";
    //    cout << "\n";
    //}


    return 0;
}

