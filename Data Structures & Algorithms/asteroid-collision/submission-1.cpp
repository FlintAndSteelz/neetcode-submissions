class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (auto val: asteroids){

            bool destroyed = false;
            while (!stk.empty() && stk.back()>0 && val < 0){
                if (stk.back() < -val){
                    stk.pop_back();
                    continue;
                }
                else if (stk.back() == -val){
                    stk.pop_back();
                }
                else{
                }
                destroyed = true;
                break;
            }
            if (!destroyed)
                stk.push_back(val);
        }
        return stk;
    }
};