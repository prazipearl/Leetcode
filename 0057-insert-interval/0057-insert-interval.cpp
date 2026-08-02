class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        for(int i=0;i<intervals.size();i++){
            vector<int>curr=intervals[i];
            if(newInterval[0]>curr[1]){
                 merged.push_back(curr);
            }
            else if(newInterval[1]<curr[0]){
                merged.push_back(newInterval);
                newInterval=curr;
            }
            else{
                newInterval[0]=min(curr[0],newInterval[0]);
                newInterval[1]=max(curr[1],newInterval[1]);
            }
        }
        merged.push_back(newInterval);
        return merged;
    }
};