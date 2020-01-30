#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
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
const int N  = 1e5 + 5;
vector<int> g[N], used(N, 0);
int n, m;
set<int> s[3];

vector<pair<int,int>> edges;
vector<int> c(3, 0);

void check(int x, int y)
{
	// check if there is any missing edge between group x and group y 
    map<int, int> equiv;
    for(int i=1;i<=n;i++) equiv[i] = used[i];
    map<int, int> count;
    for(int i=0;i<m;i++)
    {
        int a  = edges[i].first, b = edges[i].second;
        if(used[a] == x && used[b] == y)
        {
            count[b]++;
        }
        else if(used[a] == y && used[b] == x)
        {
            count[a]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(used[i] == y)
        {
            if(count[i] != c[x-1])
            {
                cout << "-1\n";
                exit(0);
            }
        }
    }
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n >> m;
    edges.resize(m);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]) continue;
        for(int j:g[i])
        {
            used[j] = 2;
        }
        used[i] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i] == 1 || used[i] == 3) continue;
        for(int j:g[i])
        {
            if(used[j] != 1)
            {
                used[j] = 3;
            }
        }
    }
	for(int i=1;i<=n;i++)
    {
        if(used[i] == 1 || used[i] == 2) continue;
        for(int j:g[i])
        {
            if(used[j] != 1 && used[j] != 2)
            {
				cout << "-1\n";
				return 0;
            }
        }
    }
    for(int i=1;i<=n;i++) c[used[i]-1]++;
    for(int i=0;i<3;i++)
    {
        if(c[i] == 0)
        {
            cout << "-1\n";
            return 0;
        }
    }
    check(1, 2);
    check(1, 3);
    check(3, 1);
    check(2, 1);
    check(2, 3);
    check(3, 2);
    for(int i=1;i<=n;i++) cout << used[i] << " ";
    cout << "\n";

    return 0;
}

