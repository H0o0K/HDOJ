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
    memset(node->next , 0 , sizeof(node->next));    // ��ʼ��Ϊ��ָ��  
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
        node->count += 1;      // ���д�������ͳ��ÿ������ǰ׺���ֵĴ�����Ҳ����ͳ��ÿ�����ʳ��ֵĴ�����  
    }  
    node->exist = true;        // ���ʽ����ĵط���Ǵ˴����Թ���һ������  
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