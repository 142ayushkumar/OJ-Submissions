#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v[n+1];
        for(int i=1;i<n;i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(v[x].size() <= 1 || n%2 == 0)
            cout << "Ayush\n";
        else cout << "Ashish\n";

    }
    return 0;
}
