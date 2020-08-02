class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rows=n;
        int cols=n;
        int r=0;
        int c=0;
        vector<vector<int> >arr(n,vector<int>(n));
        int ct=1;
        while(r<rows && c<cols)
        {
            for(int j=c;j<cols;j++)
                arr[r][j]=ct++;
            r++;
            for(int i=r;i<rows;i++)
                arr[i][cols-1]=ct++;
            cols--;
            for(int j=cols-1;j>=c;j--)
                arr[rows-1][j]=ct++;
            rows--;
            for(int i=rows-1;i>=r;i--)
                arr[i][c]=ct++;
            c++;
        }
        return arr;
    }
};
