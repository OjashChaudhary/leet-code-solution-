class Solution {
public:
    int months[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayofyear(string s){
        int month=0;
        int res=0;
        for(int i=0; i<=1; i++){
            month*=10;
            month+= (s[i]-'0');
        }
        for(int i=0; i<month-1; i++){
            res+= months[i];
        }
        
        int day=0;
        for(int i=3; i<=4; i++){
            day*=10;
            day+= (s[i]-'0');
        }
        res+= day;
        return res;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aA= dayofyear(arriveAlice);
        int lA= dayofyear(leaveAlice);
        int aB= dayofyear(arriveBob);
        int lB= dayofyear(leaveBob);

        int days= min(lA, lB)- max(aA, aB)+1;
        if(days >= 0) return days;
        return 0;
    }
};