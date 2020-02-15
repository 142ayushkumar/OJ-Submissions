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
const int LOGN = 20;
int n;
vector<int> tree[N];
int lev[N];
int dp[N][LOGN];

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


    
int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
	cin >> n;
	for(int i=1;i<n;i++)
	{
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
	}
	dfs(1, 1);
	fill();
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int x, y, a, b, k;
		cin >>  x >> y >> a >> b >> k;
        int zz = lca(x, y), cc = lca(a, b);
        int dxy = dist(x, y), dab = dist(a, b);

        int diff = k - dab;
        if(diff >= 0 && diff%2 == 0)
        {
            cout << "YES\n";
            continue;
        }
         
        vector<int> check = {2*dist(x, a) + dab, 2*dist(y, b) + dab, 2*dist(y, a) + dab, 2*dist(x, b) + dab, dist(x, a) + dist(y, b), dist(x, b) + dist(y, a)};
        bool found = 0;
        for(int j=0;j< (int)check.size();j++)
        {
            if(j <= 3)
            {

                int xx = k - check[j] - dxy - 1;
                if(xx >= 0 && xx%2== 0)
                {
                    found = true;
                }
            }
            if(j > 3)
            {
                int temp = k - check[j] - 1;
                if(temp >= 0 && temp%2 == 0)
                {
                    found = true;
                }
            }
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
	}
    return 0;
}



