class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        for(int i=0;i<t.size();i++){
            if(t[i] == "+" || t[i] == "-" ||t[i] == "*" ||t[i] == "/"){
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                if(t[i] == "+"){
                    s.push(num1+num2);
                }
                else if(t[i] == "-"){
                    s.push(num1-num2);
                }
                else if(t[i] == "/"){
                    s.push(num1/num2);
                }
                else if(t[i] == "*"){
                    s.push(num1*num2);
                }
            }
            else{
                    s.push(stoi(t[i]));
            }
            
        }
        return s.top();
    }
};