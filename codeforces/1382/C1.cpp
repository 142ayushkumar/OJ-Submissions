#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define eb emplace_back
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

void rev(string& s, int l, int r)
{
    for(int i=l;i<=r;i++)
    {
        if(s[i] == '1') s[i] = '0';
        else s[i] = '1';
    }
    int n = r-l+1;
    for(int i=0;i<n/2;i++)
    {
        char temp = s[l+i];
        s[l+i] = s[r-i];
        s[r-i] = temp;
    }
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int count = 0;
        vector<int> v;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i] != b[i])
            {
                if(a[0] == b[i])
                {
                    count++;
                    if(a[0] == '1') a[0] = '0';
                    else a[0] = '1';
                    v.eb(1);
                }
                count++;
                v.eb(i+1);
                rev(a, 0, i);
            }
        }
        cout << count << " ";
        for(int i=0;i<count;i++)
            cout << v[i] << " ";
        cout << "\n";

    }

    return 0;
}

