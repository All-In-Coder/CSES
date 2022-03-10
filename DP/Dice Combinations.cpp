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

vector<long>dp;

long solve(int n)
{
    if(n==0 or n==1)
        return 1;

    if(n<0)
        return 0;

    if(dp[n]!=-1)
        return dp[n];

    long ans = 0;
    for(int i=1;i<=6;i++)
    {
        ans = (ans%MOD + solve(n-i)%MOD)%MOD;
    }

    return dp[n] =  ans%MOD;
}

int main()
{
    // run();
    int n;
    cin>>n;

    dp.resize(n+1,-1);
    long ans = solve(n);
    cout<<ans;

}
        