class Solution {
    public:
        int longestValidParentheses(string s) {
            stack<int> word;
            int solve = 0;
            //Base case
            if(s.length() == 0){
                return 0;
            }
            word.push(-1);
            //Try to find the path, and it ocassions in the string
            for(int i = 0; i < s.size(); i++){
                if (s[i] == '(') {
                    word.push(i);
                } else {
                    word.pop();
                    if (word.empty()) {
                        word.push(i); 
                    } else {
                        solve = max(solve, i - word.top());
                    }
                }
            }
            return solve;
        }
    };