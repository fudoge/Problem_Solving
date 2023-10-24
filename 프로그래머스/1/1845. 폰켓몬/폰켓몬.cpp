#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    unordered_map<int, int> pokemon_dogam;
    int pokemons = 0;
    int idx = 0;

    while(idx < n && pokemons < n/2) {
        if(pokemon_dogam[nums[idx]] == 0) {
            pokemon_dogam[nums[idx]]++;
            pokemons++;
        }
        idx++;
    } 

    return pokemons;
}