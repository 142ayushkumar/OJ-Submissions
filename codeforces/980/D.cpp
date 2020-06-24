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

bool perfect_square(int x, int y)
{
	int a = x*y;
	if(x == 0 and y == 0) return true;
	if(a <= 0) return 0;
	int z = sqrt(a);
	for(int i=z-2;i<=z+2;i++)
		if(i*i == a) return true;
	return false;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    	cin >> v[i];

    vector<int> last(n, -1);
    for(int i=1;i<n;i++)
    {
    	for(int j=i-1;j>=0;j--)
    	{
    		if(perfect_square(v[i], v[j]))
    		{
    			last[i] = j;
    			break;
    		}
    	}
    }
    vector<int> pre(n, 0);
    for(int i=0;i<n;i++)
    {
    	if(v[i] == 0) pre[i] = 1;
    	if(i)
    		pre[i] += pre[i-1];
    }
    // if a group consist of zeroes, it can be merged with any one other group

    // prc(all(last));
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    vector<int> ans(n+1, 0);
    for(int i=0;i<n;i++)
    {
    	dp[i][i] = 1;
    	ans[1]++;
    	
    	for(int j=i+1;j<n;j++)
    	{
    		int temp_sub = 0;
    		if(last[j] >= i)
    			dp[i][j] = dp[i][j-1];
    		else
    		{
    			dp[i][j] = dp[i][j-1] + 1;
    		}
    		int num_zeroes = pre[j];
			if(i) num_zeroes -= pre[i-1];
			if(num_zeroes) temp_sub = 1;
			if(dp[i][j] == 1) temp_sub = 0;
    		ans[dp[i][j] - temp_sub]++;
    	}
    }

    for(int i=1;i<=n;i++)
    	cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}

