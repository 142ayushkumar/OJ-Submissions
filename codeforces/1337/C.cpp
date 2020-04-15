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
vector<int> t[N];

vector<int> parent(N);
vector<int> val(N);
vector<int> child(N, 0);
set<pair<int, int>, greater<pair<int, int>>> s;

void dfs(int node, int p=0, int lev=0)
{
	parent[node] = p;
	val[node] = lev;
	for(int i:t[node])
	{
		if(i != p)
		{
			dfs(i, node, lev+1);
			child[node] += child[i] + 1;
		}
	}
	
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a, b;
    for(int i=1;i<n;i++)
    {
    	cin >> a >> b;
    	t[a].pb(b);
    	t[b].pb(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    	s.insert({val[i] - child[i], i});
    int ans = 0;
    while(k > 0)
    {
    	pair<int,int> node = *s.begin();
    	// pr(node);
    	s.erase(s.begin());

    	ans += node.first;
    	k--;
    }
    cout << ans << "\n";
    return 0;
}

