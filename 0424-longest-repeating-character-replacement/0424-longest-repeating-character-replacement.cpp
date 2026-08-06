class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int maxfrq=0;
        vector<int>frq(26,0);
        int ans=0;
        map<int,int>mp;
        for(int r=0;r<s.size();r++){
            int size=r-l+1;
            frq[s[r]-'A']++;
            maxfrq=max(maxfrq,frq[s[r]-'A']);
            while(r-l+1-maxfrq>k){
             frq[s[l]-'A']--;
             l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};