class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
      vector<int> res(n, 0);
      int pid;
      char action[6];
      int cur;
      int pre;
      stack<int> numStack;

      for(const auto& log : logs) {
        sscanf(log.c_str(), "%d:%[a-z]:%d", &pid, action, &cur); // this line of code caused bug
        if(action[0] == 's') {
          if(!numStack.empty()) {
            res[numStack.top()] += cur-pre;
          }
          pre = cur;
          numStack.push(pid);
        }
        else {
          res[numStack.top()] += cur-pre+1;
          numStack.pop();
          pre = cur+1;
        }
      }

      return res;
    }
};
