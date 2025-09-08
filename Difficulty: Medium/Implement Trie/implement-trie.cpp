class TriesNode{
    public:
    char value;
    unordered_map<char,TriesNode*>children;
    bool isTerminal;
    
    TriesNode(char data){
        value=data;
        isTerminal=false;
    }
    
};
void insertInTries(TriesNode*root,string word)
{
    //base case:- jab node last charecte per pahuch jaye to
    if(word.length()==0)
    {
        root->isTerminal=true;
        return;
    }
    
    
    
    // 1 case solve kar do baki recursion kar dega
    char ch=word[0];
    TriesNode*child;
    
    //2: case tha
    //1:-absent hai to creat kar do
    //2:-present hai to aage bhada do
    if(root->children.count(ch)==1){
        //presnt
        child=root->children[ch];
    }
    else{
        //absent
        child=new TriesNode(ch);
        root->children[ch]=child;
    }
    insertInTries(child,word.substr(1));
}
bool serchTries(TriesNode*root,string word)
{
    //base case
    if(word.length()==0)
    {
        // return root->isTerminal;
        if(root->isTerminal==true){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    //1:-case solve kar de
    char ch=word[0];
    TriesNode*child;
    if(root->children.find(ch)!=root->children.end())
    {
        //present
        //end kay equal nahi hao
        child=root->children[ch];
    }
    else{
        //absent
        return false;
    }
    bool recAns= serchTries(child,word.substr(1));
    return recAns;
}
bool serchPrefix(TriesNode*root,string word)
{
    //base case
    if(word.length()==0)
    {
        return true;
    }
    
    
    //1:-case solve kar de
    char ch=word[0];
    TriesNode*child;
    if(root->children.find(ch)!=root->children.end())
    {
        //present
        //end kay equal nahi hao
        child=root->children[ch];
    }
    else{
        //absent
        return false;
    }
    bool recAns=serchPrefix(child,word.substr(1));
    return recAns;
}


class Trie {
  public:
    
    TriesNode*root;

    Trie() {
        // implement Trie
        root=new TriesNode('-');
    }

    void insert(string &word) {
        // insert word into Trie
        insertInTries(root,word);
    }

    bool search(string &word) {
        // search word in the Trie
        bool ans=serchTries(root,word);
        return ans;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        bool ans=serchPrefix(root,word);
        return ans;
    }
};

