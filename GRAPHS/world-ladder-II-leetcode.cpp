class Solution {
public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        if (!words.count(endWord))
            return ans;

        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> levelVisited;

            while (size--) {
                string word = q.front();
                q.pop();

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original)
                            continue;

                        word[i] = c;

                        if (!words.count(word))
                            continue;

                        // First time seeing this word
                        if (!visited.count(word)) {
                            if (!levelVisited.count(word)) {
                                q.push(word);
                                levelVisited.insert(word);
                            }

                            parent[word].push_back(
                                q.empty() ? "" : ""
                            );
                        }

                        // Also allow another parent from same level
                        if (levelVisited.count(word)) {
                            string p = word;
                            p[i] = original;
                            parent[word].push_back(p);
                        }

                        if (word == endWord)
                            found = true;
                    }

                    word[i] = original;
                }
            }

            for (auto& word : levelVisited)
                visited.insert(word);
        }

        vector<string> path = {endWord};

        function<void(string)> dfs = [&](string word) {
            if (word == beginWord) {
                vector<string> temp = path;
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                return;
            }

            for (string p : parent[word]) {
                if (p.empty())
                    continue;

                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };

        dfs(endWord);

        return ans;
    }
};
