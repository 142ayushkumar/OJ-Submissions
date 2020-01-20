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

void f(int l, int r, int p, int q)
{
	cout << r-l+1 << " " << q-p+1 << " ";
	for(int i=l;i<=r;i++) cout << i << " ";
	for(int i=p;i<=q;i++) cout << i << " ";
	cout << "\n";
	cout.flush();
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
        int n, ans = 0;
        cin >> n;
        vector<pair<int, int>> a, b, c, d;
        a.pb({1, n/2});
        b.pb({n/2+1, n});
        for(int i=1;i<10;i++)
        {
            int sza=0, szb = 0;
            for(auto j:a)
                sza += j.second - j.first + 1;
            for(auto j:b)
                szb += j.second - j.first + 1;
            if(sza == 0 || szb == 0) break;
            cout << sza << " " << szb;
            for(auto j: a)
                for(int k=j.first;k<=j.second;k++)
                    cout << " " << k;
            for(auto j:b)
                for(int k=j.first;k<=j.second;k++)
                    cout << " " << k;
            cout << "\n";
            cout.flush();
            int temp;
            cin >> temp;
            ans = max(ans, temp);
            c.clear();
            d.clear();
            for(auto j:a)
            {
                int mid = (j.first + j.second)/2;
                c.pb({j.first, mid});
                d.pb({mid+1, j.second});
            }
            for(auto j:b)
            {
                int mid = (j.first + j.second)/2;
                c.pb({j.first, mid});
                d.pb({mid+1, j.second});
            }
            swap(a, c);
            swap(b, d);
                
        }
        cout << "-1 " << ans << "\n";
        cout.flush();


    }
    return 0;
}

