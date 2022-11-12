class Solution {
    public int countGoodStrings(int low, int high, int zero, int one) {
         int[] dpp = new int[high + 1];
        dpp[0] = 1;
        int MOD_no = 1000000007;
        for (int i = 1; i <= high; i++) {
            if (i - zero >= 0) {
                dpp[i] = (dpp[i] + dpp[i - zero]) % MOD_no;
            }
            if (i - one >= 0) {
                dpp[i] = (dpp[i] + dpp[i - one]) % MOD_no;
            }
        }
        int sum_no = 0;
        System.out.println(Arrays.toString(dpp));
        for (int i = low; i <= high; i++) {
            sum_no = (sum_no + dpp[i]) % MOD_no;
        }
        return sum_no;
    }
}
