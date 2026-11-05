class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) { 
        arr2.push_back(INT_MAX);
        arr2.push_back(INT_MIN);
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int res=0;
        int i=0,j=0;
        while(i < arr1.size()){
            if(arr1[i] >= arr2[j]){
                j++;
            }
            else{
                if(abs((double) arr2[j]-arr1[i]) > d && abs((double)arr2[j-1]-arr1[i])> d){
                    res++;
                }
                i++;
            }
        }
        return res;
    }
};