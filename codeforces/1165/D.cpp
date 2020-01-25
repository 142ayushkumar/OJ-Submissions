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

const int N = (int)1e6 + 5;
vector<int> seive(N);

void f()
{
    for(int i=0;i<N;i++) seive[i] = i;
    for(int i=2;i<N;i++)
    {
        if(seive[i] != i) continue;
        for(int j=2*i;j<N;j+=i)
        {
            seive[j] = i;
        }
    }
}


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int t;
    cin >> t;
    f();
    while(t--)
    {
        int n;
        cin >> n;
        if(n == 0)
        {
            cout << "1\n";
            continue;
        }
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(all(a));
        int curr_ans = a[n-1];
        set<int> prime;
        for(int i=0;i<n;i++)
        {
            int curr = a[i];
            while(curr > 1)
            {
                prime.insert(seive[curr]);
                curr /= seive[curr];
            }
        }
        int ans = curr_ans*(*prime.begin());
        bool check = true;
        for(int i=0;i<n;i++)
        {
            if(ans%a[i])
            {
                check = false;
                break;
            }
        }
        map<int, int> n_factor;
        int curr = curr_ans;
        while(curr > 1)
        {
            n_factor[seive[curr]]++;
            curr /= seive[curr];
        }
        n_factor[(*prime.begin())]++;
        int count = 1;
        for(auto i: n_factor)
            count *= (i.second  + 1);
        count -= 2;
        if(n != count || !check)
        {
            cout << "-1\n";
        }
        else cout << ans << "\n";

    
    }
    return 0;
}

