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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool is_beautiful = true;
    for(int i=0;i<n-k;i++)
    {
        if(s[i] != s[i+k])
        {
            is_beautiful = false;
        }
    }
    cout << n << "\n";
    if(is_beautiful)
    {
        cout << s << "\n";
        return 0;
    }
    int z = k-1;
    while(s[z] == '9' && z > 0) z--;
    bool check = true;
    for(int i=k;i<n;i++)
    {
        if(s[i%k] < s[i])
        {
            check = false;
            break;
        }
        else if(s[i%k] > s[i]) break;
    }
    if(check)
    {
        for(int i=0;i<n;i++)
            cout << s[i%k];
        cout << "\n";
        return 0;
    }
    assert(s[z] != '9');
    if(s[z] != '9')
    	s[z] = (s[z] + 1);
    for(int i=z+1;i<k;i++) s[i] = '0';
    for(int i=0;i<n;i++)
    {
        cout << s[i%k];
    }
    cout << "\n";
    return 0;
}

