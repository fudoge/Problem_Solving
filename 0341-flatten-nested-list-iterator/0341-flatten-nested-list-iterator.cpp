/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> flattened;
    int index;

    vector<int> flatten(vector<NestedInteger> nested) {
        vector<int> result;
        for(const auto &n : nested) {
        //요소가 배열이 아닌 정수라면:
            if(n.isInteger()) {
                result.push_back(n.getInteger());
            //배열이라면:
            } else {
                auto subList = flatten(n.getList());
                result.insert(result.end(), subList.begin(), subList.end());
            }
        }
        return result;
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattened = flatten(nestedList);
         index = 0;
    }
    
    int next() {
        return flattened[index++];
    }
    
    bool hasNext() {
        return index < flattened.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */