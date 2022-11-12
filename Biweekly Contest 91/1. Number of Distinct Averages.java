class Solution {
    public int distinctAverages(int[] nums) {
          Arrays.sort(nums);
        int no = nums.length;
        int left_no = 0;
        int right_no = no - 1;
        Set<Double> set = new HashSet<>();
        while (left_no < right_no) {
            double avg = ((double) nums[left_no] + (double) nums[right_no]) / 2;
            set.add(avg);
            left_no++;
            right_no--;
        }
        return set.size();
    }
}
