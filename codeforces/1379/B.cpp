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


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int l, r, m;
        cin >> l >> r >> m;
        auto satisfy = [&] (int a, int b, int c) {
            int n = (m-b+c)/a;
            int mod = (m-b+c)%a;
            return (mod == 0 and n > 0 and a >= l and b >=l and c >=l and a <= r and b <= r and c <= r);
        };
        auto get = [&] (int a, int n) {
            int diff = m - n*a;
            int b, c;
            if(diff > 0) 
            {
                b = l+diff;
                c = l;
            }
            else
            {
                b = l;
                c = l+abs(diff);
            }
            return make_pair(b, c);
        };

        int i;
        pair<int, int> tmp = {-1, -1};
        for(i=l;i<=r;i++)
        {
            int n = m/i;
            tmp = get(i, n);
            if(satisfy(i, tmp.first, tmp.second))
            {
                cout << i << " " << tmp.first << " " << tmp.second << "\n";
                break;
            }
            tmp = get(i, n-1);
            if(satisfy(i, tmp.first, tmp.second))
            {
                cout << i << " " << tmp.first << " " << tmp.second << "\n";
                break;
            }
            tmp = get(i, n+1);
            if(satisfy(i, tmp.first, tmp.second))
            {
                cout << i << " " << tmp.first << " " << tmp.second << "\n";
                break;
            }
    
        }
    }
    return 0;
}

