class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int left = 0, right = skill.size()-1;
        int total = skill[left] + skill[right];
        long long ans = skill[left++] * skill[right--];
        
        while(left < right) {
            if(total != skill[left] + skill[right]) return -1;
            ans += skill[left++] * skill[right--];
        }

        return ans;
    }
};