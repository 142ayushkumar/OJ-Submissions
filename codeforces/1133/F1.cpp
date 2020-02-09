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
const int N = (int)2e5 + 5;
int n, m;
vector<int> graph[N];
int id[N];
vector<int> parent(N), size(N);

void init()
{
    for(int i=0;i<N;i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int find_p(int node)
{
    if(node == parent[node]) return node;
    return parent[node] = find_p(parent[node]);
}

void union_(int a, int b)
{
    a = find_p(a);
    b = find_p(b);
    if(a == b) return;
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    parent[b] = a;
}


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        edges[i] = {a, b};
    }
    int ver_max_deg = 1, max_deg = graph[1].size();
    for(int i=2;i<=n;i++)
    {
        if(graph[i].size() > max_deg)
        {
            max_deg = graph[i].size();
            ver_max_deg = i;
        }
    }
    vector<bool> vis(n+1, false);
    init();
    for(int i:graph[ver_max_deg])
    {
        cout << i << " " << ver_max_deg << "\n";
        union_(ver_max_deg, i);
    }

    for(int i=0;i<m;i++)
    {
        int a = edges[i].first, b = edges[i].second;
        if(find_p(a) == find_p(b)) continue;
        union_(a, b);
        cout << a << " " << b << "\n";
    }

    return 0;
}

