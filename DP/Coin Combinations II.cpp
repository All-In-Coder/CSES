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


int solve(int n, int sum, int arr[],int index)
{
    vector<int>dp(sum+1,0);
    dp[0] = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(arr[i]<=j)
                dp[j] = (dp[j]+dp[j-arr[i]])%MOD;
        }
    }
    return dp[sum];
}

int main()
{
    run();
    int n,sum;
    cin>>n>>sum;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int index = 0;
    int ans = solve(n,sum,arr,index);
    cout<<ans;
}
        