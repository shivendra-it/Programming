#include<bits/stdc++.h>
using namespace std;

const int nsize = 26;

typedef struct Trie{
    bool flag;
    Trie *next[nsize]; 
}Trie;

Trie *root;

void  create_trie(){
    int i;
    root = new Trie;
    root->flag = false;
    for(i=0;i<nsize;i++)
        root->next[i]=NULL;
}


void insert_trie(char *word){
    Trie *tem  = root;
    int i;
    while(*word !='\0'){
        if(tem->next[*word - 'a']==NULL){
            Trie *cur = new Trie;
            cur -> flag = false;
            for(i =0;i<nsize;i++)
                cur->next[i]=NULL;
            tem->next[*word - 'a'] = cur;
        }
        tem  = tem->next[*word-'a'];
        word++;
    }

}


bool search_trie(char *word){
    Trie *tem = root;
    int i;
    for(i=0;word[i]!='\0';i++){
        if(tem==NULL || tem->next[word[i] - 'a']==NULL)
            return false;
        tem = tem->next[word[i] - 'a'];
    }
    return tem->flag;
}


int main(){

    int i,n;
    char tmp[50];
    create_trie();
    cout << "Please enter the string of the initialization dictionary tree (character 0 end):：" << endl;
    while(cin >> tmp)
    {
        //cout << tmp << endl;
        if(tmp[0] == '0' && tmp[1] =='\0') break;
        insert_trie(tmp);
    }
    cout << "Please enter the string you want to find：" << endl;
    while(cin >> tmp)
    {
        //cout << tmp << endl;
        if(tmp[0] == '0' && tmp[1] =='\0') break;
        if(search_trie(tmp))
            cout << "Find success! Re-enter the search, character 0 end search:" << endl;
        else
            cout << "Find failed! Re-enter the search, character 0 end search:" << endl;
    }

    return 0;
}