class Solution {
public:
    string sortSentence(string s) {
        
        vector<string> ans(10);
        
        string temp = "";

         
        int index = 0;

        while(index < s.size()){

       

        if(s[index] == ' '){

            int pos = temp[temp.size() - 1] - '0';

            temp.pop_back();

            ans[pos] = temp;

            temp.clear();
        }

        else{
            temp += s[index];
            
        }
        index++;
        }
         int pos = temp[temp.size() - 1] - '0';

            temp.pop_back();

            ans[pos] = temp;

            string result = "";

            for(int i = 0; i <= 9; i++){
                if(ans[i]!= ""){
                result += ans[i];
                result += ' ';
                }
            }
         
         result.pop_back();

      return result; 
        
    }
};