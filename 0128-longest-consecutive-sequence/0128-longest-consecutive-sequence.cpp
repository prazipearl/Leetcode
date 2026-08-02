class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int longest=0;
        for(auto x:nums){
            st.insert(x);
        }
        for(auto x:st){
            if(st.find(x-1)==st.end()){
                int len=1;
                int curr=x;
                while(st.find(curr+1)!=st.end()){
                    len++;
                    curr++;
                }
               longest=max(longest,len);
            }
        }
        return longest;
    }
};