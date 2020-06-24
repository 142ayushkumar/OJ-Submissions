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

const int MAX = 1e6 + 5;

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(m), a(k);
    for(int i=0;i<m;i++)
    	cin >> s[i];
    for(int i=0;i<k;i++)
    	cin >> a[i];
    if(!m)
    {
    	int ans = 1e18;
    	for(int i=0;i<k;i++)
    	{
    		int times = (n-1)/(i+1) + 1;
    		ans = min(ans, times*a[i]);
    	}
    	cout << ans << "\n";
    	return 0;
    }
    if(s[0] == 0) 
    {
    	cout << "-1\n";
    	return 0;
    }
    int last = s[0], cont = 1, curr = 1;
    for(int i=1;i<m;i++)
    {
    	if(last != s[i]-1)
    	{
    		cont = max(curr, cont);
    		curr = 1;
    	}
    	else 
    		curr++;
    	last = s[i];
    	// pr(i, curr);
    }
   	cont = max(curr, cont);
    cont++;
    vector<int> pos(MAX, 0);
    for(int i=0;i<m;i++)
    {
    	pos[s[i]] = 1;
    }
    int cost = 1e18;
    vector<int> free;
    int ptr = 0;
    for(int i=1;i<=n;i++)
    {
        if(ptr < n and s[ptr] == i)
        {
            ptr++;
        }
        else free.pb(i);
    }
    // pr(cont);
    for(int i=cont-1;i<k;i++)
    {
    	int l = i+1;
    	int num_req = 1;
    	int start = l;
    	while(start < n)
        {
            if(pos[start]) 
            {
                // blocked
                start = *(lower_bound(all(free), start) - 1);
            }
            num_req++;
            start += l;
        }
    	cost = min(cost, num_req*a[i]);
    }

    if(cost == (int)1e18) cost = -1;
    cout << cost << "\n";
    return 0;
}

