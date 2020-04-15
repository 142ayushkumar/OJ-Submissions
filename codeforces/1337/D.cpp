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

const int MAX = 4e18L;

pair<int, int> f(int x, vector<int>& v)
{
	int n = v.size();
	int z = lower_bound(all(v), x) - v.begin();
	int l = MAX, r = MAX;
	if(z != n)
	{
		r = v[z];
	}
	if(z)
		l = v[z-1];
	return {l, r};
}

int get(int x, int y, pair<int, int> z)
{
	int a = (x-y)*(x-y) + (y-z.first)*(y-z.first) + (z.first - x)*(z.first-x);
	int b = (x-y)*(x-y) + (y-z.second)*(y-z.second) + (z.second - x)*(z.second -x);
	if(z.first == MAX and z.second == MAX)
		return MAX;
	else if(z.first == MAX) return b;
	else if(z.second == MAX) return a;
	return min(a, b);
}


int ret(int x, vector<int>& u, vector<int>& v)
{
	pair<int, int> first = f(x, u);
	pair<int, int> second = f(first.first, v);
	pair<int, int> third = f(first.second, v);
	// pr(first, second, third);
	int ans = MAX;
	if(first.first != MAX)
		ans = min(ans, get(x, first.first, second));
	// pr(ans);
	if(first.second != MAX)
		ans = min(ans, get(x, first.second, third));
	// pr(ans);
	return ans;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
    	int r, g, b;
    	cin >> r >> g >> b;
    	vector<int> x(r), y(g), z(b);
    	for(int i=0;i<r;i++) cin >> x[i];
    	for(int i=0;i<g;i++) cin >> y[i];
    	for(int i=0;i<b;i++) cin >> z[i];
    	sort(all(x));
    	sort(all(y));
    	sort(all(z));
    	int ans = MAX;
    	for(int i=0;i<r;i++)
    	{
    		ans = min(ans, ret(x[i], y, z));
    		ans = min(ans, ret(x[i], z, y));
    	}
    	for(int i=0;i<g;i++)
    	{
    		ans = min(ans, ret(y[i], x, z));
    		ans = min(ans, ret(y[i], z, x));
    	}
    	for(int i=0;i<b;i++)
    	{
    		ans = min(ans, ret(z[i], x, y));
    		ans = min(ans, ret(z[i], y, x));
    	}
    	cout << ans << "\n";
    }
    return 0;
}

