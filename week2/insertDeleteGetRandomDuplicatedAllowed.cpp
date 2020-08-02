class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int,set<int,greater<int> > >mp;
    vector<int>v;
    RandomizedCollection() {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        v.push_back(val);
        mp[val].insert(v.size()-1);
        if(mp[val].size()==1)
                return true;
        return false;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mp[val].size()!=0)
        {
            auto it=mp[val].begin();
            int curr=*it;
            int newIndex=v.size()-1;
            int ele=v.back();
            swap(v[curr],v[newIndex]);
            mp[ele].erase(newIndex);
            mp[ele].insert(curr);
            v.pop_back();
            mp[val].erase(curr);
            return true;
        }
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
