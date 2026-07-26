class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
           maxarea=max(min(height[i],height[j])*(j-i),maxarea);
           if(height[i]<height[j]) i++;
           else if(height[i]>height[j]) j--;
           else{
            i++;
            j--;
           }
        }
        return maxarea;
    }
};