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

vector<int>dp;

int solve(int n, int sum, int arr[])
{
    if(sum==0)
        return 0;

    if(dp[sum]!=-1)
        return dp[sum];

    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=sum)
        {
            int temp_ans = solve(n,sum-arr[i],arr);
            if(temp_ans!=INT_MAX and temp_ans+1<ans)
                ans = temp_ans+1;
        }
    }
    return dp[sum] =  ans;

}

int main()
{
    // run();
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    loop(i,0,n)
        cin>>arr[i];

    
    dp.resize(sum+1,-1);
    int ans = solve(n,sum,arr);
    if(ans==INT_MAX)
        cout<<-1;
    else
        cout<<ans;
    
}
        