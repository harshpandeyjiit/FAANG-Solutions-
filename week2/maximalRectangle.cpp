int histoGram(vector<int>& temp)
{
    int n=temp.size();
    int maxe=0;
    stack<int>s;
    int i=0;
    for(int i=0;i<n;i++)
    {
        if(s.empty() || temp[s.top()]<=temp[i])
            s.push(i);
        else
        {
            while(s.empty()==false && temp[s.top()]>temp[i])
            {
                int index=s.top();
                s.pop();
                int right=i;
                int left=(s.empty())?-1:s.top();
                int area=temp[index]*(right-left-1);
                maxe=max(maxe,area);
            }
            s.push(i);

        }
    }
    while(s.empty()==false)
    {
        int curr=s.top();
        s.pop();
        int right=n;
        int left=(s.empty())?-1:s.top();
        int area=temp[curr]*(right-left-1);
        maxe=max(maxe,area);
    }
    return maxe;
}
class Solution {
public:
    /**
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        // write your code here
        int n=matrix.size();
             if(n==0)
            return 0;
        int m=matrix[0].size();
        int maxArea=0;

        vector<vector<int> >temp(n,vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                temp[i][j]=(matrix[i][j])?1:0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] && i!=0)
                    temp[i][j]+=temp[i-1][j];
            }
            maxArea=max(maxArea,histoGram(temp[i]));
        }
        return maxArea;
    }
};
