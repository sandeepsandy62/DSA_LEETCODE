class Solution {
public:
    int mySqrt(int x) {
        //Brute Force
        // y = sqrt(x) ;
        // y^2 = x ;
        // to be more precise y^2 <= x cuz , we need to truncate the decimal digits
        
        //so when ever our y^2 <= x condition failed then , we find our ans which is 1 less than y 
        //TC : O(SQRT(X)) , SC : O(1)
        
        long long int y = 0 ;
        while(y*y <= x) y++;
        return y-1;
    }
};