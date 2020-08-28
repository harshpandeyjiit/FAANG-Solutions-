#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repre(i,a,b)for(int i=a;i<=b;i++)
using namespace std;
int fun(int a)
{
  if(a==0)
    return 1;
  int ct=0;
  while(a)
  {
    a=a&(a-1);
    ct++;
  }
  return ct;
}
string fun2(int n)
{
  if(n==0)
    return "0";
   string res="";
   int i = 0;
   while (n > 0) {
       if(n%2)res+='1';
       else res+='0';
       n = n / 2;
       i++;
   }
   reverse(res.begin(),res.end());
   return res;
}
int32_t main()
{
  int n;
  cin>>n;
  int maxe=0;
  int a[n];
  rep(i,n)
  {
    cin>>a[i];
    maxe=max(maxe,a[i]);
  }
  int maxBits=(int)log2(maxe) + 1;
  int count=0;
  repre(i,1,(1<<n)-1)
  {
    int ones=0;
    int zeroes=0;
    rep(j,n)
    {
      if(i & (1<<j))
      {
        int res=fun(a[j]);
        ones+=res;
        zeroes+=maxBits-res;
      }
    }
    if(ones==zeroes)count++;
  }
  string ans="";
  int bitsInAns;
  if(count==0)bitsInAns=1;
  else
   bitsInAns=(int)log2(count) + 1;
  if(bitsInAns>maxBits)
  {
 	string temp=fun2(count);
    string res="";
    for(int i=temp.size()-1;i>=0;i--)
    {
      if(maxBits==0)break;
      res+=temp[i];
      maxBits--;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    exit(0);
  }
  int zeroesToAppend=maxBits-bitsInAns;
  rep(i,zeroesToAppend)ans+='0';
  string temp=fun2(count);
  ans+=temp;
  cout<<ans<<endl;
  return 0;
}
