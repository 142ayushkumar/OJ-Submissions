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
    cout << fixed << setprecision(12); 
    int r, s, p;
    cin >> r >> s >> p;
    double dp[r+1][s+1][p+1];
    memset(dp, 0, sizeof(dp));
    dp[r][s][p] = 1;
    for(int i=r;i>=0;i--)
    {
        for(int j=s;j>=0;j--)
        {
            for(int k=p;k>=0;k--)
            {
                if(i+j+k <= 1) continue;
                int den = i*j + j*k + k*i;
            
                if(i and j)
                {
                    double tmp = ((double)i*j)/den;
                    dp[i][j-1][k] += dp[i][j][k] * tmp; 
                }
                if(j and k)
                {
                    double tmp = ((double)j*k)/den;
                    dp[i][j][k-1] += dp[i][j][k] * tmp;
                }
                if(k and i)
                {
                    double tmp = ((double)k*i)/den;
                    dp[i-1][j][k] += dp[i][j][k] * tmp;
                }
            }
        }
    }
    double a = 0, b = 0, c = 0;
    for(int i=1;i<=r;i++) a += dp[i][0][0];
    for(int i=1;i<=s;i++) b += dp[0][i][0];
    for(int i=1;i<=p;i++) c += dp[0][0][i];

    cout << a << " " << b << " " << c << "\n";

    return 0;
}

