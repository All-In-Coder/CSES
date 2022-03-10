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
int solve(int n)
{
    if(n==0)
        return 0;

    if(n<=9)
        return 1;
    
    if(dp[n]!=-1)
        return dp[n];

    set<int>store;
    int num = n;
    while(num)
    {
        store.insert(num%10);
        num/=10;
    }

    int ans = INT_MAX;
    for(int x:store)
    {
        if(n-x>=0 and x!=0)
        {
            ans = min(ans,1+solve(n-x));
        }
    }
    return dp[n] =  ans;
}

int main()
{
    run();
    int n;
    cin>>n;
    dp.resize(n+1,-1);
    cout<<solve(n);

}
        