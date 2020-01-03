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

const int N = 1e5 + 5;
set<int> tree[N], not_vis;
int n, m;

void dfs(int node)
{
    vector<int> call;
    for(auto it = not_vis.begin();it != not_vis.end();)
    {
        // checking all not visited nodes
        if(tree[node].find(*it) == tree[node].end())
        {
            call.push_back(*it);
            it = not_vis.erase(it);
        }
        else it++;
    }
    for(int i:call) dfs(i);
}

    

int32_t main()
{
    fastio;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    int ans = 0;
    for(int i=1;i<=n;i++) not_vis.insert(i);
    for(int i=1;i<=n;i++)
    {
        if(not_vis.find(i) != not_vis.end()) 
        {
            not_vis.erase(i);
            dfs(i);
            ans++;
        }
    }
    cout << ans-1 << "\n";

    return 0;
}

