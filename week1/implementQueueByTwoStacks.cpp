class MyQueue {
    stack<int>s1;
    stack<int>s2;

public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        s1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        if(s2.empty()==true)
        {
            while(s1.empty()==false)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ele=s2.top();
        s2.pop();
        return ele;
        // write your code here
    }

    /*
     * @return: An integer
     */
    int top() {
        if(s2.empty()==true)
        {
            while(s1.empty()==false)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ele=s2.top();
        return ele;
        // write your code here
    }
};
