class RecentCounter {
private:
    int* counter;
    int i; // next to check
    int j; // next to insert

public:
    RecentCounter() {
        counter = new int[10000];
        i = 0;
        j = 0;
    }
    
    int ping(int t) {
        counter[j] = t;
        j++;

        // begin check

        while (counter[i] < t - 3000) {
            i++;
        }

        return j-i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */