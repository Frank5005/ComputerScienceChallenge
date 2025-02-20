//Recursion idea
//Base case
//Number of possible subsets: 2^n
//Select it or exclude it

class Solution {
public:
    void subsetGen(int i, vector<int>& nums, vector<vector<int>>& solve, vector<int>& vec){
        //Base case
        if(nums.size() == i){
            solve.push_back(vec);
            return;
        }
        //Recursion
        vec.push_back(nums[i]);
        subsetGen(i+1, nums, solve, vec);
        vec.pop_back();
        subsetGen(i+1, nums, solve, vec);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solve;
        vector<int> vec;
        subsetGen(0, nums, solve, vec);
        return solve;
    }
};