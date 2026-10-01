class Solution {
public:
    vector<string> ans;

    vector<string> letters = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index, string& current) {
        // We've chosen one letter for every digit
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string possible = letters[digits[index] - '0'];

        for (char ch : possible) {
            current.push_back(ch);

            backtrack(digits, index + 1, current);

            current.pop_back(); // undo choice
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        string current;
        backtrack(digits, 0, current);

        return ans;
    }
};
