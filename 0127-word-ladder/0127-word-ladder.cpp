class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);

        while(!q.empty()){
            auto it=q.front();
            string word=it.first;
            int val=it.second;
            q.pop();
            if(word==endWord)return val;
            
            for(int i=0; i<word.size(); i++){
                char ori=word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        q.push({word,val+1});
                        s.erase(word);
                    }
                }
                word[i]=ori;
            }
        }
        return 0;
    }
};