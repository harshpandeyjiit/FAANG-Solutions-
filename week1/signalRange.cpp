#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        arr[0]=0;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(arr[i]<arr[i-1])
            {
                dp[i]=1;
                continue;
            }
            else
            {
                int ans=1;
                int temp=i-1;
                while(temp>0 && arr[i]>=arr[temp])
                {
                    ans+=dp[temp];
                    temp-=dp[temp];
                }
                dp[i]=ans;
            }
        }
        for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
        cout<<endl;
    }
    return 0;
}
