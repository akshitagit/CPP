#include<bits/stdc++.h> 
using namespace std; 
stack<char> st; 
string s; 
char bottom_insert(char x){ 
    if(st.size() == 0){ 
        st.push(x); 
    }  
    else{ 
        char a = st.top(); 
        st.pop(); 
        bottom_insert(x); 
  
        st.push(a); 
    } 
}   
char reverse(){   
    if(st.size()>0){ 
        char x = st.top(); 
        st.pop(); 
        reverse();
        bottom_insert(x); 
    } 
} 
int main(){      
    st.push('1'); 
    st.push('2'); 
    st.push('3'); 
    st.push('4');
    st.push('5');     
    reverse();   
    while(!st.empty()){ 
        char p=st.top(); 
        st.pop(); 
        s+=p; 
    }    
    cout<<"[";
    for(int i=s.size()-1; i>=0; i--){
        cout<<s[i]<<", ";
    }
    cout<<"]";
    return 0; 
}
