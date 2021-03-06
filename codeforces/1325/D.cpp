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
    int u, v;
    cin >> u >> v;
    int tsum = v, txor = u;
    if(u > v)
    {
        cout << "-1\n";
        return 0;
    }
    int num = 0;
    int z = v - u;
    int XOR = 0, SUM = 0;
    if(u == 0 and v == 0)
    {
        cout << "0\n";
    }
    else if(z == 0)
        cout << "1\n" << u << "\n";
    else if(u == 0 and z%2)
        cout << "-1\n";
    else if(u == 0) cout << "2\n" << z/2 << " " << z/2 << "\n";
    else if(z%2) cout << "-1\n";
    else
    {
        int tt = z/2;
        if((tt&u) == 0)
        {
            cout << "2\n" << tt << " " << u+tt<< "\n";
            XOR = tt^(u+tt);
            SUM = tt+u+tt;
        }
        else
        {
            cout << "3\n" << u << " " << z/2 << " " << z/2 << "\n";
            XOR = u;
            SUM = u + z/2 + z/2;
        }
        assert(tsum == SUM and txor == XOR);
    }

    return 0;
}

