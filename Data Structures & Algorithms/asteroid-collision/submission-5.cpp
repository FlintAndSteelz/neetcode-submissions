class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int j = -1;
        for (auto value: asteroids){
            while (j >= 0 && asteroids[j] > 0 && value < 0){
                if (asteroids[j] + value < 0)
                    j--;
                //collion happens so we pop the top of the stack
                else if (asteroids[j] + value > 0){
                    value =0;
                    break;
                }
                else{
                    value =0;
                    j--;
                }
            }
            if (value != 0)
                asteroids[++j] = value;
        }
        asteroids.resize(j+1);
        return asteroids;
    }
};