class Solution {
public:
    static bool compare(Interval& a,Interval& b) {
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;

        // Sort intervals based on start time using a custom comparator
        sort(intervals.begin(), intervals.end(), compare);

        // Check for overlapping meetings
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false; // Overlapping found
            }
        }
        return true; // No conflicts found
    }
};
