#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define int long long
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
int n, m, a, b;
const int N = 2*(int)1e5 + 5;
vector<int> v[N];
vector<int> vis(N, -1);
void dfs(int node, int x)
{
    if(node == a || node == b) return;
    if(vis[node] == -2) return;
	vis[node] = x;
	bool check = false;
    if(x == -2) check = true;
    int z = (a == x)? a:b;
    for(int i:v[node])
    {
        if(i == z) 
        {
            check = true;
            vis[node] = -2;
        }
        else 
        {
            if(vis[i] == -1)
            {
                dfs(i, x);
            }
        }
    }
            
    if(check)
    {
        for(int i:v[node])
        {
            if(i == a || i == b || vis[i] == -2) continue;
            if(vis[i] != -2)
                dfs(i, -2);
        }
    }
}


int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n >> m >> a >> b;
    	for(int i=0;i<n;i++)
            if(v[i].size())
    		    v[i].clear();
    	for(int i=0;i<n;i++) vis[i] = -1;
    	for(int i=0;i<m;i++)
    	{
    		int x, y;
    		cin >> x >> y;
    		x--;
    		y--;
    		v[x].pb(y);
    		v[y].pb(x);
    	}
        int x = 0, y = 0;
    	a--;
    	b--;
        vis[a] = a;
        vis[b] = b;
    	for(int i=0;i<v[a].size();i++)
    	{
    		dfs(v[a][i], b);
    	}
    	for(int i=0;i<v[b].size();i++)
    	{
    		dfs(v[b][i], a);
    	}
        for(int i=0;i<n;i++)
            if(vis[i] == a) x++;
            else if(vis[i] == b) y++;
        x--;
        y--;
    	cout << x*y << "\n";
    }
    
    return 0;
}
