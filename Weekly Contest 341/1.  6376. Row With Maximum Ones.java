class Solution {
    public int[] rowAndMaximumOnes(int[][] mato) {
    int maxe = 0;
        int maxRow = 0;
        for (int i = 0; i < mato.length; i++) {
            int one = countOnes(mato[i]);
            if (one > maxe) {
                maxe = one;
                maxRow = i;
            }
        }
        return new int[]{maxRow, maxe};
    }

    private int countOnes(int[] rows) {
        int counts = 0;
        for (int i = 0; i < rows.length; i++) {
            if (rows[i] == 1) {
                counts++;
            }
        }
        return counts;
    }
}
