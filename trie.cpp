#include<bits/stdc++.h>
using namespace std;

const int maxn = 26;

typedef struct Trie
{
    bool flag;
    Trie *next[maxn];
}Trie;

Trie *root;

void trie_init()
{
    int i;
    root = new Trie;
    root->flag = false;
    for(i=0;i<maxn;i++)
        root->next[i] = NULL;
}


void trie_insert(char *word)
{
    //int i = 0;
    //while(word[i] != '\0')
    Trie *tem = root;
    int i;
    while(*word != '\0')
    {
       // cout << "root**" << tem->next[0];
        if(tem->next[*word-'a'] == NULL)// 为空才建立
        {
            Trie *cur = new Trie;
            cur->flag = false;
            for(i=0;i<maxn;i++)
                cur->next[i] = NULL;
            tem->next[*word-'a'] = cur;
        }
        tem = tem->next[*word-'a'];
        //cout << *word << "**";
        word++;
    }
    tem->flag = true;//插入一个完整的单词
}
// 查找一个字符串
bool trie_search(char *word)
{
    Trie *tem = root;
    int i;
    for(i=0; word[i]!='\0'; i++)
    {
        if(tem==NULL || tem->next[word[i]-'a']==NULL)
            return false;
        tem = tem->next[word[i]-'a'];
    }
    return tem->flag;
}


void trie_del(Trie *cur)
{
    int i;
    for(i=0;i<maxn;i++)
    {
        if(cur->next[i] != NULL)
            trie_del(cur->next[i]);
    }
    delete cur;
}


int main()
{
    int i,n;
    char tmp[50];
    trie_init();
    cout << "Please enter the string of the initialization dictionary tree (character 0 end):：" << endl;
    while(cin >> tmp)
    {
        //cout << tmp << endl;
        if(tmp[0] == '0' && tmp[1] =='\0') break;
        trie_insert(tmp);
    }
    cout << "Please enter the string you want to find：" << endl;
    while(cin >> tmp)
    {
        //cout << tmp << endl;
        if(tmp[0] == '0' && tmp[1] =='\0') break;
        if(trie_search(tmp))
            cout << "Find success! Re-enter the search, character 0 end search:" << endl;
        else
            cout << "Find failed! Re-enter the search, character 0 end search:" << endl;
    }
    return 0;
}