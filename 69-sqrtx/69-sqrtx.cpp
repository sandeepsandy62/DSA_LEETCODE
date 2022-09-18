class Solution {
public:
    int mySqrt(int x) {
        //Brute Force
        // y = sqrt(x) ;
        // y^2 = x ;
        // to be more precise y^2 <= x cuz , we need to truncate the decimal digits
        
        //so when ever our y^2 <= x condition failed then , we find our ans which is 1 less than y 
        //TC : O(SQRT(X)) , SC : O(1)
        
        // long long int y = 0 ;
        // while(y*y <= x) y++;
        // return y-1;
        
        
        //Now actualy what we are doing we are checking from 1 , 2 ,3 ,.....,sqrt(x)
        //instead of doing linear search we use binary search so that time complexity will be    O(log(sqrt(x)))
        //as we know ans will be in range when y*y <= x , so we store ans in mid*mid <= x condition
        //Given constraints 0 <= x <= 2^31 - 1
        //that is the reason we are storing low = 0 , high - INT_MAX
        
        long long low = 0 , high = INT_MAX ,ans = 0;
        while(low <= high){
            long long mid = low + (high-low)/2 ;
            if(mid*mid <= x) ans = mid , low = mid+1;
            else high = mid -1 ;
        }
        
        return ans;
    }
};