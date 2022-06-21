class ExamRoom {
public:
    vector<int> seatIndex;
    int no;
    ExamRoom(int n) {
        no = n;
    }
    
    int seat() {
        if(seatIndex.size() == 0){
            seatIndex.push_back(0);
            return 0;
        }
        
        int diff = max(seatIndex[0], (no-1-seatIndex.back()));
        for(int i=0;i<seatIndex.size()-1;i++){
            diff = max(diff, (seatIndex[i+1]-seatIndex[i])/2);
        }
        if(seatIndex[0] == diff){
            seatIndex.insert(seatIndex.begin(), 0);
            return 0;
        }
        for(int i=0;i<seatIndex.size()-1;i++){
            if((seatIndex[i+1]-seatIndex[i])/2 == diff){
                seatIndex.insert(seatIndex.begin()+i+1, (seatIndex[i+1]+seatIndex[i])/2);
                return seatIndex[i+1];
            }
        }
        seatIndex.push_back(no-1);
        return no-1;
    }
    
    void leave(int p) {
        for(int i=0;i<seatIndex.size();i++){
            if(seatIndex[i] == p)   seatIndex.erase(seatIndex.begin()+i);
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */