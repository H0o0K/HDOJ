#include<iostream>
#include<string>
using namespace std;

class TrieNode
{
private:
	int count;
	TrieNode *next[26];
	bool exist;
public:
	TrieNode();
	~TrieNode();
	TrieNode * createNode();
	void Trie_insert(TrieNode *root, const char* word);
	int Trie_search(TrieNode *root, const char* word);
};

TrieNode::TrieNode()
{
    count = 0;  
    exist = false;  
    memset(next , 0 , sizeof(next));   
}
TrieNode::~TrieNode()
{
}
TrieNode* TrieNode::createNode()  
{  
    TrieNode* node = (TrieNode *)malloc(sizeof(TrieNode));  
    node->count = 0;  
    node->exist = false;  
    memset(node->next , 0 , sizeof(node->next));    // 初始化为空指针  
    return node;  
} 
void TrieNode::Trie_insert(TrieNode *root, const char* word)  
{  
	if(strlen(word)==0)
		return;
    TrieNode *node = root;  
    const char *p = word;  
    int id;  
    while( *p )  
    {  
        id = *p - 'a';  
        if(node->next[id] == NULL)  
        {  
			node->next[id] = node->createNode();  
        }  
        node = node->next[id];  
        ++p;  
        node->count += 1;      // 这行代码用于统计每个单词前缀出现的次数（也包括统计每个单词出现的次数）  
    }  
    node->exist = true;        // 单词结束的地方标记此处可以构成一个单词  
} 
int TrieNode::Trie_search(TrieNode *root, const char* word)  
{ 
	if(strlen(word)==0)
		return false;
    TrieNode *node = root;  
    const char *p = word;
    int id;  
    while( *p )  
    {  
        id = *p - 'a';  
        node = node->next[id];  
        ++p;  
        if(node == NULL)  
            return 0;  
    }  
    return node->count; 
} 

int main()
{
	TrieNode TN;
	TrieNode *root = TN.createNode();
	string s;
    bool flag = false;
	while(getline(cin,s))
	{
		const char* word = s.c_str();
		if(flag)  
            cout<<TN.Trie_search(root , word)<<endl;  
        else  
        {  
			if(s.length() != 0)  
            {  
                TN.Trie_insert(root , word);  
            }  
            else  
                flag = true;  
        }  
	}
	return 0;
}