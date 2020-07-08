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

int get(int a, int b)
{
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int z = get(0, 0);
    int a = 0, b = 0;
    for(int i=29;i>=0;i--)
    {
        if(z == 1)
        {
            // a > b 
            // either 1 0 or 0 0 or 1 1
            int x = get(a, b + (1<<i)), y = get(a + (1<<i), b);
            if(x == y or x == 0 or y == 0)
            {
                // different bits
                a += (1<<i);
                z = x;
            }
            else if(x == 1 and y == -1)
            {
                a += (1<<i);
                b += (1<<i);
            }
        }
        else if(z == -1)
        {
            int x = get(a + (1<<i), b), y = get(a, b + (1<<i));
            if(x == y or x == 0 or y == 0)
            {
                b += (1<<i);
                z = x;
            }
            else if(x == -1 and y == 1)
            {
                a += (1<<i);
                b += (1<<i);
            }
        }
        else
        {
            // equal
            int x = get(a, b + (1<<i));
            if(x == 1)
            {
                a += (1<<i);
                b += (1<<i);
            }
        }
    }
    cout << "! " << a << " " << b << "\n";
    return 0;
}

