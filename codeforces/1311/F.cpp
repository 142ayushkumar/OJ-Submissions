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

const int N = 2e5 + 5;
int n;
vector<pair<int,int>> v;
/*
 * Sorting the points with x coordinates and will update fenwick tree
 * for after processing every points from left to right 
 * for say ith point from left sum of all those points with velocity less 
 * than velocity of this ith point will contribute in final answer
 * since -1e8 < v < 1e8 use compression
 */
struct BIT {
    vector<int> T, COUNT;
    int n;
    BIT(int _n = N) {
        T.resize(_n + 1, 0);
        COUNT.resize(_n+1, 0);
        n = _n;
    }
    int sum(int idx){
        int sum_ = 0;
        while (idx > 0){
            sum_ += T[idx];
            idx -= (idx & -idx);
        }
        return sum_;
    }
    int count(int idx){
        int count_ = 0;
        while(idx > 0)
        {
            count_ += COUNT[idx];
            idx-= (idx & -idx);
        }
        return count_;
    }
    int sum(int l, int r)
    {
        return sum(r) - sum(l-1);
    }
    void update(int idx, int val){
        while (idx <= n){
            COUNT[idx] += 1;
            T[idx] += val;
            idx += (idx & -idx);
        }
    }
};

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>> v[i].first;
    }
    for(int i=0;i<n;i++)
    {
        cin >> v[i].second;
    }
    // compression
    map<int, int> compress;
    sort(all(v), cmp);
    // starting index = 1
    int index = 1, curr = -1e9;
    for(int i=0;i<n;i++)
    {
        if(curr == v[i].second)
            continue;
        else
        {
            compress[v[i].second] = index;
            curr = v[i].second;
            index++;
        }
    }

    sort(all(v));
    int ans = 0;
	BIT ft(n);
    for(int i=0;i<n;i++)
    {
        ans -= ft.sum(compress[v[i].second]);        
        ans += v[i].first*ft.count(compress[v[i].second]);
        ft.update(compress[v[i].second], v[i].first);
    }
    cout << ans << "\n";

    return 0;
}

