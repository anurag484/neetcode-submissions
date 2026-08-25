class CountSquares {
public:
     unordered_map<int, unordered_map<int,int>> rows;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        rows[y][x]++;  // increment count for point (x,y)
    }
    

    int count(vector<int> point) {
        int qx = point[0], qy = point[1];
        int ans = 0;

        // If no points in the query's row, nothing to do.
        if (rows.find(qy) == rows.end()) return 0;

        // Iterate every point (x, qy) in the same horizontal row
        for (auto &p : rows[qy]) {
            int x = p.first;
            int c1 = p.second;   // number of (x, qy)
            if (x == qx) continue;  // side length 0 -> skip

            int side = abs(x - qx);

            // check top square: y = qy + side
            int yTop = qy + side;
            if (rows.find(yTop) != rows.end()) {
                int c2 = 0, c3 = 0;
                auto it2 = rows[yTop].find(x);    // (x, yTop)
                if (it2 != rows[yTop].end()) c2 = it2->second;
                auto it3 = rows[yTop].find(qx);   // (qx, yTop)
                if (it3 != rows[yTop].end()) c3 = it3->second;
                ans += c1 * c2 * c3;
            }

            // check bottom square: y = qy - side
            int yBot = qy - side;
            if (rows.find(yBot) != rows.end()) {
                int c2 = 0, c3 = 0;
                auto it2 = rows[yBot].find(x);    // (x, yBot)
                if (it2 != rows[yBot].end()) c2 = it2->second;
                auto it3 = rows[yBot].find(qx);   // (qx, yBot)
                if (it3 != rows[yBot].end()) c3 = it3->second;
                ans += c1 * c2 * c3;
            }
        }
        return ans;
    }
};
