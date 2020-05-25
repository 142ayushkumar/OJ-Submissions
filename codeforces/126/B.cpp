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
const int N = 1e6 + 5;
int p1n[N], p2n[N];

int ipow(int base, int exp, int mod)
{
    int ans = 1;
    while(exp > 0)
    {
        if(exp&1)
            ans = (ans*base)%mod;
        base = (base*base)%mod;
        exp >>= 1;
    }
    return ans;
}

int mod_inv(int base, int mod)
{
    return ipow(base, mod-2, mod);
}

int inc(int curr, int remove, int power, int add, int p, int m)
{
    curr = (curr - remove + m)%m;
    curr = (curr*mod_inv(p, m))%m;
    curr = (curr + power*add)%m; 
    return curr;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0;i<n;i++)
        s[i] = s[i]-'a' + 1;
    int m = 1e9 +7, p1 = 31, p2 = 53; 
    p1n[0] = 1;
    p2n[0] = 1;
    for(int i=1;i<N;i++)
    {
        p1n[i] = (p1n[i-1]*p1)%m;
        p2n[i] = (p2n[i-1]*p2)%m;
    }

    int h1 = 0, h2 = 0, rh1 = 0, rh2 = 0;
    vector<vector<int>> v;
    for(int i=0;i<n-1;i++)
    {
        h1 = (h1 + p1n[i]*s[i])%m;
        h2 = (h2 + p2n[i]*s[i])%m;
        rh1 = (rh1*p1 + s[n-1-i])%m;
        rh2 = (rh2*p2 + s[n-1-i])%m;
        if(rh1 == h1 and rh2 == h2)
        {
            v.pb({i+1, h1, h2});
        }
    }
    if(v.size() == 0)
    {
        cout <<"Just a legend";
        return 0;
    }

    int l = 0, r = (int)v.size() - 1;
    bool ans = false;
    while(l <= r)
    {
        int mid = (l+r+1)/2;
        int len = v[mid][0];
        h1 = v[mid][1];
        h2 = v[mid][2];
        bool found = false;
        for(int i=1;i+len-1<n-1;i++)
        {

            h1 = inc(h1, s[i-1], p1n[len-1], s[i+len-1], p1, m);
            //h2 = inc(h2, s[i-1], p2n[len-1], s[i+len-1], p2, m);
            if(h2 == v[mid][2] and h1 == v[mid][1])
            {
                found = true;
                ans = true;
                break;
            }
        }
        if(found) 
        {
            if(l ==r)r--;
            l = mid;
        }
        else r = mid-1;
    }
    if(!ans) cout <<"Just a legend\n";
    else
    {
        for(int i=0;i<v[l][0];i++)
            cout << (char)(s[i] + 'a' -1);
        cout << "\n";
    }

    return 0;
}

