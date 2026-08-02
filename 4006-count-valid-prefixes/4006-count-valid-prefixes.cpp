class Solution {
public:
    int countValidPrefixes(string s) {
        int onec=0;
        int zeroc=0;
        int c=0;
        for(auto x:s){
            if(x=='1') onec++;
            else zeroc++;
            if(abs(onec-zeroc)<=1) c++;
        }
        return c;
    }
};