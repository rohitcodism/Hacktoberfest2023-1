#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct MerkleNode {
  string hash;
  MerkleNode* left;
  MerkleNode* right;
};

MerkleNode* CreateMerkleNode(string hash) {
  MerkleNode* node = new MerkleNode();
  node->hash = hash;
  node->left = NULL;
  node->right = NULL;
  return node;
}

MerkleNode* BuildMerkleTree(vector<string>& hashes) {
  if (hashes.size() == 1) {
    return CreateMerkleNode(hashes[0]);
  }

  // Create a new Merkle node for each pair of hashes.
  vector<MerkleNode*> parents;
  for (int i = 0; i < hashes.size() / 2; i++) {
    MerkleNode* parent = CreateMerkleNode(hashes[i] + hashes[hashes.size() - 1 - i]);
    parent->left = CreateMerkleNode(hashes[i]);
    parent->right = CreateMerkleNode(hashes[hashes.size() - 1 - i]);
    parents.push_back(parent);
  }

  // If the number of hashes is odd, add the last hash to the parents vector.
  if (hashes.size() % 2 == 1) {
    parents.push_back(CreateMerkleNode(hashes[hashes.size() / 2]));
  }

  // Recursively build the Merkle tree for the parent nodes.
  return BuildMerkleTree(parents);
}

void PrintMerkleTree(MerkleNode* root) {
  if (root == NULL) {
    return;
  }

  cout << root->hash << endl;
  PrintMerkleTree(root->left);
  PrintMerkleTree(root->right);
}

int main() {
  vector<string> hashes = {"a", "b", "c", "d", "e"};

  MerkleNode* root = BuildMerkleTree(hashes);

  PrintMerkleTree(root);

  return 0;
}
