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


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> graph[n+1];
    vector<pair<int, int>> edges(n-1);
    for(int i=1;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        edges[i-1] = {min(a, b), max(b, a)};
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int mx_deg = 0, mx_idx = -1;
    for(int i=1;i<=n;i++)
    {
        if(graph[i].size() > mx_deg)
        {
            mx_deg = graph[i].size();
            mx_idx = i;
        }
    }
    map<pair<int,int>, int> ans;
    int curr = 0;
    for(int i:graph[mx_idx])
    {
        int x = i, y = mx_idx;
        //pr(x, y);
        ans[{min(x, y), max(x,y)}] = curr++;
    }
    for(int i=0;i<n-1;i++)
    {
        if(ans.find(edges[i]) == ans.end()) ans[edges[i]] = curr++;
    }
    for(int i=0;i<n-1;i++) cout << ans[edges[i]] << "\n";

    return 0;
}

