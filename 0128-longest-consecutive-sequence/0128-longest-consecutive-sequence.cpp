class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int len=1;
        int longest=INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]) continue;
            else if(nums[i-1]==nums[i]-1){
                len++;
            }
            else{
             longest=max(longest,len);
             len=1;
            }
        }
        return max(longest,len);
    }
};