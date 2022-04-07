class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // -9 -8 -1 0 5
        sort(satisfaction.begin(),satisfaction.end());
        int res = 0;
        int total = 0;
        int n = satisfaction.size();
        
        for(int i=n-1;i>=0 && satisfaction[i]>-total;i--){
            total += satisfaction[i];
            res += total;
        }
        return res;
    }
};