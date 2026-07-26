class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size());
        vector<int>right(height.size());
        int leftmax=0;
        int rightmax=0;
        for(int i=0;i<height.size();i++){
            leftmax=max(height[i],leftmax);
            left[i]=leftmax;
        }
        for(int i=height.size()-1;i>=0;i--){
            rightmax=max(height[i],rightmax);
            right[i]=rightmax;
        }
        int watertrap=0;
        for(int i=0;i<height.size();i++){
            watertrap+=(min(left[i],right[i])-height[i]);
        }
        return watertrap;
    }
};