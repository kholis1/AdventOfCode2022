#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class treeNode {
    public:
        string dir;
        int size;
        treeNode *parent;
        vector<treeNode *>children;

        treeNode(treeNode *parent, string dir){
            this->dir = dir;
            this->parent = parent;
            this->size = 0;
        };

        void addChild(string childDir){
            treeNode *newChild = new treeNode(this, childDir);
            this->children.push_back(newChild);
        }

        void addSize(int size){
            this->size += size;
        }

        int nodeSize(){
            int childrenTotalSize = this->size;

            if(this->children.empty())
                return childrenTotalSize;

            for(treeNode *child : this->children)
                childrenTotalSize += child->nodeSize();

            return childrenTotalSize;
        }

        int partA(){
            if(this->children.empty()){
                if(this->nodeSize() <= 100000){
                    return this->nodeSize();
                }
                else{
                    return 0;
                } 
            }

            int totalSize = 0;
            for(treeNode *child : this->children){
                totalSize += child->partA();
            }

            if(this->nodeSize() <= 100000){
                totalSize += nodeSize();
            }

            return totalSize;
        }

        int partB(int target, int min){
            int nSize = this->nodeSize();

            if(nSize >= target && nSize < min)
                min = nSize;
            
            if(this->children.empty())
                return min;

            for(treeNode *child : this->children){
                int cSize = child->partB(target, min);
                if(cSize < min)
                    min = cSize;
            }
            
            return min;

        }
        
};

void getSentence(vector<string> &words, string line){
    string word;
    istringstream iss(line);

    while (iss >> word) {
        words.push_back(word);
    }
}

int main() {
    ifstream myfile;

    string line;
    myfile.open("input.txt");

    treeNode *root = new treeNode(NULL, "/");
    treeNode *iter = root;
    int count = 0;
    while(getline(myfile, line)){
        count++;
        vector<string> words;
        getSentence(words, line);

        if(words[0] == "$"){
            if(words[1] == "cd"){
                if(words[2] == ".."){
                    iter = iter->parent;
                } else {
                    for(treeNode *node : iter->children){
                        if(node->dir == words[2]){
                            iter = node;
                        }
                    }
                }
            }
        } else if (words[0] == "dir"){
            iter->addChild(words[1]);
        } else {
            iter->addSize(stoi(words[0]));
        }

    } 
// 70000000 - root->nodeSize() = 43636666

    cout << "Part A: " << root->partA() << endl;
    cout << "Part B: " << root->partB( 30000000 - (70000000 - root->nodeSize()), 10000000) << endl;

}

// 6705963 too high