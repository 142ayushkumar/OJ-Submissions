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

const int N = 2e3 + 5;
string dp[N][N];
vector<string> v;
int dist[N][10];
int n;

string f(int id, int k)
{
	if(k <0) return "|";
	if(id == n)
	{
		if(k > 0) return "|";
		if(k == 0)
		{
			return "";
		}
	}
	if(dp[id][k] != "-") return dp[id][k];
	string curr = "";
	bool found = false;
	for(int i=9;i>=0;i--)
	{
		if(dist[id][i] != -1)
		{
			string z = f(id+1, k-dist[id][i]);
			if(z == "|")
				continue;

			curr += (char)(i + '0');
			curr += z;
			found = true;
			break;
		}
	}

	if(found == false) 
	{
		dp[id][k] = "|";
		return "|";
	}
	
	return dp[id][k] = curr;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int k;
    cin >> n >> k;
    v.resize(n);
    for(int i=0;i<n;i++)
    	cin >> v[i];
    vector<string> store = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    for(int i=0;i<n;i++)
    {
    	
    	for(int k=0;k<10;k++)
    	{
    		int curr = 0;
	    	for(int j=0;j<7;j++)
	    	{
	    		if(store[k][j] == '0' and v[i][j] == '1')
	    		{
	    			curr = -1;
	    			break;
	    		}
	    		else if(store[k][j] == '1' and v[i][j] == '0')
	    		{
	    			curr++;
	    		}
	    	}
	    	dist[i][k] = curr;
		}	
    }
    for(int i=0;i<N;i++)
    {
    	for(int j=0;j<N;j++)
    		dp[i][j] = "-";
    }
    string ans = f(0, k);
    if(ans == "|" or ans == "-") cout << "-1\n";
    else cout << ans <<"\n";
    
    return 0;
}

