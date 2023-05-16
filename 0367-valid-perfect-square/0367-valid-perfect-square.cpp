class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i=1,j=num/2+1;
        while(i<=j){
            long long m=(i+j)>>1;
            
            if(m*m<num)
                i=m+1;
            else if(m*m>num)
                j=m-1;
            else 
                return true;
        }
        if(i*i!=num)
            return false;
        return true;
    }
};