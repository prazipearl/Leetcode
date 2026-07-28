class Solution {
private:
int find(vector<int>&leader,int node){
    if(leader[node]!=node){
        leader[node]=find(leader,leader[node]);
    }
    return leader[node];
}
void join(vector<int>&leader,int left,int right){
    int ll=find(leader,left);
    int rl=find(leader,right);
    leader[rl]=ll;
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>leader(isConnected.size());
        for(int i=0;i<leader.size();i++){
            leader[i]=i;
        }
        for(int r=0;r<isConnected.size();r++){
            for(int c=0;c<isConnected[0].size();c++){
                if(isConnected[r][c]==1){
                    join(leader,r,c);
                }
            }
        }
        vector<int>gcnt(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            int ult=find(leader,i);
            gcnt[ult]++;
        }
        int ans=0;
        for(auto x:gcnt){
            if(x!=0) ans++;
        }
        return ans;
    }
};