#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

unordered_map<string,int> wordIndex;
unordered_map<int,string> indexWord;

struct trie_node {
    struct trie_node* children[26];
    int sufixMatch[2];
    bool isEndOfWord;

};

struct trie_node* getNode() {
    struct trie_node* newNode = (struct trie_node*)malloc(sizeof(struct trie_node));
    newNode -> isEndOfWord = false;
    newNode -> sufixMatch[0] = -1;
    newNode -> sufixMatch[1] = -1;
    for (int i = 0; i < 26; i++) {
        newNode -> children[i] = NULL;
    }
    return newNode;
}


vector<int> orderWords(int a, int b, int c) {
    vector<string> result;
    vector<int> orderIndex;
    if(b == -1) {
         if(a != c) {
            result.push_back(indexWord[a]);
            result.push_back(indexWord[c]);
         }
         else {
            result.push_back(indexWord[a]);
            result.push_back(indexWord[b]);
        }
    }
    else {
        if (a == c || b == c) {
            result.push_back(indexWord[a]);
            result.push_back(indexWord[b]);
        }
        else if (a == b) {
            result.push_back(indexWord[b]);
            result.push_back(indexWord[c]);
        }
        else {
            result.push_back(indexWord[a]);
            result.push_back(indexWord[b]);
            result.push_back(indexWord[c]);
        }

    }

    sort(result.begin(), result.end());
    orderIndex.push_back(wordIndex[result[0]]);
    orderIndex.push_back(wordIndex[result[1]]);
    return orderIndex;
}

void insertTrieNode(struct trie_node* root, string word) {
    int index;
    if (indexWord.find(root -> sufixMatch[0]) == indexWord.end()) {
            root -> sufixMatch[0] = wordIndex[word];
    }
    else {
        vector<int> sufixOrder = orderWords(root -> sufixMatch[0], root -> sufixMatch[1], wordIndex[word]);
        root -> sufixMatch[0] = sufixOrder[0];
        root -> sufixMatch[1] = sufixOrder[1];

    }
    for(int i = word.length() - 1; i >= 0; i--) {
        index = word[i] - 'a';
        if (root -> children[index]) {
            root = root -> children[index];
            vector<int> sufixOrder = orderWords(root -> sufixMatch[0], root -> sufixMatch[1], wordIndex[word]);
            root -> sufixMatch[0] = sufixOrder[0];
            root -> sufixMatch[1] = sufixOrder[1];
        }
        else {
            root -> children[index] = getNode();
            root -> children[index] -> isEndOfWord = false;
            root -> children[index] -> sufixMatch[0] = wordIndex[word];
            root = root -> children[index];
        }

    }
    root -> isEndOfWord = true;
}

string queryWord(struct trie_node* root, string query) {
    int index;
    string result;
    for(int i = query.length() - 1; i >= 0; i--) {
        index = query[i] - 'a';
        if (root -> children[index]) {
            if(indexWord[root -> sufixMatch[0]] != query) {
                if(root ->sufixMatch[0] != -1)
                    result = indexWord[root -> sufixMatch[0]];
            }
            else {
                if(root ->sufixMatch[1] != -1)
                    result = indexWord[root -> sufixMatch[1]];
            }
            root = root -> children[index];
        }
        else {
            break;
        }
    }
    //cout<<"Test Query: "<<root -> sufixMatch[0]<<" "<<root -> sufixMatch[1]<<endl;
    //cout<<root -> sufixMatch[0]<<query<<endl;
    if(indexWord[root -> sufixMatch[0]] != query) {
        if(root ->sufixMatch[0] != -1)
            result = indexWord[root -> sufixMatch[0]];
    }
    else {
        if(root ->sufixMatch[1] != -1)
            result = indexWord[root -> sufixMatch[1]];
    }
    return result;
}

/*string readInputWord() {

    char c[31];
    fgets (c, sizeof(c), stdin);
    if (c[0] != '\n' && c[0] != EOF) {
        string retString(c);
        return retString;
    }
    return "";


}*/


int main() {
    string word,query;
    int countIndex = 0;
    char line[35];
    char queryLine[35];
    struct trie_node* root = getNode();
    while(1) {
        fgets(line, sizeof(line), stdin);
        if (line[0] == '\n') break;
        word = line;
        word.pop_back();
        wordIndex[word] = countIndex;
        indexWord[countIndex] = word;
        insertTrieNode(root,word);
        countIndex++;
    }
    //cout<<" Test "<<root -> children[4] -> children['m' - 'a'] -> children['i' - 'a'] -> sufixMatch[0]<<" "<<root -> children[4] -> children['m' - 'a'] -> children['i' - 'a'] -> sufixMatch[1] <<endl;
    while(scanf("%s",queryLine) != EOF) {
        query = queryLine;
        cout<<queryWord(root,query)<<endl;
    }

    return 0;

}
