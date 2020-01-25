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

vector<vector<int>> v;
int n, m;
bool found = false;
map<pair<int, int>, bool> used;// row, curr
void dfs(int row, int curr, vector<int>& x)
{
    if(found) return; 
    if(used.find({row, curr}) != used.end()) return;
    used[{row, curr}] = true;
    if(row == n)
    {
        if(curr)
        {
            cout << "TAK\n";
            for(int i:x) cout << i << " ";
            cout << "\n";
            found = true;
        }
        return;
    }
    for(int i=0;i<m;i++)
    {
        x[row] = i + 1;
        dfs(row+1, curr^v[row][i], x);
    }
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    
    cin >> n >> m;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        v[i].resize(m);
        for(int j=0;j<m;j++)
            cin >> v[i][j];
    }
    vector<int> curr(n);
    dfs(0, 0, curr);
    if(!found) cout << "NIE\n";
    return 0;
}

