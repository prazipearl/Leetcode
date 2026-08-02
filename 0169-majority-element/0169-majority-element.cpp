class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        int majorelement=0;
        for(auto x:mp){
            majorelement=max(majorelement,x.second);
        }
        for(auto x:mp){
            if(x.second==majorelement) return x.first;
        }
        return 0;
    }
};