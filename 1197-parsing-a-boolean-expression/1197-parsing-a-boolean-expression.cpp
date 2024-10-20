class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> operators;
        stack<char> operands;

        for(const char& ch : expression) {
            if(ch == '&' || ch == '|' || ch == '!') {
                operators.push(ch);
            } else if(ch == '(') {
                operands.push(ch);
            } else if(ch == 't' || ch == 'f') {
                operands.push(ch);
            } else if(ch == ')') {
                char op = operators.top();
                operators.pop();
                char res = operands.top();
                operands.pop();
                
                switch (op) {
                    case '!': {
                        res = res == 't'? 'f' : 't';
                        break;
                    }
                    case '&' : {
                        while(operands.top() != '(') {
                            res = res == 't' && operands.top() == 't'? 't':'f';
                            operands.pop();
                        }
                        break;
                    }
                    case '|': {
                        while(operands.top() != '(') {
                            res = res == 't' || operands.top() == 't'? 't':'f';
                            operands.pop();
                        }
                        break;
                    }
                }
                operands.pop();
                operands.push(res);
            }
        }

        return operands.top() == 't';
    }
};