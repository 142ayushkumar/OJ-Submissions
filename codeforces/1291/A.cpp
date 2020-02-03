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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool is_odd = (s[n-1]-'0')%2;
        int sm = 0;
        for(int i=0;i<n;i++)
        {
            sm += s[i] - '0';
        }
        if(sm%2 == 0 && is_odd) cout << s << "\n";
        else if(n == 1) cout << "-1\n";
        else
        {
            int n_odd = 0, ans = 0;
            for(int i=0;i<n;i++)
            {
                int z = s[i] - '0';
                if(z%2)
                {
                    n_odd++;
                }
            }
            if(n_odd < 2) cout << "-1\n";
            else 
            {
                int ans = 0, c = 2;
                for(int i=0;i<n;i++)
                {
                    if(!c) break;
                    int z = s[i] - '0';
                    if(z%2)
                    {
                        ans *= 10;
                        ans += z;
                        c--;
                    }
                }
                cout << ans << "\n";
            }
        }



    }
    return 0;
}

