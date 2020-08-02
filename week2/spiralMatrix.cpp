class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        if(matrix.size()==0)
                return ans;
        int r=0;
        int c=0;
        int n=matrix.size()-1;
        int m=matrix[0].size()-1;
        if(n==0)
        {
            return matrix[0];
        }
        else if(m==0)
        {
            vector<int>ans;
            for(int i=0;i<=n;i++)
                    ans.push_back(matrix[i][0]);
            return ans;
        }
        while(n>=r && m>=c)
        {
            for(int j=c;j<=m;j++)
                    ans.push_back(matrix[r][j]);
            r++;
            for(int i=r;i<=n;i++)
                    ans.push_back(matrix[i][m]);
            m--;
            for(int j=m;j>=c;j--)
                    ans.push_back(matrix[n][j]);
            n--;
            for(int i = n;i>=r;i--)
                    ans.push_back(matrix[i][c]);
            c++;
           /* if(n==r)
            {
                for(int j=c;j<=m;j++)
                        ans.push_back(matrix[n][j]);
                break;
            }
            else if(m==c)
            {
                for(int i=r;i<=n;i++)
                        ans.push_back(matrix[i][m]);
                break;
            }*/
            cout<<n<<" "<<r<<" "<<m<<" "<<c<<endl;
        }
        return ans;
    }
};
