class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>left(prices.size());
        int leftmax=0;
        for(int i=prices.size()-1;i>=0;i--){
            leftmax=max(leftmax,prices[i]);
            left[i]=leftmax;
        }
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            maxprofit=max(maxprofit,left[i]-prices[i]);
        }
        return maxprofit;
    }
};