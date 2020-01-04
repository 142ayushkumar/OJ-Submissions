/* same as codeforces round 599 b */
#include <bits/stdc++.h>


using namespace std;

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
const int N = (int)2e5 + 5;
set<int> graph[N];
int n, m;
vector<int> sz_connected;
set<int> not_visited; 

void dfs(int node, int& curr_num)
{
    int icurr_num = curr_num;
    curr_num++;
    vector<int> call;
    for(auto it = not_visited.begin();it != not_visited.end();)
    {
        if(graph[node].find(*it) == graph[node].end())
        {
            int y = *it;
            it = not_visited.erase(it);
            dfs(y, curr_num);
            it = not_visited.upper_bound(y);

        }
        else it++;
    }
    if(icurr_num == 0) 
    {
        sz_connected.push_back(curr_num);
    }
}


int32_t main()
{
    fastio;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    for(int i=1;i<=n;i++) not_visited.insert(i);
    for(int i=1;i<=n;i++)
    {
        if(not_visited.find(i) != not_visited.end())
        {
            not_visited.erase(i);
            int curr_size = 0;
            dfs(i, curr_size);
        }
    }
    cout << sz_connected.size() << "\n";
    sort(all(sz_connected));
    for(int i:sz_connected) cout << i << " ";
    cout << "\n";
    return 0;
}

