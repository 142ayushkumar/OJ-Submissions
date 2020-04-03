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
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        vector<int> s(n);
        bool check = true;
        int total=0, mx;
        vector<int> till(n+1, 0);
        for(int i=0;i<n;i++)
        {
            cin >> s[i];
            total += s[i];
            till[s[i]]++;
            if(till[s[i]] > 2) check = false;
        }
        set<int> st;
        int count = 0;
        vector<bool> used(n+1, false);
        int sum = 0;
        for(int i=1;i<n;i++)
        { 
            if(used[s[i-1]])
            {
                check = false;
                break;
            }
            used[s[i-1]] = true;
            count++;
            sum += s[i-1];
            if((i*(i+1))/2 == sum)
            {
                int sm = (i*(i+1))/2 + ((n-i)*(n-i+1))/2;
                if(sm != total)
                    continue;
                st.insert(i);
            }
        }
        reverse(all(s));
        count = 0;
        used.assign(n+1, false);
        sum = 0;
        vector<int> ans;
		for(int i=1;i<n;i++)
        { 
            if(used[s[i-1]])
            {
                check = false;
                break;
            }
            used[s[i-1]] = true;
            count++;
            sum += s[i-1];
            if((i*(i+1))/2 == sum)
            {
                int sm = (i*(i+1))/2 + ((n-i)*(n-i+1))/2;
                if(sm != total)
                    continue;
                if(st.find(n-i) != st.end())
                    ans.push_back(n-i);
            }
        }

        cout << ans.size() << "\n";
        for(auto i:ans)
            cout << i << " " << n-i << "\n";
    }
    return 0;
}

