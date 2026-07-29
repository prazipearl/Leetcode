class Solution {
private:
    void solve(int idx,vector<int>&curr,set<vector<int>>&ans,vector<int>&nums){
        if(idx==nums.size()){
            ans.insert(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(idx+1,curr,ans,nums);
        curr.pop_back();
        solve(idx+1,curr,ans,nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        set<vector<int>>ans;
        solve(0,curr,ans,nums);
        vector<vector<int>> OGans;
        for(auto x:ans){
            OGans.push_back(x);
        }
        return OGans;
    }
};