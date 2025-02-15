class SmallestInfiniteSet {
private:
    set<int> data;
    int maxInitialized;
public:
    SmallestInfiniteSet() {
        this->maxInitialized = 10;
        for (int i = 1; i <= this->maxInitialized; i++) {
            this->data.insert(i);
        }
    }
    
    int popSmallest() {
        if (this->data.empty()) {
            for (int i = 1; i <= 10; i++) {
                this->data.insert(this->maxInitialized+i);
            }
            this->maxInitialized += 10;
        }

        int value = *(this->data.begin());
        this->data.erase(this->data.begin());

        return value;
    }
    
    void addBack(int num) {
        if (num > this->maxInitialized) {
            for (int i = this->maxInitialized + 1; i < num; i++) {
                this->data.insert(i);
            }
            this->maxInitialized = num;
        }
        this->data.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */