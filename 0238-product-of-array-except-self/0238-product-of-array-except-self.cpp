class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        vector<int>suffix(nums.size());
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=nums[i]*suffix[i+1];
        }
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0) ans[i]=suffix[i+1];
            else if(i==nums.size()-1) ans[i]=prefix[i-1];
            else ans[i]=prefix[i-1]*suffix[i+1];
        }
        return ans;
    }
};