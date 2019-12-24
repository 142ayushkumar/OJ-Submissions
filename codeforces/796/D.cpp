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


int32_t main()
{
    fastio;
    int n, k, d;
    cin >> n >>k >> d;
    vector<int> p(k), tree[n];
    for(int i=0;i<k;i++)
    {
        cin >> p[i];
        p[i]--;
    }
    vector<int> vis(n, 0);
    map<pair<int, int>, int> index;
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a < b) swap(a,b);
        index[{a, b}] = i;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    queue<pair<int, int>> q;
    for(int i=0;i<k;i++)
    {
        if(vis[p[i]] == 0)
        {
            q.push({p[i], -1});
            vis[p[i]] = 1;
        }
    }
    set<int> ans;
    while(!q.empty())
    {
        int top = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int i:tree[top])
        {
            if(i == parent) continue;
            if(vis[i])
            {
                ans.insert(index[{max(i, top), min(i, top)}]);
            }
            else
            {
                vis[i] = vis[top] + 1;
                q.push({i, top});
            }
        }
    }
    vector<int> final(ans.begin(), ans.end());
    cout << final.size() << "\n";
    for(int i:final) cout << i+1 << " ";
    cout << "\n";




        
    return 0;
}

