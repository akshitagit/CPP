 int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        int t[n+1][m+1];
        for (int i = 0; i<n+1; i++){
            for (int j = 0; j<m+1; j++){
                if (i == 0 || j == 0){
                    t[i][j] = 0;
                }
            }
        }
        
        for (int i = 1; i<n+1; i++){
            for (int j = 1; j<m+1; j++){
                if (text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        //print the string too
        int i = n;
        int j = m;
        string s;
        while (i>0 && j>0){
            if (text1[i-1] == text2[j-1] ){
                s = text1[i-1] + s;
                i--;
                j--;
            }else if (t[i-1][j] < t[i][j-1]){
                j--;
            }else{
                i--;
            }
        }
        cout << s;
        return s.size();
        // return t[n][m] in case string is not required to be printed
    }
};