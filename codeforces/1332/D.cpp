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

int calc(vector<vector<int>>& v)
{
	int n = v.size(), m = v[0].size();
	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	dp[0][1] = v[0][0];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j] = max(dp[i-1][j]&v[i-1][j-1], dp[i][j-1]&v[i-1][j-1]);
		}
	}
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=m;j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	return dp[n][m];

}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int k;
    cin >> k;
    if(k == 0)
    {
    	cout << "1 1\n1\n";
    	return 0;
    }
    vector<vector<int>> check;
    // check.push_back({7, 3, 3, 1});
    // check.push_back({4, 8, 3, 6});
    // check.push_back({7, 7, 7, 3});
    // check.push_back({1, 1, 1, 1});
    // check.push_back({1, 1, 1, 1});
    // check.push_back({1, 2, 3, 1});
    // check.push_back({15, 5, 1});
    // check.push_back({8, 13, 5});
    int z = (1<<18) -1;
    int req = k+1;
    // int ans[2][3];
    vector<vector<int>> ans(2, vector<int>(3));
    ans[0][0] = z;
    ans[0][1] = (req|1);
    ans[1][2] = ans[0][1];
    ans[1][0] = (1<<17);
    ans[1][1] = (ans[1][0] | req);
    ans[0][2] = 1;
    cout << 2 << " " << 3 <<"\n";
    for(int i=0;i<2;i++)
    {
    	for(int j=0;j<3;j++)
    		cout <<ans[i][j] << " ";
    	cout << "\n";
    }

    // cout << calc(ans) << "\n";
    return 0;
}

