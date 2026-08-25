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
      static bool compare(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
          if (intervals.empty()) return 0;

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end(),compare);

        // Step 2: Min-Heap to track end times of meetings
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 3: Iterate over meetings
        for (const Interval& meeting : intervals) {
            // If the earliest meeting has ended before this one starts, remove it
            if (!minHeap.empty() && minHeap.top() <= meeting.start) {
                minHeap.pop();
            }
            // Add the current meeting's end time
            minHeap.push(meeting.end);
        }

        // Step 4: Return the number of parallel meetings (size of the heap)
        return minHeap.size();
    }
};
