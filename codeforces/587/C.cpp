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
const int N = (int)1e5 + 1;
const int LOGN = 20;
int n, m, q;
vector<int> tree[N], nodeinf[N], count(N, 0), information[N][LOGN];
// use lca for finding distances between two vertices fast
int lev[N], dis[N];
int dp[N][LOGN];

void dfs(int node, int parent)
{
    dp[node][0] = parent;
    dis[node] += nodeinf[node].size();
    for(int i:tree[node])
    {
        if(i == parent) continue;
        lev[i] = lev[node] + 1;
        dis[i] = dis[node];
        dfs(i, node);
    }
}

void fill()
{
    for(int j=1;j<LOGN;j++)
    {
        for(int i=1;i<=n;i++)
        {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    vector<int> overflow(N, false);
    // resize nodeinf[i] to 10 if size > 10
    for(int i=1;i<=n;i++)
    {
        if(nodeinf[i].size() > 10) nodeinf[i].resize(10);
        information[i][0] = nodeinf[i];
    }
    for(int j=1;j<LOGN;j++)
    {
        for(int i=1;i<=n;i++)
        {
            int y = information[dp[i][j-1]][j-1].size();
            priority_queue<int> pq;
            for(int k:information[i][j-1]) 
            {
                pq.push(k);
                if(pq.size() > 10) pq.pop();
            }
            for(int k=0;k < y ;k++)
            {
                pq.push(information[dp[i][j-1]][j-1][k]);
                if(pq.size() > 10) pq.pop();
            }
            while(pq.size() > 10) pq.pop();
            while(!pq.empty())
            {
                information[i][j].pb(pq.top());
                pq.pop();
            }
        }
    }
}

int lca(int a, int b)
{
    if(lev[a] > lev[b]) swap(a, b);
    int diff = lev[b] - lev[a];
    // go up from b with this diff
    int curr = 0; 
    while(diff > 0)
    {
        int z = (1<<curr);
        if(diff&z)
        {
            diff -= z;
            b = dp[b][curr];
        }
        curr++;
    }
    if(a == b) return a;
    for(int i=LOGN-1;i>=0;i--)
    {
        int x = dp[a][i], y = dp[b][i];
        if(x != y)
        {
            a = x;
            b = y;
        }
    }
    // now go 1 up
    return dp[a][0];
}

void print_in_path(int a, int b, int ct)
{
    priority_queue<int> pq;
    if(lev[a] > lev[b]) swap(a, b);
    int diff = lev[b] - lev[a];
    int curr = 0;
    //prc(all(information[b][0]));
    while (diff > 0)
    {
        int z = (1 << curr);
        if(diff&z)
        {
            for(int i:information[b][curr]) 
            {
                pq.push(i);
                if(pq.size() > 10) pq.pop();
            }
            diff -= z;
            b = dp[b][curr];
        }
        curr++;
    }
    if(a != b) 
    {
        for(int i=LOGN-1;i>=0;i--)
        {
            int x = dp[a][i], y = dp[b][i];
            if(x != y)
            {
                for(int j:information[a][i]) 
                {
                    pq.push(j);
                    if(pq.size() > 10) pq.pop();
                }
                for(int j:information[b][i]) 
                {
                    pq.push(j);
                    if(pq.size() > 10) pq.pop();
                }
                a = x;
                b = y;
            }
        }
         for(int j:information[a][0]) 
         {
             pq.push(j);
             if(pq.size() > 10) pq.pop();
         }
        for(int j:information[b][0]) 
        {
            pq.push(j);
            if(pq.size() > 10) pq.pop();
        }
        for(int j:information[dp[a][0]][0]) 
        {
            pq.push(j);
            if(pq.size() > 10) pq.pop();
        }
    }
    else
    {
        for(int j:information[a][0])
        {
            pq.push(j);
            if(pq.size() > 10) pq.pop();
        }
    }
    vector<int> ans(ct, -1);
    while(pq.size() > ct)
        pq.pop();
    while(ct--)
    {
        ans[ct] = pq.top();
        pq.pop();
    }
    for(int i:ans) cout << i << " ";
    cout << "\n";
}

int dist(int a, int b)
{
    return lev[a] + lev[b] - 2*lev[lca(a, b)];
}

int num(int a, int b)
{
    int lca_ = lca(a, b);
    //pr(a, b, lca_, dis[a], dis[b], dis[lca_]);
    return dis[a] + dis[b] - 2*dis[lca_] + nodeinf[lca_].size();
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n >> m >> q;	
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    for(int i=0;i<m;i++)
    {
        int z;
        cin >> z;
        nodeinf[z].pb(i+1);
    }
    dfs(1, 0);
    fill();
    for(int i=0;i<q;i++)
    {
        int u, v, a;
        cin >> u >> v >> a;
        //pr(num(u, v));
        int z =num(u, v);
        int ct = min(z, a);
        cout << ct << " ";
        print_in_path(u, v, ct);
    }

    return 0;
}

