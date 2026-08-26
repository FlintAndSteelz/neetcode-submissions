class Solution {
public:
    bool isValid(string s) {
        //tức là cứ gặp một cặp ngoặc legit thì tù ngay
        while (true){
            size_t pos = string:: npos;
            if ((pos = s.find("()")) != string::npos){
                s.erase(pos, 2);
                continue;
            }
            if ((pos = s.find("{}")) != string::npos){
                s.erase(pos,2);
                continue;
            }
            if ((pos = s.find("[]")) != string::npos){
                s.erase(pos,2);
                continue;
            }
            //nếu mà tới được dòng break này thì có nghĩa là 
            //đã đi qua các cặp ngoặc legit
            //nếu mà string s còn ngoặc thì là false, nếu mà hết
            //ngoặc thì là true
            break;
        }
        return s.empty();
    }
};
