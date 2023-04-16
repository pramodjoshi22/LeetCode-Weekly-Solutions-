class Solution {
    public int maxDivScore(int[] nums, int[] divisors) {
        
        int length=nums.length;
        int lentcount=divisors.length;
        
        int minmum=0;
        int maxmum=0;
        
        for(int i=0;i<lentcount;i++){
            
            int counts=0;
            int divs=divisors[i];
            
            for(int j=0;j<length;j++){
                
                if(nums[j]%divs==0)
                    counts++;
            }
            
            if(counts>=maxmum){
                if(counts>maxmum){
                    maxmum=counts;
                    minmum=divs;
                }else{
                     if(minmum==0){
                         
                          minmum=divs;
                         maxmum=counts;
                     }                  
                    else{
                        if(divs<minmum)
                            minmum=divs;
                    }
                }
            }
        }
        
        return minmum;
    }
}

