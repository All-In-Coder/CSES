#include<bits/stdc++.h>
using namespace std;


#define loop(i,l,n) for(long i=l;i<n;i++)
const long long MOD = 1000000007;
const long INF = 1e9;
typedef long long ll;
template<typename T> T gcd(T a, T b) {return (b ? __gcd(a, b) : a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}

template<typename T> T pow2(T a) {return a & (-a);}
template<typename T> void add(T a, T b, vector<T> graph[])
{    graph[a].push_back(b);
    graph[b].push_back(a);
};

template<typename T> void addW(long a, long b, long p, vector<pair<long, long>> graph[])
{    graph[a].push_back({b, p});
    graph[b].push_back({a, p});
};
    

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin); 
        freopen("outputf.in","w",stdout);
    #endif
}

int main()
{
    // run();
    int n;
    cin>>n;

    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];

    vector<vector<int>>dp(n,vector<int>(n,0));

    if(s[0][0]=='*')
        dp[0][0] = INT_MAX;
    else
        dp[0][0] = 1;

    for(int i=1;i<n;i++)
    {
        dp[0][i] = s[0][i]=='*'?INT_MAX: dp[0][i-1]==INT_MAX?INT_MAX:1;
        dp[i][0] = s[i][0]=='*'?INT_MAX: dp[i-1][0]==INT_MAX?INT_MAX:1;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(s[i][j]=='*')
                dp[i][j]=INT_MAX;
            else
            {
                
                if(dp[i-1][j]==INT_MAX and dp[i][j-1]==INT_MAX){
                    dp[i][j] = INT_MAX;
                    continue;
                }

                if(dp[i-1][j]!=INT_MAX)
                    dp[i][j]+=dp[i-1][j];

                if(dp[i][j-1]!=INT_MAX)
                    dp[i][j]+=dp[i][j-1];

                

                dp[i][j] = dp[i][j]%MOD;
            }
        }
    }
    
    if(dp[n-1][n-1]==INT_MAX)
        cout<<0;
    else
        cout<<dp[n-1][n-1];

}
        