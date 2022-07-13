//Function to find longest substring without repetating characters

int lengthOfLongestSubstring(string s) {
        if(s.size()<2){
            return s.size();
        }
        int start = 0,end = 1;
        int maxlen = 0,currmax=1;
        unordered_set<char> st;
        st.insert(s[start]);
        while(start<s.size() && end<s.size()){
            if(st.count(s[end])==0){
                st.insert(s[end]);
                end++;
                maxlen = max(maxlen,end-start);
            }
            else{
                st.erase(s[start++]);
            }
        }
        return maxlen;
    }
