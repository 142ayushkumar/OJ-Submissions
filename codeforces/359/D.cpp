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

int n;

/*
 * 1 based index, define N (max length of array possible)
 * Point update, increment of a[i] by b
 */
const int N = 3e5 + 5; // change n accordingly
int v[N];
int store[N][20];
void f()
{
	for(int i=0;i<n;i++)
	{
		store[i][0] = v[i];
	}
	for(int j=1;j<20;j++){
		for(int i=0;i+(1<<j)-1<n;i++){
			store[i][j]=__gcd(store[i][j-1],store[i+(1<<(j-1))][j-1]);
		}
	}
}
 
int get(int l,int r){
	int L = log2(r-l+1);
	return __gcd(store[l][L], store[r-(1<<L)+1][L]);
}
 

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n;
    for(int i=0;i<n;i++)
    {
    	cin >> v[i];
    }
    f();
    int ans = 0;
    set<int> store;
    for(int i=0;i<n;i++)
    {
    	// binary search left
    	int l = 0, r = i;
    	while(l < r)
    	{
    		int mid = (l+r)/2;
    		int g = get(mid, i);
    		if(g != v[i])
    		{
    			l = mid + 1;
    		}
    		else r = mid;
    	}
    	int L = l;
    	l = i;
    	r = n-1;
    	while(l < r)
    	{
    		int mid = (l+r+1)/2;
    		int g = get(i, mid);
    		if(g != v[i])
    		{
    			r = mid-1;
    		}
    		else l = mid;
    	}
    	int R = l;
    	if(ans < R-L)
    	{
    		ans = R - L;
    		store.clear();
    		store.insert(L);
    	}
    	else if(ans == R-L)
    	{
    		store.insert(L);
    	}
    }
    cout << store.size() << " " << ans << "\n";
    for(int i:store)
    	cout << i+1 << " ";
    cout << "\n";

    return 0;
}
 