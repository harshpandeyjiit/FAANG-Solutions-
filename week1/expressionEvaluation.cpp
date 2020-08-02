int prec(char ops)
{
    if(ops == '+'||ops == '-')
	return 1;
	if(ops == '*'||ops == '/')
	return 2;
	return 0;
}
// Function to perform arithmetic operations.
int applyOp(int a, int b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
    return 0;
}
class Solution {
public:
    /**
     * @param expression: a list of strings
     * @return: an integer
     */
    int evaluateExpression(vector<string> &v) {
        // write your code here
        stack<int>nums;
        stack<char>op;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]=="(")
                op.push('(');
            else if(v[i]==")")
            {
                while(!op.empty() && op.top()!='(')
                {
                    int val2=nums.top();
                    nums.pop();
                    int val1=nums.top();
                    nums.pop();
                    char opd=op.top();
                    op.pop();
                    nums.push(applyOp(val1,val2,opd));
                }
                if(!op.empty())
                    op.pop();
            }
            else if(isdigit(v[i][0]))
            {
                int val=stoi(v[i]);
                nums.push(val);
            }
            else
            {
                while(!op.empty() && prec(op.top())>=prec(v[i][0]))
                {
                    int val2=nums.top();
                    nums.pop();
                    int val1=nums.top();
                    nums.pop();
                    char opd=op.top();
                    op.pop();
                    nums.push(applyOp(val1,val2,opd));
                }
                op.push(v[i][0]);
            }
        }
        while(!op.empty())
        {
            int val2=nums.top();
            nums.pop();
            int val1=nums.top();
            nums.pop();
            char opd=op.top();
            op.pop();
            nums.push(applyOp(val1,val2,opd));
        }
        if(nums.empty())
            return 0;
        return nums.top();

    }
};
