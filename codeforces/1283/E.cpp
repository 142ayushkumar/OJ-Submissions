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
    int N = 2e5 + 5;
    vector<int> c(N, 0), d(N, 0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        c[a]++;
        d[a]++;
    }
    int mn = 0, mx = 0;
    for(int i=0;i<N-2;i++)
    {
        if(c[i])
        {
            c[i+1] = 0;
            c[i+2] = 0;
            mn++;
        }
    }
    vector<int> ans(N, 0);
    for(int i=1;i<N-1;i++)
    {
        if(ans[i-1] == 0 && d[i])
        {
            ans[i-1]  = 1;
            d[i]--;
        }
        if(d[i] && ans[i] == 0)
        {
            ans[i] = 1;
            d[i]--;
        }
        if(d[i] && ans[i+1] == 0) 
        {
            ans[i+1] = 1;
            d[i]--;
        }
    }
    for(int i=0;i<N;i++) if(ans[i]) mx++;
    cout << mn << " " << mx << "\n";



    return 0;
}

