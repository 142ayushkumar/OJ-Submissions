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
    int k, a, b;
    cin >> k >> a >> b;
    vector<vector<int>> A(3, vector<int>(3)), B(3, vector<int>(3));
    int n = 3;
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++)
        {
            cin >> A[i][j];
        }
    }
	for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++)
        {
            cin >> B[i][j];
        }
    }
    map<pair<int, int>, int> used;
    int x = a, y = b, sa = 0, sb = 0;
    int period = 1;
    vector<pair<int, int>> score(100000);
    while(used.find({x, y}) == used.end())
    {
        used[{x, y}] = period;
        if(x == 3 && y == 2)
            sa++;
        else if(x == 2 && y == 3)
            sb++;
        else if(x == 2 && y == 1)
            sa++;
        else if(x == 1 && y == 2)
            sb++;
        else if(x == 1 && y == 3)
            sa++;
        else if(x == 3 && y == 1) 
            sb++;
        score[period] = {sa, sb}; 
        int xx = A[x-1][y-1], yy = B[x-1][y-1];
        x = xx;
        y = yy;
        period++;
    }
    int repeat = period - used[{x, y}];
    int abcd = used[{x, y}];
    if(k < used[{x, y}] - 1)
    {
        cout << score[k].first << " " << score[k].second << "\n";
        return 0;
    }
    k -= used[{x, y}] - 1;
    if(k < 0)
    {
        cout << score[k] << "\n";
    }
    int times = k/repeat;
    sa -= score[used[{x, y}]-1].first;
    sb -= score[used[{x, y}]-1].second;
    pair<int,int> ans = {sa*times, sb*times};
    ans.first += score[used[{x, y}] - 1].first;
    ans.second += score[used[{x, y}] - 1].second;
    int z = k%repeat;
    if(z)
    {
        ans.first += score[used[{x, y}] + z-1].first - score[used[{x, y}]-1].first;
        ans.second += score[used[{x, y}] + z-1].second - score[used[{x, y}]-1].second;
    }

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}

