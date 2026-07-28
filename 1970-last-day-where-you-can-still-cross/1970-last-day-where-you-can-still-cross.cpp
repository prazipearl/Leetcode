class Solution {
public:
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
    int latestDayToCross(int R, int C, vector<vector<int>>& cells) {
        vector<int>leader(R*C+2);
        vector<bool>water(R*C+2,false);
        for(int i=0;i<leader.size();i++){
            leader[i]=i;
        }
        int days=0;
        int dr[8]={0,-1,-1,-1,0,1,1,1};
        int dc[8]={-1,-1,0,1,1,1,0,-1};
        for(auto cell:cells){
            int r=cell[0];
            int c=cell[1];
            water[(r-1)*C+c]=true;
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=1&&nr<=R&&nc>=1&&nc<=C&&water[(nr-1)*C+nc]==true){
                    join(leader,(nr-1)*C+nc,(r-1)*C+c);
                }
            }
            if(c==1){
                join(leader,0,(r-1)*C+c);
            }
            else if(c==C){
                join(leader,R*C+1,(r-1)*C+c);
            }
            if(find(leader,0)==find(leader,R*C+1)) break;
            days++;
        }
        return days;
    }
};