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
    int n;
    cin >> n;
    vector<int> v(n);
    int n_odd = 0, n_even =0;
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        if(v[i])
        {
            if(v[i]%2) n_odd++;
            else n_even++;
        }
    }
    n_odd = (n+1)/2 - n_odd;
    n_even = n/2 - n_even;
    int dp[n][n][n][2]; // index n_odd n_even odd_used or even_used
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                for(int l=0;l<2;l++)
                    dp[i][j][k][l] = M;
    if(v[0] == 0)
    {
        if(n_odd) dp[0][n_odd-1][n_even][1] = 0;
        if(n_even) dp[0][n_odd][n_even-1][0] = 0;
    }
    else if(v[0]%2) 
    {
        dp[0][n_odd][n_even][1] = 0;
    }    
    else
        dp[0][n_odd][n_even][0] = 0;
    for(int i=1;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
           for(int k=0;k<n;k++)
           {
               if(dp[i-1][j][k][1] < M)
               {
                   if(v[i])
                   {
                       if(v[i]%2)
                           dp[i][j][k][1] = min(dp[i-1][j][k][1], dp[i][j][k][1]);
                       else dp[i][j][k][0] = min(dp[i-1][j][k][1] + 1, dp[i][j][k][0]);
                   }
                   else
                   {
                       if(j) dp[i][j-1][k][1] = min(dp[i-1][j][k][1], dp[i][j-1][k][1]);
                       if(k) dp[i][j][k-1][0] = min(dp[i-1][j][k][1] + 1, dp[i][j][k-1][0]);
                   }
               }

    		   if(dp[i-1][j][k][0] < M)
               {
                   if(v[i])
                   {
                       if(v[i]%2)
                           dp[i][j][k][1] = min(dp[i-1][j][k][0] + 1, dp[i][j][k][1]);
                       else dp[i][j][k][0] = min(dp[i-1][j][k][0], dp[i][j][k][0]);
                   }
				   else
                   {
                       if(j) dp[i][j-1][k][1] = min(dp[i-1][j][k][0]+1, dp[i][j-1][k][1]);
                       if(k) dp[i][j][k-1][0] = min(dp[i-1][j][k][0], dp[i][j][k-1][0]);
                   }
               }
           }
       }
    }
    int ans = min(dp[n-1][0][0][0], dp[n-1][0][0][1]);
    cout << ans << "\n";

    return 0;
}

