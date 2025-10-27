class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int rowSize = bank.size();
        int colSize = bank[0].size();
        vector<pair<int,int>> exist;

        for(int r =0;r<rowSize;r++){
            bool found =false;
            int count =0;
            for(int c =0;c<colSize;c++){
                if(bank[r][c]=='1'){
                    count++;
                    found=true;

                } 
                

            }
            if(found) exist.push_back({r,count});
        }
        int count=0;
        if(exist.size()<=1) return 0;
        for(int idx =0;idx<exist.size()-1;idx++){
            int first = exist[idx].second;
            int sec = exist[idx+1].second;
            count += (first*sec);



        }
        return count;
        
    }
};