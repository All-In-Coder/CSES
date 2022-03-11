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


int sum = 0;
vector<vector<int>>dp;

int solve(int arr[], int n, int m, int index, int pre)
{
    if(index!=n and pre!=0 and arr[index]!=0 and  abs(pre-arr[index])>1)
        return 0;

    if(index==n)
    {
        return 1;
    }

    if(dp[index][pre]!=-1)
        return dp[index][pre];

    int ans = 0;
    if(arr[index]==0)
    {
        if(pre==0)
        {
            for(int i=1;i<=m;i++)
            {
                ans = (ans%MOD +  solve(arr,n,m,index+1,i)%MOD)%MOD;
            }
        }
        else
        {
            if(pre-1>0){
                ans= (ans%MOD + solve(arr,n,m,index+1,pre-1)%MOD)%MOD;
            }


            ans = (ans%MOD + solve(arr,n,m,index+1,pre)%MOD)%MOD;

            if(pre+1<=m)
                ans = (ans%MOD + solve(arr,n,m,index+1,pre+1)%MOD);
        }
    }
    else if(pre!=0 and abs(arr[index]-pre)>1)
        return 0;

    else
        ans = (ans%MOD + solve(arr,n,m,index+1,arr[index])%MOD)%MOD;

    return dp[index][pre] = ans%MOD;
    

}

int main()
{
    run();
    int n,m;
    cin>>n>>m;
    int arr[n];

    loop(i,0,n)
        cin>>arr[i];

    dp.resize(n+1, vector<int>(m+1,-1));

    cout<<solve(arr,n,m,0,0);


}
        