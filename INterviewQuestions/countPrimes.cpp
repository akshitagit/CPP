//Program to find total no. of primes upto a given no. 
int countPrimes(int n) {
        int cnt=0;
        vector<int> vec(n,1);
        for(int i=2;i<n;i++){
            if(vec[i]==1){
                cnt++;
                for(int j=2;j*i<n;j++){
                    if(vec[j*i]==1)
                        vec[j*i] = 0;
                }
            }
        }
        return cnt;
    }
