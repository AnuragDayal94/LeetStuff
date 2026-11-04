class node{
    public:
        char ch;
        unordered_map<int, node*>map;
        bool isterminal;

        node(char c){
            this->ch=c;
            this->isterminal=false;
        }
};

class Trie {
    node* root;
public:
    Trie() {
        root=new node('-');
    }

    void insertis(node* root, string word){
        if(word.length()==0){
            root->isterminal=true;
            return ;
        }

        char c=word[0];
        node* temp;
        if(root->map.count(c)!=1){
            temp=new node(c);
            root->map[c]=temp;
        }else{
            temp=root->map[c];
        }

        insertis(temp, word.substr(1));
        return ;
    }
    
    void insert(string word) {
        insertis(root, word);
        return;
    }

    bool searchis(node* root, string word){
        if(word.length()==0){
            return root->isterminal;
        }

        node* temp;
        char c=word[0];
        if(root->map.count(c)!=1){
            return false;

        }
        temp=root->map[c];
        return searchis(temp, word.substr(1));
    }
    
    bool search(string word) {
        return searchis(root, word);
    }

    bool solve(node* root, string p){
        if(p.length()==0){
            return true;
        }
        node* temp;
        char c=p[0];
        if(root->map.count(c)!=1){
            return false;
        }

        temp=root->map[c];
        return solve(temp, p.substr(1));
    }
    
    bool startsWith(string prefix) {
        return solve(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */