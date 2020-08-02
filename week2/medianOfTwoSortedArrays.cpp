class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m)swap(nums1,nums2);
        n=nums1.size();
        m=nums2.size();
        int low=0;
        int high=n;
        while(low<=high)
        {
            int partx=(low+high)/2;
            int party=(n+m+1)/2;
            party-=partx;
            int maxLeftx=(partx==0)?INT_MIN:nums1[partx-1];
            int maxLefty=(party==0)?INT_MIN:nums2[party-1];
            int minRightx=(partx==n)?INT_MAX:nums1[partx];
            int minRighty=(party==m)?INT_MAX:nums2[party];

            if(maxLefty<=minRightx && maxLeftx<=minRighty)
            {
                if((n+m)%2==0)
                {
                    double ans= (double(min(minRightx,minRighty)) + double(max(maxLeftx,maxLefty)))/2.0;
                    return ans;
                }
                else
                      return max(maxLeftx,maxLefty);

            }
            else if(maxLeftx>minRighty)
                high=partx-1;
            else
                low=partx+1;

        }
        return 0;
    }
};
