#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repre(i,a,b)for(int i=a;i<=b;i++)
const int mod=1e9+7;
int calculateForSmall(vector<int>& arr)
{
    ll n=arr.size();
  stack<ll>s;
    ll small[n][3];
    memset(small,-1,sizeof(small));
  rep(i,n)
  {
    if(s.empty() || arr[s.top()]<=arr[i])
      s.push(i);
    else
    {
      while(!s.empty() && arr[s.top()]>arr[i])
      {
        small[s.top()][1]=i;
        s.pop();
      }
      s.push(i);
    }
  }
  while(!s.empty())s.pop();
  for(int i=n-1;i>=0;i--)
  {
    if(s.empty() || arr[s.top()]<arr[i])
      s.push(i);
    else
    {
      while(!s.empty() && arr[s.top()]>=arr[i])
      {
        small[s.top()][0]=i;
        s.pop();
      }
      s.push(i);
    }
  }
    ll ans=0;
  rep(i,n)
  {
    int low=small[i][0];
    int high=small[i][1];
    if(high==-1)high=n;
    small[i][2]=(high-i)*(i-low);
    ll res=arr[i]*small[i][2];
     ans=((ans%mod)+(res%mod))%mod;
  }
    return ans;
}
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        return calculateForSmall(A);
    }
};
