int fun(vector<int>& v,int k)
{
    int prefSum=0;
    set<int>s;
    s.insert(0);
    int res=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        prefSum+=v[i];
        auto it=s.lower_bound(prefSum-k);
        if(it!=s.end())
                res=max(res,prefSum-(*it));
        s.insert(prefSum);
    }
    return res;
}
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int ans=INT_MIN;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int j=0;j<m;j++)
        {
            vector<int>temp(n,0);
            for(int k=j;k<m;k++)
            {
                for(int i=0;i<n;i++)
                        temp[i]+=matrix[i][k];
                ans=max(ans,fun(temp,K));
            }
        }
        return ans;

    }
};
