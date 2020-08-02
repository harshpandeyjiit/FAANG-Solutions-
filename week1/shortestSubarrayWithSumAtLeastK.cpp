class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        deque<int>q;
        int pref[A.size() + 1];
        pref[0]=0;
        int n = A.size();
        for(int i=1;i<=n;i++)
            pref[i]=pref[i-1]+A[i-1];
        int ans=n+1;
        for(int i=0;i<=n;i++)
        {
            while(q.empty()==false && pref[i]<=pref[q.back()])
                    q.pop_back();
            while(q.empty()==false && pref[i]-pref[q.front()]>=K)
            {
                ans=min(ans,i-q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        if(ans<n+1)
                return ans;
        return -1;
    }
};
