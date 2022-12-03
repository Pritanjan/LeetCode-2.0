class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(auto i : s){
            mp[i]++;
        }
        
        sort(s.begin(), s.end(), 
            [&mp] (const char a, const char b){
                return (mp[a] == mp[b]) ? a < b : mp[a] > mp[b];
            });
        
        return s;
    }
};