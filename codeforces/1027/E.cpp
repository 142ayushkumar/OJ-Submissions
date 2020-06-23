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
const int MOD = 998244353;

const int N = 500 + 5;

int dp[2][N][N];




int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, K;
    cin >> n >> K;
    dp[1][1][1] = 1;
    for(int ii=1;ii<=n;ii++)
    {
    	int i = ii%2;
    	// j = 1
    	for(int k=1;k<=n;k++)
    	{
    		// if(ii==1 and k == 1) continue;
    		for(int j=1;j<n;j++)
    			dp[i][1][k] += dp[1-i][j][k];
    		dp[i][1][k] %= MOD;
    	}
    	for(int j=2;j<=n;j++)
    	{
    		for(int k=1;k<=n;k++)
    		{
    			dp[i][j][max(j, k)] += dp[1-i][j-1][k];
    			dp[i][j][max(j, k)] %= MOD;
    		}
    	}
    	for(int j=0;j<=n;j++)
    	{
	    	for(int k=0;k<=n;k++)
	    	{
	    		dp[1-i][j][k] = 0;
	    	}
	    }
    }
    int pre[n+1];
    memset(pre, 0, sizeof(pre));
    for(int k=0;k<=n;k++)
    {
    	for(int j=0;j<=n;j++)
    	{
    		pre[k] += dp[n%2][j][k];
    		pre[k] %= MOD;
    	}
    }
    // pre sum
    int prepre[n+1];
    memset(prepre, 0, sizeof(prepre));
    for(int i=1;i<=n;i++)
    	prepre[i] = (prepre[i-1] + pre[i])%MOD;
    int ans = 0;
    // check if sqrt(k) is counted twice
    for(int k=1;k<=n;k++)
    {
    	int tmp = (K-1)/k;
    	tmp = min(tmp, n);
    	ans = (ans + pre[k]*prepre[tmp])%MOD;
    }
    cout << (ans*2)%MOD << "\n";
    return 0;
}
 