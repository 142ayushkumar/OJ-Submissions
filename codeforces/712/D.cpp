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

int a, b, k, t;

const int MAX = 1e5 + 1e2 + 5;


int ipow(int base, int exp)
{
    int ans = 1;
    while(exp > 0)
    {
        if(exp&1)
            ans = (ans*base)%M;
        base = (base*base)%M;
        exp >>= 1;
    }
    return ans;
}

int fact[2*MAX+1];
int inv_fact[2*MAX+1];

int nck(int n, int k)
{
	if(k > n) return 0;
	int ans = (fact[n]*inv_fact[k])%M;
	ans = (ans*inv_fact[n-k])%M;
	return ans;
}


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> a >> b >> k >> t;
    
    fact[0] = 1;
    for(int i=1;i<=2*MAX;i++)
    	fact[i] = (fact[i-1]*i)%M;

    inv_fact[2*MAX] = ipow(fact[2*MAX], M-2);
    for(int i=2*MAX-1;i>0;i--)
    	inv_fact[i] = (inv_fact[i+1]*(i+1))%M;

    inv_fact[0] = 1;

   	vector<int> dp1(2*MAX+1, 0), dp2(2*MAX+1, 0);
   	for(int i=a;i<=a+2*k*t;i++)
   	{
   		dp1[i] = nck(i+t-1-a, t-1);
   		int neg = 0, sign = 1;
   		for(int j=1;j<=t;j++)
   		{
   			neg = (neg + nck(t, j)*nck(i+t-1-a-(2*k+1)*j, t-1)*sign)%M;
   			sign *= -1;
   		}
   		dp1[i] = (dp1[i] -neg + M)%M;
   	}

   	for(int i=b;i<=b+2*k*t;i++)
   	{
   		dp2[i] = nck(i+t-1-b, t-1);
   		int neg = 0, sign = 1;
   		for(int j=1;j<=t;j++)
   		{
   			neg = (neg + nck(t, j)*nck(i+t-1-b-(2*k+1)*j, t-1)*sign)%M;
   			sign *= -1;
   		}
   		dp2[i] = (dp2[i] -neg + M)%M;
   	}

   	for(int i=1;i<=2*MAX;i++)
   		dp2[i] = (dp2[i] + dp2[i-1])%M;

   	int ans = 0;
   	for(int i=1;i<=2*MAX;i++)
   	{
   		ans = (ans + dp1[i]*dp2[i-1])%M;
   	}

   	cout << ans << "\n";


    return 0;
}

