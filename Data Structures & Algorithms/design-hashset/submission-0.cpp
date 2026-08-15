class MyHashSet {

    std::vector<bool> data_;
    

public:
    MyHashSet() {
        data_.resize(1000001, false);
    }
    
    void add(int key) {
        data_[key] = true;
    }
    
    void remove(int key) {
        data_[key] = false;
    }
    
    bool contains(int key) {
        return data_[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */