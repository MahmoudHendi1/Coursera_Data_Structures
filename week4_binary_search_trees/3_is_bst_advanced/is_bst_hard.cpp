#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long long key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

 bool psh(int i,long long mn,long long mx,const vector<Node>& tree){
        if(i ==-1 || i>=tree.size())
            return true;
        if(tree[i].key<mn ||tree[i].key>mx  )
            return false;
        return psh(tree[i].left,mn,tree[i].key-1,tree)&&psh(tree[i].right,tree[i].key,mx,tree);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    long long key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  long long mn = -21474835648ll, mx=21471483647ll;
  if (psh(0,mn,mx,tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
