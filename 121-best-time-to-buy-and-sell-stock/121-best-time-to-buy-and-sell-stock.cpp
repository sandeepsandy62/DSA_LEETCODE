class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //APPROACH 1 
        
        /*Brute force O(N^2) will not work TLE 
        int n = prices.size();
        int cur , mx = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            cur = prices[i];
            for(int j = i+1 ; j < n ; j++){
                if(prices[j]-cur > mx){
                    mx = prices[j]-cur ; 
                }
            }
        }
        if(mx == INT_MIN || mx <= 0) return 0;
        return mx ;
        */
        
        //APPROACH 2
        
        //variation of next greater element problem pattern
        //Here we need to add one extra condition to check if the
        //price of the current day stock is less than nexGreater[i] value
        //if it is true we will update it by nextgreater[i+1]
        //By this we can maintain greatest stock available in the array
        
        /*TC : O(N) , SC : O(N)
        
        int n = prices.size();
        vector<int>nxtGreater(n,0);
        nxtGreater[n-1] = -1 ;
        for(int i = n-2 ; i >= 0 ; i--){
            if(prices[i] < prices[i+1] || prices[i] < nxtGreater[i+1]){
                if(prices[i] < nxtGreater[i+1])
                  nxtGreater[i] = nxtGreater[i+1];
                else
                    nxtGreater[i] = prices[i+1];
            }else{
                nxtGreater[i] = -1 ;
            }
        }
        
        int mx = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nxtGreater[i]-prices[i] > mx) mx = nxtGreater[i]-prices[i] ;
        }
        
        return mx;
        */
        
        //APPROACH 3
        //find minimum element and find maximum profit with that minimum element
        //TC : O(N) , SC : O(1)
        int n = prices.size();
        int mn = INT_MAX , mx = 0;
        for(int i = 0 ; i < n;i++){
            mn = min(mn,prices[i]);
            mx = max(mx,prices[i]-mn);
        }
        return mx;
        
    }
};