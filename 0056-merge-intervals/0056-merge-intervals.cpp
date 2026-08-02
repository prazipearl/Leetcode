class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<int>prev=intervals[0];
        vector<vector<int>> merged;
        for(int i=1;i<intervals.size();i++){
            vector<int>curr=intervals[i];
            if(prev[1]>=curr[0]){
                prev[1]=max(prev[1],curr[1]);
            }
            else{
                merged.push_back(prev);
                prev=curr;
            }
        }
        merged.push_back(prev);
        return merged;
    }
};