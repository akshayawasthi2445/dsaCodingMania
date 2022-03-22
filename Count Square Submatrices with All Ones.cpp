class Solution {
public:
    int min(int a,int b,int c){
        if(a<b && a<c) return a;
        else if(b<c) return b;
        else return c;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        
        int total=0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> V(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(matrix[i][0]==1){total+=1;V[i][0]=1;}
        }
        
        for(int i=1;i<n;i++){
            if(matrix[0][i]==1){total+=1;V[0][i]=1;}
        }
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==1){
                    V[i][j]=min(V[i-1][j],V[i-1][j-1],V[i][j-1])+1;
                    total+=V[i][j];
                }
            }
        }
        return total;
    }
};