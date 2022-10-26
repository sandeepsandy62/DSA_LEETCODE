class Solution {
public:
    int mySqrt(int x) {
        /*
        
        range = 1 to x+1
        cause our idea is to search k^2 > x 
        if we find it then we will return k-1
        if i/o x = 8
        minimal k is 3 , so that 3*3 = 9 > 8
        but sqrt is 2
        
        now why right = x+1
        assume x = 0
        then left = 0 , right = 0,
        left < right ==> false
        return left-1 then ans is -1
        it is wrong so if we take 
        right = x+1 = 1
        left < right true
        mid = 0
        0*0 > x flase
        so left = mid + 1 = 1
        return left-1
        that is 0
        
        */
        
        long long int left = 0 , right = (long long int)x+1 , mid = 0;
        while(left < right){
            mid = left + (right-left)/2 ;
            if(mid*mid > x)
                right = mid;
            else
                left = mid+1;
        }
        return left-1;
    }
};