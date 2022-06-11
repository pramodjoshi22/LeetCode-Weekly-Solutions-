//6096. Successful Pairs of Spells and Potions


class Solution {
    
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int len = potions.length;
        for(int i=0; i<spells.length; i++){
            int sp = spells[i];
            int left = 0, right = len-1;
            while(left <= right){
                int mid = left + ((right-left)>>1);
                long sum = (long)potions[mid]*sp;
                if(sum >= success) right = mid -1;
                else left = mid+1;
            }
            spells[i] = len-left;
        }
        return spells;

    }
}
