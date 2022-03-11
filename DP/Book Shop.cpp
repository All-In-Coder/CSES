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

unordered_map<string,int>dp;

int solve(int pages[], int price[], int index, int n, int total)
{
    vector<vector<int>>dp(n+1, vector<int>(total+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=total;j++)
        {
            if(j>=pages[i-1])
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-pages[i-1]]+price[i-1]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][total];
}   

int main()
{
    // run();
    int n,total;
    cin>>n>>total;

    int pages[n], price[n];
    loop(i,0,n)
        cin>>pages[i];
    loop(i,0,n)
        cin>>price[i];

    cout<<solve(pages,price,0,n,total);

}
        