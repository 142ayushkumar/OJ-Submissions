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

int f(int id, int player, vector<int>& v, map<pair<int, int>, int>& m)
{
    
    if(m.find({player, id}) != m.end())
        return m[{player, id}];
    int d = player;
    if(v[id] == 1)
    {
        if(player ==1) player = 2;
        else player = 1;
        m[{d, id}] = 1-f(id+1, player, v, m); 
    }
    else
    {
        if(player == 1) player = 2;
        else player = 1;
        m[{d, id}] = max(1-f(id+1, player, v, m), f(id+1, d, v, m));
    }
    return m[{d, id}];
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>> v[i];
        map<pair<int, int>, int> m;
        m[{1, n-1}] = 1;
        m[{2, n-1}] = 1;
        int z = f(0, 1, v, m);
        if(z) cout << "First\n";
        else cout << "Second\n";
        
    }

    return 0;
}

