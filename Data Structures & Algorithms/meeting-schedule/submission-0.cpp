/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
    if (intervals.empty()) return true;

    // Sort intervals based on start time
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
        return a.start < b.start;
    });

    // Check for overlapping meetings
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start < intervals[i - 1].end) {
            return false; // Overlapping found
        }
    }
    return true; // No conflicts found
}
};
