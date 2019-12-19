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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(2*n);
        int one = 0, two = 0;
        for(int i=0;i<2*n;i++) 
        {
            cin >> a[i];
            if(a[i] == 1) one++;
            else two++;
        }
        map<int, int> m;
        int co = 0, ct = 0;
        m[0] = n;
        int ans = 2*n;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i] == 1) co++;
            else ct++;
            if(m.find(co-ct) == m.end())
                m[co-ct] = i;
            if(one - two  - (co - ct) == 0) 
            {
                ans = min(n-1 - i + 1, ans);
            }
        }
        co = 0;
        ct = 0;
        for(int i=n;i<2*n;i++)
        {
            if(a[i] == 1) co++;
            else ct++;
            int z = one - two - (co - ct);

            if(m.find(z) != m.end())
            {
                ans = min(ans, i - m[z] + 1);
            }
        }
        if(one == two) ans = 0;
        cout << ans << "\n";

    }
    return 0;
}

