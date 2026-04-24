class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int l =0 , r=0 , u=0;
        for(int i =0;i<n;i++){
            if(moves[i]=='L') l++;
            else if(moves[i]=='R') r++;
            else u++;

        }
        int x ;
        if(l>=r){
            x= l-r;
            x+=u;
            return x;

        }
        else{
            x=r-l;
            x+=u;
            return x;
        }
        return 0;
        
    }
};