class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for ( auto value: asteroids){
            //the collision only happens when the value is positive
            //and the top of the stack is negative
            while (!stk.empty() && value < 0 && stk.back() >0){
                int difference = stk.back() + value;
                if (difference < 0)
                    stk.pop_back();
                else if (difference == 0){
                    value = 0;
                    stk.pop_back();
                }
                else{
                    value = 0;
                }
            }
            if (value != 0)
                stk.push_back(value);
        }
        return stk;
    }

};