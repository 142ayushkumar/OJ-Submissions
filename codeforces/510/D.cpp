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

int n;
vector<int> c, l;
const int N = 300 + 5;
int dp[N][1<<9];


int f(int id, int mask, vector<int>& v, int z)
{
	if(id == n)
	{
		if(mask == (1<<z)-1)
			return 0;
		else return 1e9;
	}
	if(dp[id][mask] != -1) return dp[id][mask];
	int curr = min(c[id] + f(id+1, mask|v[id], v, z), f(id+1, mask, v, z));
	dp[id][mask] = curr;
	return curr;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n;
    c.resize(n), l.resize(n);
    for(int i=0;i<n;i++)
    {
    	cin >> l[i];
    }
    for(int i=0;i<n;i++)
    	cin >> c[i];

    int ans = 1e9;
    for(int i=0;i<n;i++)
    {
    	//  if i index is in answer
    	memset(dp, -1, sizeof(dp));
    	vector<int> prime;
    	int tmp = l[i];
    	for(int j=2;j*j<=l[i];j++)
    	{
    		if(tmp%j == 0)
    			prime.pb(j);
    		while(tmp%j == 0)
    			tmp/=j;
    	}
    	if(tmp > 1) prime.pb(tmp);
    	vector<int> v(n, 0);
    	for(int j=0;j<n;j++)
    	{
    		for(int k=0;k<(int)prime.size();k++)
    		{
    			if(l[j]%prime[k])
    				v[j] |= (1<<k);
    		}
    	}
    	ans = min(ans, c[i] + f(i+1, 0, v, prime.size()));
    }
    if(ans == 1e9)
    	ans = -1;
    cout << ans << "\n";
    
    return 0;
}

