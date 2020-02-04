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
const int N = 100000 + 1;
const int LOGN = 17;
int n;
vector<int> tree[N], store[N];
// use lca for finding distances between two vertices fast
int lev[N];
int dp[N][LOGN];
map<int,int> pos;


void dfs(int node, int parent)
{
    dp[node][0] = parent;
    pos[node] = store[lev[node]].size();
    store[lev[node]].pb(node);
	int count = 0;
    for(int i:tree[node])
    {
        if(i == parent) continue;
        count++;	
        lev[i] = lev[node] + 1;
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

int lift(int a, int b)
{
    // lift a, b level
    for(int i=LOGN-1;i>=0;i--)
    {
        if(b&(1<<i))
        {
            a = dp[a][i];
            b ^= (1<<i);
        }
    }
    return a;
}
int dist(int a, int b)
{
    return lev[a] + lev[b] - 2*lev[lca(a, b)];
}

int ipow(int base, int exp)
{
    int ret = 1;
    while(exp)
    {
        if(exp&1)
            ret *= base;
        base *= base;
        exp >>= 1;
    }
    return  ret;
}

    
int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n;
    vector<int> parents;
    for(int i=1;i<=n;i++)
    {
        int tn;
        cin >> tn;
        if(tn == 0)
            parents.pb(i);
        else
        {
            tree[i].pb(tn);
            tree[tn].pb(i);
        }
    }
    // rooting tree
    for(auto parent: parents)
    {
        dfs(parent, parent);
    }
    fill();
    int m;
    cin >> m;
    vector<int> ans(m, -1);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        // lift a -> b lev 
        int parent = lift(a, b);
        int temp_parent = lift(a, b-1);
        if(parent == temp_parent)
        {
            ans[i] = 0;
        }
        else
        {
            int A = pos[a];

            int l = 0, r = store[lev[a]].size() - 1 - A;        
            int L = A, R = A;
            while(l < r)
            {
                int mid =  (l + r + 1)/2;
                if(lift(store[lev[a]][mid + A], b) != parent)
                {
                    r = mid-1;
                }
                else
                    l = mid;

            }
            R = A+l;
            l = 0;
            r = A;
            while(l < r)
            {
                int mid = (l + r)/2;
                if(lift(store[lev[a]][mid], b) != parent)
                {
                    l = mid+1;
                }
                else
                    r = mid;
            }
            L = l;
            ans[i] = R - L;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}



