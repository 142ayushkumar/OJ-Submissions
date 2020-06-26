#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define int long long
#define ll long long
#define ll long long
#define all(c) (c).begin(),(c).end()
#define M 1000000007
// #define INF LLONG_MAX
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

const int N = 3e5 + 5;
const int INF = 1e18;
vector<int> tree[N], wt[N];
int weights[N];
int n, ans;

void max2(pair<int,int>& p, int v)
{
	if(v > p.first)
	{
		p.second = p.first;
		p.first = v;
	}
	else if(v > p.second)
	{
		p.second = v;
	}
}

int dfs(int node, int parent=-1)
{
	int t = tree[node].size();
	pair<int, int> mx(-INF, -INF);
	for(int i=0;i<t;i++)
	{
		int node1 = tree[node][i];
		if(node1 == parent) continue;
		int temp = dfs(node1, node);
		int val = weights[node] + temp - wt[node][i];
		ans = max(ans, val);
		max2(mx, val);
		ans = max(ans, temp);
	}
	ans = max(ans, mx.first + mx.second - weights[node]);
	return max(mx.first, weights[node]);
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    	cin >> weights[i];
    for(int i=1;i<n;i++)
    {
    	int a, b, w;
    	cin >> a >> b >> w;
    	tree[a].pb(b);
    	tree[b].pb(a);
    	wt[a].pb(w);
    	wt[b].pb(w);
    }
    ans = *max_element(weights+1, weights+n+1);
    ans = max(ans, dfs(1));
    cout << ans << "\n";
    return 0;
}

