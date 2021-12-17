class Solution {
public:
    int min(int a,int b,int c){
        if(a<=b && a<=c) return a;
        else if(b<=a && b<=c)return b;
        else return c;
    }
    int max(int a,int b){
        if(a>b)return a;
        else return b;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxarea=0;
        vector<vector<int>> store(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            store[i][0] = matrix[i][0]-'0';
            maxarea = max(store[i][0],maxarea);
        }
        
        for(int i=1;i<n;i++){
            store[0][i] = matrix[0][i]-'0';
            maxarea = max(store[0][i],maxarea);
        }
           
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='0') store[i][j]=0;
                else store[i][j] = min(store[i-1][j-1],store[i-1][j],store[i][j-1])+1;
                maxarea = max(store[i][j],maxarea);
            }
        }
        return maxarea*maxarea;
    }
};