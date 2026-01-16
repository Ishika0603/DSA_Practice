#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); i++) {

            // if +ve asteroid in stack and current asteroid is -ve
            if (!ans.empty() && ans.back() > 0 && asteroids[i] < 0) {

                while (!ans.empty() &&
                       ans.back() > 0 &&
                       abs(asteroids[i]) > ans.back()) {
                    ans.pop_back();
                }

                if (!ans.empty() &&
                    abs(asteroids[i]) == ans.back()) {
                    ans.pop_back();
                    continue;
                } 
                else if (ans.empty() || ans.back() < 0) {
                    ans.push_back(asteroids[i]);
                }

            } else {
                ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};