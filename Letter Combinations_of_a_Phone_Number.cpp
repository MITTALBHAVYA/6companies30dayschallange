class Solution {
public:
    void backtrack(string combination,string next_digits,vector<string>&num_map,vector<string>&output){
        if(next_digits.empty()){
            output.push_back(combination);
        }
        else{
            string letters=num_map[next_digits[0]-'2'];
            for(char letter : letters){
                backtrack(combination+letter,next_digits.substr(1),num_map,output);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>num_map={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>output;
        backtrack("",digits,num_map,output);
        return output;
    }
};