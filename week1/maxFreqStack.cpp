class FreqStack {
public:
    unordered_map<int,int>mp;
    stack<pair<int,int> >s;
    int maxe;
    FreqStack() {
        maxe=0;
        mp.clear();
    }

    void push(int x) {
        mp[x]++;
        maxe=max(maxe,mp[x]);
        if(maxe==mp[x])
        {
            s.push({x,mp[x]});
            return;
        }
        else if(mp[x]<maxe)
        {
            vector<pair<int,int> >v;
            while(s.empty()==false && s.top().second>mp[x])
            {
                v.push_back(s.top());
                s.pop();
            }
            s.push({x,mp[x]});
            for(int i=v.size()-1;i>=0;i--)
                    s.push(v[i]);
        }
    }

    int pop() {
        int ele=s.top().first;
        mp[ele]--;
        s.pop();
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
