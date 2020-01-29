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
    int n, q;
    cin >> n >> q;
    while(q--)
    {
        int z;
        cin >> z;
        string s;
        cin >> s;
        for(int i=0;i<s.length();i++)
        {	
			int a = 1, temp = z;
			while(temp%2 == 0)
			{
				temp/=2;
				a *= 2;
			}
			a/=2;

            if(s[i] == 'L')
            {
                if(z %2) continue; // leaf
                else z-=a;
            }
            else if(s[i] == 'R')
            {
                if(z%2) continue;
                z+=a;
            }
            else
            {
                if(z == (n+1)/2) continue;
                // check if this is a right node or left node
                a*=2;
                if(a == 0) a = 1;
                int p1 = 0, p2 = 0, t1 = z-a, t2 = z+a;
                if(t1 == 0)
                {
                    z += a;
                    continue;

                }
                else if(t1 == n)
                {
                    z -= a;
                    continue;
                }
                while(t1%2 == 0 && t1)
                {
                    t1/=2;
                    p1++;
                }
                while(t2%2 == 0 && t2)
                {
                    t2 /= 2;
                    p2++;
                }

                if(p1 > p2)
                {
                    z+=a;
                }
                else z-=a;
            }
        }
        cout << z << "\n";
    }


    return 0;
}

