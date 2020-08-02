class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >ans;
        if(nums.size()==0)
                return ans;
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=n-1;
            int req=(-1)*nums[i];
            while(l<r)
            {
                int sum=nums[l]+nums[r];
                if(sum==req)
                {
                    vector<int>temp= {nums[i],nums[l],nums[r]};
                    ans.push_back(temp);
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }
                else if(sum>req)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};
