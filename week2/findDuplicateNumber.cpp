class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        // write your code here
        for(int i=0;i<nums.size();i++)
        {
            int pos=abs(nums[i])-1;
            if(nums[pos]>0)
                nums[pos]=(-1)*nums[pos];
            else
                return abs(nums[i]);
        }
    }
};
