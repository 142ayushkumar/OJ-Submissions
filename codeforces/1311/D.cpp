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
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >>  a >> b >> c;
        int ans = a-1 + b-1;
        int fa = 1, fb = 1, fc = c;
        // make all equal to a
        if((b-a + c-b) < ans)
        {
            ans = b-a + c-a;
            fa = b;
            fb = b;
            fc = b;
        }
        for(int i=1;i<=2*a;i++)
        {
            for(int j=i;j<=2*b;j+=i)
            {
                int c1 = (c/j)*j, c2 = (c/j)*j + j;
                int z = abs(c1 - c) + abs(b-j) + abs(a-i);

                if(z < ans && c1 >= j)
                {
                    ans = z;
                    fa = i;
                    fb = j;
                    fc=c1;
                }
                z = abs(c2-c) + abs(b-j) + abs(a-i);
                if(z < ans && c2 >= j)
                {
                    ans = z;
                    fa = i;
                    fb = j;
                    fc = c2;
                }

            }
        }
        cout << ans << "\n";
        cout << fa << " " << fb << " " << fc << "\n";

    }


    return 0;
}

