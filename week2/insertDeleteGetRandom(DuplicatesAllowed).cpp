class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int>mp;
    vector<int>v;
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        int curr=mp[val];
        int newIndex=v.size()-1;
        int ele=v.back();
        swap(v[curr],v[newIndex]);
        v.pop_back();
        mp[ele]=curr;
        mp.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
          return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
