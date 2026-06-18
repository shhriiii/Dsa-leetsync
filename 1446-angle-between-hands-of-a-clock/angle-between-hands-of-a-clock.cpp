class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle =0;
        angle += minutes*6.0;
        int x =hour%12;
        angle-=x*30.0;
        angle-=minutes*0.5;
        // cout<<angle<<endl;
        // return abs(min(abs(360-angle) , min(angle,abs(angle-360))));
        angle=abs(angle);
        return min(abs(360-angle),angle);

    }
};