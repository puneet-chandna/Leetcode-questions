#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source;
    int destination;
    int timestamp;
    bool operator==(Packet const &o) const {
        return source == o.source 
            && destination == o.destination 
            && timestamp == o.timestamp;
    }
};

struct PacketHash {
    size_t operator()(Packet const &p) const noexcept {
        // Combine into 64-bit
        // shift sizes chosen so overlaps avoided
        uint64_t h = ((uint64_t)p.source << 42) ^ ((uint64_t)p.destination << 21) ^ (uint64_t)p.timestamp;
        return std::hash<uint64_t>()(h);
    }
};

class Router {
private:
    int memoryLimit;
    deque<Packet> q;
    unordered_set<Packet, PacketHash> uniqueSet;
    unordered_map<int, vector<int>> destTimestamps;
    unordered_map<int, int> processedIdx;  // how many earliest timestamps for each destination are no longer active

public:
    Router(int memoryLimit_) : memoryLimit(memoryLimit_) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (uniqueSet.find(p) != uniqueSet.end()) return false;
        if ((int)q.size() == memoryLimit) {
            Packet old = q.front();
            q.pop_front();
            uniqueSet.erase(old);
            processedIdx[old.destination]++;
        }
        q.push_back(p);
        uniqueSet.insert(p);
        destTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet p = q.front();
        q.pop_front();
        uniqueSet.erase(p);
        processedIdx[p.destination]++;
        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end()) return 0;
        const vector<int> &v = it->second;
        int skip = processedIdx[destination];
        // Make sure skip is not larger than v.size()
        // Using binary search over [skip, v.size())
        auto lb = lower_bound(v.begin() + skip, v.end(), startTime);
        auto ub = upper_bound(v.begin() + skip, v.end(), endTime);
        return (int)(ub - lb);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */