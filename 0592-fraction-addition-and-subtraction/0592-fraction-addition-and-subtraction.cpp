class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }

    string fractionAddition(string expression) {
        int curr_numerator = 0, curr_denominator = 1;
        int i = 0, n = expression.size();

        while (i < n) {
            int sign = 1;
            if (expression[i] == '-' || expression[i] == '+') {
                sign = (expression[i++] == '-') ? -1 : 1;
            }

            int numerator = 0;
            while (isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i++] - '0');
            }
            numerator *= sign;

            i++;

            int denominator = 0;
            while (i < n && isdigit(expression[i])) {
                denominator = denominator * 10 + (expression[i++] - '0');
            }

            int lcm_val = lcm(curr_denominator, denominator);
            curr_numerator = curr_numerator * (lcm_val / curr_denominator) + numerator * (lcm_val / denominator);
            curr_denominator = lcm_val;
        }

        int g = gcd(abs(curr_numerator), curr_denominator);
        curr_numerator /= g;
        curr_denominator /= g;

        return to_string(curr_numerator) + '/' + to_string(curr_denominator);
    }
};