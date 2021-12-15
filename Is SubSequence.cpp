class Solution {
public:
    bool isSubsequence(string s, string t) {
        // s="abc"
        // t="ahbgdc"
        
        // s="axc"
        // t="ahbgdc"
        int m = s.size();
        int n = t.size();
        int flag = 0;
        if(m>n)return false;
        else if(s=="" && t=="")return true;
        int arr[n+1][m+1];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<=s.size();i++){
            arr[0][i] = 0;
        }
        for(int i=0;i<=t.size();i++){
            arr[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t[i-1]==s[j-1]){
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                }
                else
                    arr[i][j] = arr[i-1][j];
            }
            if(arr[i][m]>0){
                flag = 1;
                break;
            }
        }
        if(flag==1)return true;
        else return false;
    }
};