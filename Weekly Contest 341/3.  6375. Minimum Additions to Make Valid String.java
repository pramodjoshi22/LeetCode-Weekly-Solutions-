class Solution {
    public int addMinimum(String words) {
        int rests = 0;
        int indexs = 0;
        char[] state = {'a', 'b', 'c'};
        for (char c : words.toCharArray()) {
            while (true) {
                if (c != state[indexs]) {
                    indexs = (indexs + 1) % state.length;
                    rests++;
                    continue;
                }
                indexs = (indexs + 1) % state.length;
                break;
            }
        }
        if (indexs == 1) return rests + 2;
        if (indexs == 2) return rests + 1;
        return rests;
    }
}
