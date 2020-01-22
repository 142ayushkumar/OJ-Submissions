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
map<int, int> id;
bool cmp(const int& a, const int& b)
{
    return id[a] < id[b];
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> tree[n+1];
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    vector<int> bfs(n);
    for(int i=0;i<n;i++) 
    {
        cin >> bfs[i];
        id[bfs[i]] = i;
    }
    for(int i=1;i<=n;i++) sort(all(tree[i]), cmp);
    queue<int> q;
    map<int, int> lev;
    vector<int> level(n+1);
    vector<bool> vis(n+1, false);
    int start = bfs[0];
    lev[1] = 1;
    level[start]  = 1;
    q.push(start);
    vis[start] = 1;
    vector<int> response(n);
    int curr = 0;
    while(!q.empty())
    {
        int top = q.front();
        response[curr++] = top;
        q.pop();
        for(int i:tree[top])
        {
            if(!vis[i])
            {
                lev[level[top]+1]++;
                level[i] = level[top]+1;
                q.push(i);
                vis[i] = true;
            }
        }
    }
    bool check = true;
    // given starting from 1
    if(bfs[0] != 1) check = false;
    for(int i=0;i<n;i++)
        if(bfs[i] != response[i])
        {
            check = false;
            break;
        }
    //prc(all(response));
    if(check) cout << "Yes\n";
    else cout << "No\n";



    return 0;
}

