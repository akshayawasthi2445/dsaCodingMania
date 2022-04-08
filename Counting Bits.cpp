class Solution {
public:
    vector<int> countBits(int n) {
        
        if(n == 0) return {0};
        if(n == 1) return {0,1};
        
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        
        int batch = 2;
        int i=2;
        int batchCounter = 0;
        
        while(i<=n){
            res.push_back(1+res[i-batch]);
            batchCounter+=1;
            if(batchCounter == batch){
                batch*=2;
                batchCounter=0;
            }
            i++;
        }
        return res;
    }
};
// 0000
// 0001
// 0010
// 0011
// 0100 bc = 1
// 0101 bc = 2
// 0110 bc = 3
// 0111 bc = 4
// 1000