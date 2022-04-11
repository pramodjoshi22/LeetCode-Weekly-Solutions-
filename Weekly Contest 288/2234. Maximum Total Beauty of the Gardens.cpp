//2234. Maximum Total Beauty of the Gardens


class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        int full_cnt = 0;
        for(int i = flowers.size() - 1; i >= 0; i--) {
            if(flowers[i] < target) break;
            full_cnt++;
        }
        int n = flowers.size() - full_cnt;
        if(n == 0) return (long long)full_cnt * (long long)full;
        
        vector<long long> fill_up(n, 0), fill_target(n, 0);
        
        // fill_up: flowers needed to get min of flowers to flowers[i]
        fill_up[0] = 0;
        for(int i = 1; i < n; i++) {
            fill_up[i] = (flowers[i] - flowers[i-1]) * (long long)i + fill_up[i-1];
        }
        // fill_target[i] fill flowers[i] to flowers[n-1] to target level
        fill_target[n-1] = (long long) target - flowers[n-1];
        for(int i = n - 2; i >= 0; i--) {
            fill_target[i] = fill_target[i+1] + (long long)(target - flowers[i]); 
        }
        long long ret = 0;
        for(int num_fill = 0; num_fill <= n; num_fill++) {
            long long m = 0;
            long long rm = newFlowers;
            if(num_fill != 0) {
                rm -= fill_target[n-num_fill];
            }
            if(rm < 0) break;
            if(num_fill != n) {
                auto ptr = upper_bound(fill_up.begin(), fill_up.end(), rm);
                // can get min to flowers[idx-1] level, but not flowers[idx] level
                int idx = ptr - fill_up.begin();
                if(idx >= n - num_fill) idx = n - num_fill;
                m = flowers[idx - 1];
                m += (rm - fill_up[idx - 1]) / idx; 
                m = min(m, (long long)target - 1);
            }
            long long tmp = m * (long long) partial + (full_cnt + num_fill) * (long long) full;
            ret = max(tmp, ret);
        }
        return ret;
    }
};