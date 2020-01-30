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
        int a, m;
        cin >> a >> m;
        // find prime factors of m
        int gcd = __gcd(a, m);
        vector<int> pfactors;
        int temp = m/gcd;
        for(int i=2;i<= (int)sqrt(m);i++)
        {
            if(temp%i == 0)
            {
                pfactors.pb(i);
                while(temp%i == 0)
                    temp /= i;
            }
        }
        if(temp != 1) pfactors.pb(temp);
        int n = pfactors.size(), ans = 0;
        m += a;
        m /= gcd; 
        a /= gcd;
        //pr(a, m);
        //prc(all(pfactors));
        for(int mask = 1;mask < (1<<n);mask++)
        {
            int z = __builtin_popcount(mask);
            int curr = 1;
            for(int i=0;i<n;i++)
            {
                if(mask&(1<<i)) curr*= pfactors[i];
            }
            if(z%2)
                ans += (m-1)/curr - (a-1)/curr;
            else ans -= (m-1)/curr - (a-1)/curr;
        }
        cout << (m - a) - ans << "\n";
    }
        




    return 0;
}

