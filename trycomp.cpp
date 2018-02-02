#include <queue>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unordered_map>


using namespace std;

unordered_map<string, string> prefixWord;
unordered_map<string, int> wordCount;
/*struct trie_node {
    struct trie_node* children[26];
    bool isEndOfWord;
    int noOfOccurrences;
    char word[15];
};

queue<trie_node*> bfsQueue;


struct trie_node* getNode() {
    struct trie_node* newNode = (struct trie_node*)malloc(sizeof(struct trie_node));
    newNode -> isEndOfWord = false;
    newNode -> noOfOccurrences = 0;
    for(int i = 0; i < 26; i++) {
        newNode -> children[i] = NULL;
    }
    return newNode;
}

struct trie_node* queryNode(struct trie_node* root, char query[15]) {
    int index = 0;
    struct trie_node* emptyPtr = getNode();
    emptyPtr -> noOfOccurrences = -1;
    int queryLen = strlen(query);
    for(int i = 0; i < queryLen; i++) {
        index = query[i] - 'a';
        if (root -> children[index]) {
            root = root -> children[index];
        }
        else {
            return emptyPtr;
        }
    }
    return root;

}

struct trie_node* resultUsingBfs(struct trie_node* queryNode) {
    struct trie_node* resultNode;
    struct trie_node* currNode;
    bfsQueue.push(queryNode);
    while(!bfsQueue.empty()) {
        for (int i = 0; i < bfsQueue.size(); i++) {
            currNode = bfsQueue.front();
            for (int j = 0; j < 26; j++) {
                if (currNode -> children[j]) {
                    bfsQueue.push(currNode -> children[j]);
                }
            }
            if (currNode -> isEndOfWord) {
                if (!resultNode)
                    resultNode = currNode;
                else {
                    if (currNode -> noOfOccurrences > resultNode -> noOfOccurrences)
                        resultNode = currNode;
                    if (currNode -> noOfOccurrences == resultNode -> noOfOccurrences && strcmp(currNode -> word, resultNode -> word) < 0)
                        resultNode = currNode;
                }
            }
            bfsQueue.pop();
        }
    }
    return resultNode;

}

void insertWord(struct trie_node* root, char key[15]) {
    int index = 0;
    int keyLen = strlen(key);
    for(int i = 0; i < keyLen; i++) {
        index = key[i] - 'a';
        if (!root -> children[index]) {
            root -> children[index] = getNode();
        }
        root = root -> children[index];
    }
    root -> isEndOfWord = true;
    strcpy(root -> word, key);
    root -> noOfOccurrences += 1;
}


int main() {
    int n, q;
    scanf("%d",&n);
    char query[15];
    char word[15];
    struct trie_node* root = getNode();
    struct trie_node* interNode;
    struct trie_node* resultNode;
    for(int i = 0; i < n; i++) {
        scanf("%s",word);
        insertWord(root, word);
    }
    scanf("%d",&q);
    for(int j = 0; j < q; j++) {
        scanf("%s",query);
        interNode = queryNode(root, query);
        if (interNode -> noOfOccurrences != -1) {
            resultNode = resultUsingBfs(interNode);
            printf("%s %d\n",resultNode -> word,resultNode -> noOfOccurrences);
        }
        else {
            printf("-1\n");
        }

    }
    return 0;
}*/
void updateCountMap(string word) {
    if (wordCount.find(word) != wordCount.end()) {
        wordCount[word] += 1;
    }
    else {
        wordCount[word] = 1;
    }
}

void updatePrefixMap(string word) {
    string prefix;
    for (int i = 0; i < word.length(); i++) {
        prefix += word[i];
        if (prefixWord.find(prefix) != prefixWord.end()) {
            if (wordCount[word] > wordCount[prefixWord[prefix]]) {
                prefixWord[prefix] = word;
            }
            if (wordCount[word] == wordCount[prefixWord[prefix]]) {
                if (word.compare(prefixWord[prefix]) < 0) {
                    prefixWord[prefix] = word;
                }

            }
        }
        else {
            prefixWord[prefix] = word;
        }
    }
}

int main() {
    int n,q;
    string word,query;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        cin>>word;
        updateCountMap(word);
        updatePrefixMap(word);
    }
    scanf("%d", &q);
    for(int j = 0; j < q; j++) {
        cin>>query;
        if (prefixWord.find(query) != prefixWord.end()) {
            cout<<prefixWord[query]<<" "<<wordCount[prefixWord[query]]<<endl;
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}
