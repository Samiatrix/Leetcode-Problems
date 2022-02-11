class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> unreserevedSeat;
    unordered_map<int, int> reservedSeat;
    SeatManager(int n) {
        for(int currSeat=1;currSeat<=n;currSeat++){
            unreserevedSeat.push(currSeat);
        }
    }
    
    int reserve() {
        int smallestUnreservedSeat = unreserevedSeat.top();
        unreserevedSeat.pop();
        reservedSeat[smallestUnreservedSeat] = 1;
        return smallestUnreservedSeat;
    }
    
    void unreserve(int seatNumber) {
        reservedSeat.erase(seatNumber);
        unreserevedSeat.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */