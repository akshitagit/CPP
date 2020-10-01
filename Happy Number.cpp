class Solution {
public:
    int square(int num)
    {
        int sum=0;
        while(num>0)
        {
            sum=sum+((num%10)*(num%10));
            num=num/10;
        }
        return sum;
    }
    bool isHappy(int n) 
    {
        int sum=n;
        while(1)
        {
            if(sum==1)
            {
                return true;
            }
            if(sum==89)
            {
                return false;
            }
            sum=square(sum);
        }
        return 0;
    }
};
