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

const int N = 5e5 + 5;  
vector<int> tree[N];
int vis[N];
int n;
void dfs(int node)
{
    for(int i:tree[node])
    {
        if(vis[i] == 0) 
        {
            vis[i] = 1;
            dfs(i);
        }
    }
}
int32_t main()
{
    fastio;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<pair<int, int>> all_points(2*n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i].first >> v[i].second;
        all_points[2*i] = {v[i].first, i};
        all_points[2*i+1] = {v[i].second, i};
    }
    sort(all(all_points));
    int total_edges = 0;
    set<pair<int, int>> s;
    for(int i=0;i<2*n;i++)
    {
        if(s.find(all_points[i]) != s.end())
        {
            s.erase(all_points[i]);
        }
        else
        {
            int index = all_points[i].second;
            int y = v[index].second;
            for(auto const& j:s)
            {
                if(j.first > y) break;
                int z = j.second;
                tree[index].pb(z);
                tree[z].pb(index);
                total_edges++;
                if(total_edges >= n) 
                {
                    cout << "NO\n";
                    return 0;
                }
            }
            s.insert({y, index});
        }
    }
 
    //pr(total_edges);
    bool check = true;
    vis[0] = 1;
    dfs(0);
    for(int i=0;i<n;i++)
    {
        if(vis[i] == 0)
        {
            check = false;
            break;
        }
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
    
        
    return 0;
}

