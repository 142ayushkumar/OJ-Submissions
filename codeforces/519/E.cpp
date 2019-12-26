#include <bits/stdc++.h>

using namespace std;

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
const int N = 2*(int)1e5 + 5;
const int LN = 18;
int depth[N];
int lifting[LN][N];
vector<int> tree[N];
int all_nodes[N];
void dfs(int curr, int prev, int lev = 1)
{
    lifting[0][curr] = prev;
    depth[curr] = lev;
    all_nodes[curr] = 1;
    for(int i:tree[curr])
    {
        if(i != prev)
        {
            dfs(i, curr, lev+1);
            all_nodes[curr] += all_nodes[i];
        }
    }
}
int walk(int node, int k)
{
    for(int i=0;i<LN;i++)
    {
        if(k&(1<<i))
            node = lifting[i][node];
    }
    return node;
}

int lca(int u, int v)
{
    if(depth[v] > depth[u])
        swap(u, v);
    u = walk(u, depth[u] - depth[v]);
    if(u == v) return u;
    for(int i=LN-1;i>=0;i--)
    {
        if(lifting[i][u] != lifting[i][v])
        {
            u = lifting[i][u];
            v = lifting[i][v];
        }
    }
    // go 1 up
    return lifting[0][u];
}
    
int dist(int a, int b)
{
    return depth[a] + depth[b] - 2*depth[lca(a, b)];
}

int32_t main()
{
    fastio;
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    map<int, int> store;
    for(int i=0;i<22;i++)
        store[1<<i] = i;
    memset(lifting, -1, sizeof(lifting));
    // root is 0
    dfs(0, -1);
    // complete lifting table
    for(int i=1;i<LN;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(lifting[i-1][j] != -1)
            {
                lifting[i][j] = lifting[i-1][lifting[i-1][j]];
            }
        }
    }
    int q;
    cin >> q;

    for(int i=0;i<q;i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a == b)
        {
            cout << n << "\n";
            continue;
        }
        int z = lca(a, b);
        if(z == a || z == b)
        {
            // find the mid node between a and b
            int distance = dist(a, b);
            if(distance%2)
            {
                cout << "0\n";
                continue;
            }
            // go up by distance/2
            int node = a;
            if(z == a) node = b;
            int up = distance/2;
            up-=1;
            while(up)
            {
                int msb = store[(up&-up)];
                up -= (1<<msb);
                node = lifting[msb][node];
            }
            int num_nodes_down = all_nodes[node];
            // go 1 up
            node = lifting[0][node];
            cout << all_nodes[node] - num_nodes_down << "\n";

        }
        else
        {
            int distance = dist(a,b);
            if(distance%2)
            {
                cout << "0\n";
                continue;
            }
            // which is closer to lca
            int zz = lca(a, b), up = distance/2;
            up -= 1;
            if(depth[a] == depth[b])
            {
                // from both nodes go up till up - 1
                int node = a;
                while(up)
                {
                    int msb = store[(up&-up)];
                    up -= (1<<msb);
                    node = lifting[msb][node];
                }
                int num_nodes_down = all_nodes[node];
                node = b;
                up = distance/2;
                up -= 1;
                while(up)
                {
                    int msb = store[(up&-up)];
                    up -= (1<<msb);
                    node = lifting[msb][node];
                }
                num_nodes_down += all_nodes[node];
                // go 1 up
                node = lifting[0][node];
                int ans = all_nodes[node] - num_nodes_down;
                if(zz != 0) // lca is not root add number of all nodes above lca
                    ans += n - all_nodes[node];
                cout << ans << "\n";
                continue;
            }
            else if(depth[a] - zz < depth[b] - zz)
            {
                swap(a, b);
            }
            // a is farther from lca
            int node = a;
            //pr(node, up, a, b);
            while(up)
            {
                int msb = store[(up&-up)];
                up -= (1<<msb);
                node = lifting[msb][node];
            }
            int num_nodes_down = all_nodes[node];
            // go 1 up
            node = lifting[0][node];
            cout << all_nodes[node] - num_nodes_down << "\n";
            
        }
    }
    return 0;
}

