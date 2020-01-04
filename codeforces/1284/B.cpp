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
    int n;
    cin >> n;
    vector<pair<int, int>> minmax(n); 
    vector<int> maxmin(n);
    vector<bool> accent(n, false);
    int acc_ = 0;
    for(int i=0;i<n;i++)
    {
        int m;
        cin >> m;
        int mn = -1, mx = -1;
        bool has_accent = false;
        for(int j=0;j<m;j++)
        {
            int z;
            cin >> z;
            if(!j)
            {
                mn = z;
                mx = z;
            }
            else
            {
                if(z > mn)
                {
                    has_accent = true;
                }
                mn = min(mn, z);
                mx = max(mx, z);
            }
        }
        if(has_accent) 
        {
            accent[i] = true;
            acc_++;
        }
        minmax[i] = {mn, mx};
        maxmin[i] = mx;
        if(has_accent) maxmin[i] = -1;
    }
    sort(all(maxmin));
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(accent[i]) ans += n;
        else
        {
            int z = upper_bound(all(maxmin), minmax[i].first) - maxmin.begin();
            z = n-z;
            z += acc_;
            ans += z;
        }
    }

    cout << ans << "\n";

    return 0;
}

