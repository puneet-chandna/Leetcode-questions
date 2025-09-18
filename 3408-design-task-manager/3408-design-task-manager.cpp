class TaskManager {
struct T {
        int priority;
        int taskId;
        bool operator<(T const &o) const {
            if (priority != o.priority) return priority < o.priority;
            return taskId < o.taskId;
        }
    };

    
    unordered_map<int,int> taskUser;     
    unordered_map<int,int> taskPri;      
    priority_queue<T> pq;                
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &tr : tasks) {
            int u = tr[0], t = tr[1], p = tr[2];
            taskUser[t] = u;
            taskPri[t] = p;
            pq.push(T{p, t});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskUser[taskId] = userId;
        taskPri[taskId] = priority;
        pq.push(T{priority, taskId});
    }

    void edit(int taskId, int newPriority) {
     
        taskPri[taskId] = newPriority;
        pq.push(T{newPriority, taskId});
    }

    void rmv(int taskId) {
        taskUser.erase(taskId);
        taskPri.erase(taskId);
      
    }

    int execTop() {
        while (!pq.empty()) {
            T top = pq.top();
            pq.pop();
            int t = top.taskId;
            int p = top.priority;
        
            auto it = taskPri.find(t);
            if (it == taskPri.end()) {
              
                continue;
            }
            if (it->second != p) {
            
                continue;
            }
           
            int u = taskUser[t];
            
            taskUser.erase(t);
            taskPri.erase(t);
            return u;
        }
        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */