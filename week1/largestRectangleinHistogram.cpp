class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int>s;
        int n=heights.size();
        for(int i=0;i<heights.size();i++)
        {
            if(s.empty() || heights[s.top()]<=heights[i])
                    s.push(i);
            else
            {
                while(s.empty()==false && heights[s.top()]>heights[i])
                {
                    int curr=s.top();
                    s.pop();
                    int prev=(s.empty())?-1:s.top();
                    int area=heights[curr]*(i-prev-1);
                    ans=max(ans,area);
                }
                s.push(i);
            }
        }
        while(s.empty()==false)
        {
            int curr=s.top();
            s.pop();
            int prev=(s.empty())?-1:s.top();
            int area=heights[curr]*(n-prev-1);
            ans=max(ans,area);
        }
        return ans;

    }
};
