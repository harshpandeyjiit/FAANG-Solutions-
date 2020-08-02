class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> stk;
        int n = s.length();
        for(int i=0;i<n;++i){
            char c = s[i];
            while(!stk.empty() && k>0 && stk.top()>c){
                stk.pop();
                --k;
            }
            stk.push(c);
        }

        string ans="";
        while(!stk.empty()){
            ans = stk.top()+ans;
            stk.pop();
        }
        ans = ans.substr(0, ans.length()-k);

        // removing leading zeros
        int i =0;
        while(ans[i]=='0')++i;
        ans = ans.substr(i, s.length());

        // in case the answer is zero
        if(ans.length()==0)ans="0";
        return ans;
    }
};
