class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans="";
        vector<string>v;
        while(ss>>word){
            v.push_back(word);
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            ans+=v[i];
            if(i!=v.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};