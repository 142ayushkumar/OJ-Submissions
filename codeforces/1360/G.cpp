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
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<vector<int>> v(n, vector<int>(m, 0));
        bool pos = true;
        set<pair<int, int>> s;
        vector<int> dict(m, 0);
        vector<int> used(m, 0);
        for(int i=0;i<m;i++)
            s.insert({0, i});

        for(int i=0;i<n;i++)
        {
            int tot = a, j;
            while(tot > 0)
            {
                j = (*s.begin()).second;
                int val = (*s.begin()).first;
                if(val < b and used[j] == 0)
                {
                    v[i][j] = 1;
                    dict[j]++;
                    s.erase({val, j});
                    tot--;
                    s.insert({val+1, j});
                    used[j] = 1;
                }
                else
                {
                    pos=false;
                    break;
                }
            }
            if(tot)
            {
                pos=false;
                break;
            }
            used.assign(m, 0);
        }
        for(int i=0;i<m;i++)
            if(dict[i] != b) pos=false;
        if(pos)
        {
            cout << "YES\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cout << v[i][j];
                cout << "\n";
            }
                
        }
        else cout << "NO\n";
        
    }
    return 0;
}

