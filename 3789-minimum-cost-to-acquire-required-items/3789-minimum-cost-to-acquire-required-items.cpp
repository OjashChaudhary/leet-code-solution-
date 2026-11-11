class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        int b= min(need1, need2);
        if(cost1 + cost2 > costBoth){
            ans+= (long long)b*costBoth;
            need1-=b;
            need2-=b;
        }

        if(need1) ans+= (long long)need1*min(cost1, costBoth);
        if(need2) ans+= (long long)need2*min(cost2, costBoth);
        return ans;
    }
};
