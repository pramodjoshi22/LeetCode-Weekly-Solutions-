//6092. Replace Elements in an Array
Cpp Solution

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){ // <num, pos>
            mp[nums[i]] = i;
        }

        for(vector<int> op:operations){
            int pos = mp[op[0]];
            nums[pos] = op[1];
            mp[op[1]] = pos;
        }

        return nums;
    }
};
