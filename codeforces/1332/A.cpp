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
     cin >> t;
     while(t--)
     {
     	int a, b, c, d;
     	cin >> a >> b >> c >> d;
     	int x, y, x1, y1, x2, y2;
     	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
     	if(((x == x1 and x == x2 ) and (a or b)) or ((y==y1 and y==y2) and (c or d)))
     	{
     		cout << "No\n";
     		continue;
     	}
     	int aa =  max(a-b, 0LL), bb = max(b-a, 0LL), cc = max(c-d, 0LL), dd = max(d-c, 0LL);
     	if((x-x1 < aa) or (x2-x) < bb or (y-y1) < cc or (y2-y) < dd)
     		cout << "No\n";
     	else cout << "Yes\n";
     }
     return 0;
 }
 
 