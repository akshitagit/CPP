/* solution to problem defanging IP Address
leetcode challenge */


 string defangIPaddr(string address) {
        
        string defangedIP;
        for(int i =0;i<address.length();i++){
            if(address[i]!='.'){
                defangedIP = defangedIP+address[i];
            }
            else{
                defangedIP = defangedIP+'['+'.'+']';
            }
        }
        
        
        return defangedIP;
    }