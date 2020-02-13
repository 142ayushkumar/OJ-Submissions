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


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    if(k > 4*n*m - 2*n - 2*m) 
    {
        cout << "NO\n";
        return 0;
    }
    // handle case with m == 1
    cout << "YES\n";
    vector<pair<int, string>> ans;
    if(m == 1)
    {
        int z = min(n-1, k);
        k -= z;
        ans.push_back({z, "D"});
        if(k > 0)
        {
            int z = min(n-1, k);
            ans.push_back({z, "U"});
            k-= z;
        }
        cout << ans.size() << "\n";
        for(auto &i: ans)
        {
            cout << i.first << " " << i.second << "\n";
        }

        return 0;
    }
    int curr_row = 0;
    while(k > 0)
    {
        if(curr_row >= n) break;
        if(curr_row == n-1)
        {
            if(k > 0)
            {
                int z = min(m-1, k);
                ans.push_back({z, "R"});
                k -= z;
            }
            if(k > 0)
            {
                int z = min(m-1, k);
                ans.push_back({z, "L"});
                k -= z;
            }
            break;
        }
        if(m > 1)
        {
            if(k >= (m-1)*3)
            {
                ans.push_back({m-1, "RDU"});
                k-= (m-1)*3;
            }
            else
            {
                int z = k/3;
                if(z)
                    ans.push_back({z, "RDU"});
                k %= 3;
                if(k == 1)
                    ans.push_back({1, "R"});
                else if(k == 2)
                    ans.push_back({1, "RD"});
                k = 0;
            }
            if(k >= (m-1))
            {
                ans.push_back({m-1, "L"});
                k -= m-1;
            }
            else
            {
                int z = min(k, m-1);
                if(z) 
                    ans.push_back({z, "L"});
                k -= z;
            }
        }
        if(k > 0)
        {
            k--;
            ans.push_back({1, "D"});
        }
        curr_row++;
    }
    if(k > 0)
    {
        int z = min(k, n-1);
        k -= z;
        ans.push_back({z, "U"});
    }

    cout << ans.size() << "\n";
    for(auto& i: ans)
    {
        cout << i.first << " " << i.second << "\n";
    }
        

    return 0;
}

