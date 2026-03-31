class EventManager {
public:
    priority_queue<pair<int,int>> pq;
    unordered_map<int,int> mp;

    EventManager(vector<vector<int>>& events) {
        for(auto &e : events){
            int id = e[0], priority = e[1];
            pq.push({priority, -id});
            mp[id] = priority;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        pq.push({newPriority, -eventId});
        mp[eventId] = newPriority;  // update latest
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [p, id] = pq.top();
            id = -id;

            // skip outdated entries
            if(mp[id] != p){
                pq.pop();
                continue;
            }

            pq.pop();
            mp.erase(id); // remove active event
            return id;
        }
        return -1;
    }
};
// int ,int
// prio , id
// return a < b 
// map int  , pq minheap = prio , 
/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */