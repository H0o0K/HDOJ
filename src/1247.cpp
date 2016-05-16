#include<iostream>
#include<string>

class TrieNode
{
private:
	int count;
	TrieNode *next[26];
	bool exist;
	char trans[11];
public:
	TrieNode();
	~TrieNode();
	TrieNode * createNode();
	void Trie_insert(TrieNode *root, const char* word, const char* tran);
	char* Trie_search(TrieNode *root, const char* word);
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
void TrieNode::Trie_insert(TrieNode *root, const char* word,const char* tran)  
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
	strcpy(node->trans , tran);
} 
char* TrieNode::Trie_search(TrieNode *root, const char* word)  
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
            return NULL;  
    }  
    if(node->exist)
		return node->trans;
	else
		return NULL;
} 

int main()
{
	TrieNode TN;
	TrieNode *root = TN.createNode();
	
	char str[3001],str1[3001],str2[3001],*p;
    gets(str);
	while(scanf("%s",str) && str[0]!='E')
	{
		scanf("%s",str1);
		TN.Trie_insert(root,str1,str);
	}
	getchar();
	gets(str);
	int k = 0;
	while(gets(str))
	{
		if(str[0]=='E')
			break;
		for(int i=0;str[i]!='\0';++i)
		{
			if(str[i]>='a'&&str[i]<='z')
				str2[k++] = str[i];
			else{
				str2[k]='\0';
				p = TN.Trie_search(root,str2);
				if(p)  
                    printf("%s", p);  
                else  
                    printf("%s", str2);  
                k = 0;  
                printf("%c", str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}