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
const int N = 2e6 + 5;
int BLOCK_SIZE = sqrt(N);

struct queries {
	int l, r, id;
}q;

int curr = 0;
void add(vector<int>& count, int x)
{
	curr -= (count[x]*count[x])*x;
	count[x]++;
	curr += (count[x]*count[x])*x;
}

void sub(vector<int>& count, int x)
{
	curr -= (count[x]*count[x])*x;
	count[x]--;	
	curr += (count[x]*count[x])*x;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    	cin >> v[i];
    vector<int> count(N, 0);
    queries q[t];
    for(int i=0;i<t;i++)
    {
    	cin >> q[i].l >> q[i].r;
    	q[i].id = i;
    	q[i].l--;
    	q[i].r--;
    }
    auto cmp = [&] (queries a, queries b) {
    	int x = a.l/BLOCK_SIZE, y = b.l/BLOCK_SIZE;
    	if(x == y)
    		return a.r < b.r;
    	return x < y;
    };
    sort(q, q+t, cmp);
   	vector<int> ans(t);
   	int l = 0, r = -1;
   	for(int i=0;i<t;i++)
   	{
   		while(l < q[i].l)
   		{
   			sub(count, v[l]);
   			l++;
   		}
   		while(l > q[i].l)
   		{
   			l--;
   			add(count, v[l]);
   		}
   		while(r < q[i].r)
   		{
   			r++;
   			add(count, v[r]);
   		}
   		while(r > q[i].r)
   		{
   			sub(count, v[r]);
   			r--;
   		}
   		ans[q[i].id] = curr;
   	}

   	for(int i=0;i<t;i++)
   		cout << ans[i] << "\n";

    return 0;
}

