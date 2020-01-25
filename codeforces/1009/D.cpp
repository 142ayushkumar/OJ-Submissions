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
    int n, m;
    cin >> n >> m;
    if(m < n - 1)
    {
        cout << "Impossible\n";
        return 0;
    }
    vector<pair<int, int>> edges(m);
    int z  = 0;
    for(int i=2;i<=n;i++)
    {
        edges[z++] = {1, i};
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=i+1;j<2*i;j++)
        {
            if(__gcd(i, j) != 1) continue;
            for(int k=j;k<=n;k+=i)
            {
                if(z == m) break;
                edges[z++] = {i, k};
            }
            if(z == m) break;
        }
        if(z == m) break;
    }
    if(z == m)
    {
        cout << "Possible\n";
        for(auto i: edges)
            cout << i.first << " " << i.second << "\n";
    }
    else
        cout << "Impossible\n";

    return 0;
}

