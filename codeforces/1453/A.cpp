#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> u(101, 0);
        int tmp;
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            u[tmp] = 1;
        }
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            cin >> tmp;
            if(u[tmp]) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
