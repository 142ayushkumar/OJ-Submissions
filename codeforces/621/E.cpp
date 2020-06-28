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

int n, b, k, x;
map<int, int> store;
map<int, map<int,int>> dp;
const int MOD = 1e9 + 7;

int ipow(int base, int exp)
{
    int ans = 1;
    while(exp > 0)
    {
        if(exp&1)
            ans = (ans*base)%x;
        base = (base*base)%x;
        exp >>= 1;
    }
    return ans;
}

map<int, int> g(int b)
{
	if(dp.find(b) == dp.end())
	{
		int first = b/2, second = b - b/2;
		map<int, int> tmp = g(first);
		map<int, int> tmp1 = g(second);
		map<int, int> ans;
		for(auto i:tmp)
		{
			int a = i.second;
				
			for(auto j:tmp1)
			{
				int bb = (a*j.second)%MOD;
				int c = (i.first*ipow(10, second) + j.first)%x;
				// pr(i.first, j.second, c, bb);
				ans[c] = (ans[c]+bb)%MOD;
			}
		}
		return dp[b] = ans;
	}
	else return dp[b];

}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    
    cin >> n >> b >> k >> x;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    	cin >> v[i];

    
    for(int i=0;i<n;i++)
    {
    	store[v[i]%x]++;
    }
    dp[1] = store;
    map<int, int> m = g(b);
    // prc(all(m));
    cout << m[k] << "\n";
    return 0;
}