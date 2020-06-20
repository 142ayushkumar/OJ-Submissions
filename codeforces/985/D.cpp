#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define int long long
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
    int n, H;
    cin >> n >> H;
    int l = 1, r = 2e9;
    while(l < r)
    {
    	int mid = (l + r + 1)/2;
    	int sum = (mid*(mid+1))/2;
   		if(sum > n)
   			r = mid-1;
   		else l = mid;
    }
    l = min(l, H);
    int used = l;
    int used_sum = (used*(used+1))/2;
  	int diff = n - used_sum;
  	if(diff)
  	{
  		used += diff/l;
  		diff %= l;
  		if(diff) used++;
  	}
    int ans = 0;
  	// can use go like h+1 ..... max ... 1 and how many steps will this take
  	l = H, r = 2e9;
  	while(l < r) 
  	{
  		int mid = (l+r+1)/2;
  		int sum = (mid*(mid+1)) - (H*(H-1))/2 - mid;
  		if(sum > n) r = mid-1;
  		else l = mid;
  	}
  	ans = 2*l - H;
  	diff = n - ((l*(l+1)) - (H*(H-1))/2 - l);
  	if(diff)
  	{
  		ans += diff/l;
  		diff %= l;
  		if(diff) ans++;
  	}
  	cout << min(ans, used) << "\n";
    return 0;
}