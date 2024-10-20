class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> operators;
        stack<char> operands;

        int n = expression.size();
        for(int i = 0; i < n; ++i) {
            if(expression[i] == '&' || expression[i] == '|' || expression[i] == '!') {
                operators.push(expression[i]);
            } else if(expression[i] == '(') {
                operands.push(expression[i]);
            } else if(expression[i] == 't' || expression[i] == 'f') {
                operands.push(expression[i]);
            } else if(expression[i] == ')') {
                char op = operators.top();
                operators.pop();
                char res = operands.top();
                operands.pop();
                
                switch (op) {
                    case '!': {
                        res = res == 't'? 'f' : 't';
                        if(operands.top() == '(') operands.pop();
                        operands.push(res);
                        break;
                    }
                    case '&' : {
                        while(operands.top() != '(') {
                            res = res == 't' && operands.top() == 't'? 't':'f';
                            operands.pop();
                        }
                        operands.pop();
                        operands.push(res);
                        break;
                    }
                    case '|': {
                        while(operands.top() != '(') {
                            res = res == 't' || operands.top() == 't'? 't':'f';
                            operands.pop();
                        }
                        operands.pop();
                        operands.push(res);
                        break;
                    }
                }
            }
        }

        return operands.top() == 't';
    }
};