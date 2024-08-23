class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a%b);
    }

    int get_lcm(int a, int b) {
        return a * b / gcd(max(a, b), min(a, b));
    }

    string fractionAddition(string expression) {
        vector<pair<int, int>> fracs;
        for(int i = 0; i < expression.size(); i++) {
            bool isPositive = true;
            int numerator = 0;
            int denominator = 0;
            if(expression[i] == '-') {
                isPositive = false;
            } else if(i == 0) i--;
            i++;
            
            while(isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i++] - '0');
            }
            ++i;

            while(isdigit(expression[i])) {
                denominator = denominator * 10 + (expression[i++] - '0');
            }
            --i;

            if(!isPositive) {
                numerator *= -1;
            }

            fracs.push_back({numerator, denominator});
        }

        int curr_numerator = 0;
        int curr_denominator = 1;

        for(auto &f : fracs) {
            int lcm = get_lcm(curr_denominator, f.second);

            curr_numerator *= lcm / curr_denominator;
            f.first *= lcm / f.second;

            curr_numerator += f.first;
            curr_denominator = lcm;
        }

        if(curr_numerator == 0) return "0/1";
        int g = gcd(max(curr_numerator, curr_denominator), min(curr_numerator, curr_denominator));
        curr_numerator /= g;
        curr_denominator /= g;
        if(curr_denominator < 0) {
            curr_numerator *= -1;
            curr_denominator *= -1;
        }
        return to_string(curr_numerator) + '/' + to_string(curr_denominator);
    }
};