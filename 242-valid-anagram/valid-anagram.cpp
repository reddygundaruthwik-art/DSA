class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }
        vector<int> alpha(26,0);

        for(int i = 0; i < s.size(); i++){
            alpha[s[i] - 'a']++;
        }
        string anss = "";
        for( int i = 0; i < 26; i++){
            char c = 'a' + i;

            while(alpha[i]){
                anss += c;
                alpha[i]--;
            }
        }

        vector<int> dupalpha(26,0);

        for(int j = 0; j < t.size(); j++){
            dupalpha[t[j] - 'a']++;
        }
        string anst = "";
        for (int j = 0; j < 26; j++){
            char e = 'a' + j;

            while(dupalpha[j]){
                anst += e;
                dupalpha[j]--;
            }
        }
        if(anss != anst){
            return false;
        }
        return true;
    }
};