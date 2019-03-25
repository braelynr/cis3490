/* Braelyn Rotman
   1006740
   March 24, 2019
   Assignment 4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst{
  int key;
  struct bst *left;
  struct bst *right;
}BST;

typedef struct nodestruct {
  char word[100];
  float prob;
  struct nodestruct *left;
  struct nodestruct *right;
} Node;

int cmpProb(const void *a, const void *b)
{
  Node *nodeA = (Node *)a;
  Node *nodeB = (Node *)b;

  if (nodeA->prob < nodeB->prob)
  {
    return 1;
  }
  else if (nodeA->prob > nodeB->prob)
  {
    return -1;
  }
  return 0;
}

Node *initializeNode(char *word, float prob)
{
    Node *temp = malloc(sizeof(Node));
    strcpy(temp->word, word);
    temp->prob = prob;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(Node **node, char *word, float prob)
{
  if (*node == NULL)
  {
    *node = initializeNode(word, prob);
  }

  else if (strcmp(word, (*node)->word) < 0)
  {
    insert(&(*node)->left, word, prob);
  }

  else if (strcmp(word, (*node)->word) > 0)
  {
    insert(&(*node)->right, word, prob);
  }

  return;
}

// function that finds an optimal binary search tree using the greedy technique
Node *greedyBST(Node *entries, int k)
{
  Node *tree;

  for (int i = 0; i < k; i++)
  {
    insert(&tree, entries[i].word, entries[i].prob);
  }

  return tree;
}

void searchTreeGreedy(Node *tree, char *key)
{
  if (tree == NULL)
  {
    printf("Not found.\n");
    return;
  }

  int cmp = strcmp(tree->word, key);

  if (cmp == 0)
  {
    printf("Compared with %s (%.4f), found.\n", tree->word, tree->prob);
  }
  else if (cmp > 0)
  {
    printf("Compared with %s (%.4f), go left subtree.\n", tree->word, tree->prob);
    searchTreeGreedy(tree->left, key);
  }
  else if (cmp < 0)
  {
    printf("Compared with %s (%.4f), go right subtree.\n", tree->word, tree->prob);
    searchTreeGreedy(tree->right, key);
  }
}
