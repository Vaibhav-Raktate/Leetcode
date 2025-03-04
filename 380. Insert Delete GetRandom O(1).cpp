class RandomizedSet {
    public:
        vector<int>v;
        int ind=0;
        unordered_map<int,int>map;
        RandomizedSet() {
            int ind=0;
            v.clear();
            map.clear();
            map.clear();
        }
        
        bool insert(int val) {
            if(map.find(val)!=map.end())
            return false;
    
            map[val]=ind++;
            v.push_back(val);
            return true;
        }
        
        bool remove(int val) {
            if(map.find(val)==map.end())
            return false;
            //get index
            int i=map[val];
            //swap
            swap(v[i],v[ind-1]);
            map[v[i]]=i;
            //remove
            v.pop_back();
            ind--;
            map.erase(val);
            return true;
        }
        
        int getRandom() {
            int i=rand()%ind;
            return v[i];
        }
    };
    
    /**
     * Your RandomizedSet object will be instantiated and called as such:
     * RandomizedSet* obj = new RandomizedSet();
     * bool param_1 = obj->insert(val);
     * bool param_2 = obj->remove(val);
     * int param_3 = obj->getRandom();
     */