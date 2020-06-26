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
    string s;
    cin >> s;
    int n = s.size();
    list<pair<char, int>> l;
    char curr = s[0];
    int count = 1;
    for(int i=1;i<n;i++)
    {
    	if(s[i] != curr)
    	{
    		l.push_back({curr, count});
    		count = 1;
    		curr = s[i];
    	}
    	else
    	{
    		count++;
    	}
    }
    l.push_back({curr, count});
    int ans = 0;
    while(l.size() > 1)
    {
    	auto it = l.begin();
    	auto first = it, last = l.end();
    	last--;
    	while(it != l.end())
    	{
    		assert((*it).second > 0);
    		(*it).second--;
    		if((*it).second and it!= first and it!= last)
    		{
    			(*it).second--;
    		}
	    	if((*it).second == 0) // remove and merge if pos
	    	{
	    		l.erase(it++);
	    		auto next = it, prev = --it;
	    		it++;
	    		if(!(it == l.begin() or it == l.end()))
	    		{
	    			if((*prev).first == (*next).first) // merge these two
	    			{
	    				int k = 1;
	    				if(next != last) k = 2;
	    				if((*next).second == 1) k = 1; // last tle was due to this
	    				(*prev).second += (*next).second - k;
	    				// erase next
	    				l.erase(it++);
	    			}
	    		}
	    	}
	    	else
	    	{
	    		it++;
	    	}
	    }
	  	// prc(all(l));
	    ans++;
    }
    cout << ans << "\n";
    return 0;
}

