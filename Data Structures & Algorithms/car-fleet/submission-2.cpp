#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n=speed.size();
        vector<pair<int,double>>cars;
        for(int i=0;i<n;i++){
            double time=(double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.rbegin(),cars.rend());
        int fleets=0;
        double maxTime=0.0;
        for(auto it:cars){
            if(it.second>maxTime){
                maxTime=it.second;
                fleets++;
            }
        }
        return fleets;
        // int n = position.size();
        // vector<pair<int, double>> cars; // Pair of position and time to reach target
        
        // // Calculate time to reach the destination for each car
        // for (int i = 0; i < n; i++) {
        //     double time = (double)(target - position[i]) / speed[i];
        //     cars.push_back({position[i], time});
        // }
        
        // // Sort cars by position in descending order
        // sort(cars.rbegin(), cars.rend());
        
        // int fleets = 0;
        // double maxTime = 0.0;
        
        // // Count fleets
        // for (const auto& car : cars) {
        //     if (car.second > maxTime) { // A new fleet starts
        //         fleets++;
        //         maxTime = car.second; // Update the maximum time
        //     }
        // }
        
        // return fleets;
    }
};
