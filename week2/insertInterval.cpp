class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        auto itr1 = std::lower_bound(intervals.begin(), intervals.end(),
                                     newInterval, compare);
        auto itr2 = std::upper_bound(intervals.begin(), intervals.end(),
                                     newInterval, compare);

        vector<vector<int>> res;

        for (auto itr = intervals.begin(); itr < itr1; ++itr) {
            res.push_back(*itr);
        }

        vector<int> merged_interval = newInterval;
        if (itr1 < itr2) {
            merged_interval = mergeIntervals(merged_interval, *itr1);
            merged_interval = mergeIntervals(merged_interval, *(itr2 - 1));
        }
        res.push_back(merged_interval);

        for (auto itr = itr2; itr < intervals.end(); ++itr) {
            res.push_back(*itr);
        }

        return res;
    }

private:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if (a[1] < b[0])  return true;
        return false;
    }

    static vector<int> mergeIntervals(const vector<int>& a, const vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
};
