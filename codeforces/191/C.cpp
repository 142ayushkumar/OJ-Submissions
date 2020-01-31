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
const int N = (int)1e5 + 5;
const int LOGN = 20;
int n;
vector<int> tree[N];
int lev[N];
int dp[N][LOGN];
map<int, int> vscore;
map<pair<int ,int>, int> ans;
void dfs(int node, int parent)
{
    dp[node][0] = parent;
    for(int i:tree[node])
    {
        if(i == parent) continue;
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

int dist(int a, int b)
{
    return lev[a] + lev[b] - 2*lev[lca(a, b)];
}

void mod_dfs(int node, int parent)
{
    int curr_score = 0;
    int temp = vscore[node];
    for(int i:tree[node])
    {
        if(i != parent)
        {
            mod_dfs(i, node);
            vscore[node] += vscore[i];
        }
    }
    curr_score += vscore[node];
    int xx = min(node, parent), yy = max(node, parent);
    ans[{xx, yy}] = curr_score;
}
int fnd(int l, int a, int b)
{
    int count = 0;
    if(l == a) count++;
    if(l == b) count++;
    for(int i:tree[l])
    {
        if(lev[i] > lev[l])
        {
            count += fnd(i, a, b);
        }
    }
    return count;
}

bool check_lca(int l, int a, int b)
{
	int count = fnd(l, a, b);
    return (count == 2);
}
            

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n;
    vector<pair<int, int>> edges(n-1);
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
        edges[i] = {a, b};
    }
    dfs(1, 1);
    fill();
    int k;
    cin >> k;
    int tot = 0, sm = 0;
    for(int i=0;i<k;i++)
    {
        int a, b;
        cin >> a >> b;
        int z = lca(a, b);
		// check lca
		//if(!check_lca(z, a, b)) 
        //{
        //    pr(a, b, i, z);
        //    assert(false);
        //}
        //pr(z);
        vscore[a] += 1;
        vscore[b] += 1;
        vscore[z] -= 2;
        tot += dist(a, b);
    }
    //prc(all(vscore));
    mod_dfs(1, -1);
    //pr(z);
    for(int i=0;i<n-1;i++)
    {
        int x = edges[i].first, y = edges[i].second;
        int xx = min(x, y), yy = max(x, y);
        cout << ans[{xx, yy}] << " ";
        sm += ans[{xx, yy}];
        int zzz = ans[{xx, yy}];
        assert(zzz>=0);
    }

    assert(tot == sm);
    cout << "\n";
    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=0;j<LOGN;j++)
    //    {
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << "\n";
    //}
    
        
    return 0;
}