class Solution {
public:
    string parseAtomName(const string& formula, int& i) {
        string name;
        name += formula[i++];
        while (i < formula.size() && islower(formula[i])) {
            name += formula[i++];
        }
        return name;
    }

    int parseMultiplier(const string& formula, int& i) {
        int multiplier = 0;
        while (i < formula.size() && isdigit(formula[i])) {
            multiplier = multiplier * 10 + (formula[i++] - '0');
        }
        return multiplier == 0 ? 1 : multiplier;
    }

    unordered_map<string, int> parseFormula(const string& formula, int& i) {
        unordered_map<string, int> atomCount;
        int n = formula.size();
        while (i < n && formula[i] != ')') {
            if (formula[i] == '(') {
                i++;
                unordered_map<string, int> innerCount = parseFormula(formula, i);
                i++;
                int multiplier = parseMultiplier(formula, i);
                for (const auto& pair : innerCount) {
                    atomCount[pair.first] += pair.second * multiplier;
                }
            } else {
                string name = parseAtomName(formula, i);
                int count = parseMultiplier(formula, i);
                atomCount[name] += count;
            }
        }
        return atomCount;
    }
    string countOfAtoms(string formula) {
        int i = 0;
        unordered_map<string, int> atomCount = parseFormula(formula, i);
        vector<pair<string, int>> sortedAtoms(atomCount.begin(), atomCount.end());
        sort(sortedAtoms.begin(), sortedAtoms.end());

        string result;
        for (const auto& atom : sortedAtoms) {
            result += atom.first;
            if (atom.second > 1) {
                result += to_string(atom.second);
            }
        }
        return result;
    }
};