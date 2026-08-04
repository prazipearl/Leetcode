class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>v;
        int mine=*min_element(nums.begin(),nums.end());
        int maxe=*max_element(nums.begin(),nums.end());
        for(int i=mine;i<=maxe;i++){
            auto it=find(nums.begin(),nums.end(),i);
            if(it==nums.end()) v.push_back(i);
        }
        return v;
    }
};