#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    unordered_map<int, int> mp, tr;
    mp.reserve(1024*512);
    tr.reserve(1024*512);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        mp[v[i]] = 1;
        tr[v[i]] = 1;
    }
    int count = 0, curr = 1;
    long long ans = 0;
    deque<int> dq(n);
    sort(all(v));
    for(int i=0;i<n;i++) dq[i] = v[i];
    while(count < m)
    {
        vector<int> dlt;
        for(int i=0;i<dq.size();i++)
        {
            int tree = dq.at(i);
            int z = tree + curr, y = tree-curr;
            bool a = (mp.find(z) != mp.end()), b = (mp.find(y) != mp.end());
            if(a && b)
            {
                dlt.pb(i);
            }
            if(!a)
            {
                ans += curr;
                mp[z] = 1;
                count++;
                if(count >= m) break;
            }
            if(!b)
            {
                ans += curr;
                mp[y] = 1;
                count++;
                if(count >= m) break;
            }
        }
        int tmp = dlt.size();
        for(int i=tmp-1;i>=0;i--)
            dq.erase(dq.begin() + dlt[i]);
        curr++;

    } 
    cout << ans << "\n"; 
    for(auto& i: mp) 
    {
        int z = i.first;
        if(tr[z]) continue;
        else cout << z << " ";
    }
    cout << "\n";
        
    return 0;
}

