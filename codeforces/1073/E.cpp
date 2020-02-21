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

const int MOD = 998244353;
vector<int> num;

void split(int n)
{
    num.clear();
    while(n > 0)
    {
        num.pb(n%10);
        n/=10;
    }
    reverse(all(num));
}

int dp[20][(1<<11) + 1][2]; // index, mask, tight
int cnt[20][(1<<11) + 1][2];
int k;
int powers[19];

int calc(int pos, int used, int tight)
{
    int diff = __builtin_popcountll(used);
    // leading zeros not counted in k
    if(used == 1) 
    {
        used = 0;
        diff = 0;
    }
    if(pos >= (int)num.size())
    {
        return 1;
    }

    if(cnt[pos][used][tight] != -1) return cnt[pos][used][tight];

    int lim = 9;
    if(tight) lim = num[pos];
    int cans = 0, cdp = 0;
    for(int i=0;i<=lim;i++)
    {
        int X = (used|(1<<i)); // for leading zero
        if(X == 1) X = 0;
        if((used & (1LL<<i)) || (diff < k))
        {
            if(i != lim || !tight) 
            {
                int z = calc(pos+1, X, 0);
                if(z > MOD) z%= MOD;
                cans += z;
                cdp += z*i*powers[(int)num.size() - 1 - pos] + dp[pos+1][X][0];
            }
            else 
            {
                int z = calc(pos+1, X, 1);
                if(z > MOD) z %= MOD;
                cans += z;
                cdp += z*i*powers[(int)num.size() - 1 - pos] + dp[pos+1][X][1];
            }
        } 
        if(cans > MOD) cans %= MOD;
        if(cdp > MOD) cdp %= MOD;
    }
    dp[pos][used][tight] = cdp;
    cnt[pos][used][tight] = cans;

    return cans;
}


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);

    int l, r;
    cin >> l >> r >> k;
   
    powers[0] = 1;
    for(int i=1;i<19;i++) powers[i] = (powers[i-1]*10)%MOD;

    memset(cnt, -1, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    split(r);
    int R = calc(0, 0, 1);
    R = dp[0][0][1];
    memset(cnt, -1, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    split(l-1);
    int L = calc(0, 0, 1);
    L = dp[0][0][1];
    cout << (R - L + MOD)%MOD << "\n";

    return 0;
}

