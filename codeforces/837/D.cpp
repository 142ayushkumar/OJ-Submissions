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
// #define M 1000000007
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
const int N = 200;
const int M = 26*200;

int dp[2][N][M]; // used till i, used j items, power of 5 and dp[i][j][k] stores max power of 2


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    // vector<int> v(n);
    vector<pair<int, int>> v(n, {0, 0});
    for(int i=0;i<n;i++)
    {
    	int temp;
    	cin >> temp;
    	int a = 0;
    	while(temp%2 == 0)
    	{
    		a++;
    		temp /= 2;
    	}
    	v[i].first = a;
    	a = 0;
    	while(temp%5 == 0)
    	{
    		a++;
    		temp /= 5;
    	}
    	v[i].second = a;
    }

    
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
    	int curr = (i+1)%2;
    	for(int j=0;j<k;j++)
    	{
    		for(int l=0;l<M;l++)
    		{
    			if(dp[1-curr][j][l] >= 0)
    			{
    				dp[curr][j+1][l+v[i].second] = max(dp[curr][j+1][l+v[i].second], dp[1-curr][j][l] + v[i].first);
    				ans = max(ans, min(l+v[i].second, dp[curr][j+1][l+v[i].second]));
    			}
    			dp[curr][j][l] = max(dp[curr][j][l], dp[1-curr][j][l]);
    		}
    	}
    }
    cout << ans << "\n";

    return 0;
}

