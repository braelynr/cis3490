/* Braelyn Rotman
   1006740
   March 21, 2019
   Assignment 4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodestruct {
    char word[100];
    float prob;
    struct nodestruct *left;
    struct nodestruct *right;
} Node;

void searchTree(char *unique[], float P[], int n);
Node *greedyBST(Node *entries, int k);
void searchTreeGreedy(Node *tree, char *needle);
void printNode(Node *node);
Node *initializeNode(char *word, float prob);
int cmpProb(const void *a, const void *b);

static int compare(const void* a, const void* b) // for qsort
{
    return strcmp(*(char**)a, *(char**)b);
}

int main(void) // use arguments to choose program i think and enter string
{
    FILE *fp;
    char *words[2045]; // set of words from file
    char *text; // string of entire file
    int i = 0, j = 0, k = 0; // indexing
    int size = 0; // size malloced for text
    char *key = calloc(50, sizeof(char));
    Node *tree;

    Node entries[600]; // combined word + probability structure for tree
    char *unique[601]; // array of unique words
    float probs[601]; // array of probabilities

    for(i = 0 ; i < 2045 ; i++)
    {
        words[i] = calloc(25, sizeof(char)); // allocate space for words
    }

    fp = fopen("data_7.txt", "r");
    if(fp == NULL)
    {
        printf("Failed to open file \"data_7.txt\"\n");
        return -1;
    }

    i = 0;
    size = 1000;
    text = calloc(1000, sizeof(char));
    while((text[i] = fgetc(fp)) != EOF) // read file into one string
    {
        i++;
        if(i == size) // need more memory
        {
            size = size + 1000;
            text = realloc(text, sizeof(char)*size);
            for(int j = size - 1000 ; j < size ; j++) // initialize
            {
                text[j] = '\0';
            }
        }
    }
    fclose(fp);

    // split into array of words
    for(i = 0 ; i < strlen(text) ; i++)
    {
        if(text[i] == ' ' || text[i] == '\n') // ignore whitespace
        {
            while(text[i] == ' ' || text[i] == '\n')
            {
                i++;
            }
            j++; // next word
            k = 0;
        }
        if(text[i] >= 0 && text[i] <= 127) // check for valid characters
        {
            words[j][k] = text[i];
            k++;
        }
    }
    free(text);

    qsort(words, 2045, sizeof(char *), compare); // sort array of words

    j = 0;
    k = 1;
    for(i = 0 ; i < 2045 ; i++) // for each word in array
    {
        unique[k] = words[i]; // copy into unique array
        probs[k] = 1; // 1 for first instance
        j = i + 1;
        if(i < 2044)
        {
            while(strcmp(words[i], words[j]) == 0) // while the next word is the same
            {
                probs[k] = probs[k] + 1; // increase instances
                j++; // check next word
            }
            i = j - 1; // skip already checked words
            //printf("%s\t%d\n", unique[k], probs[k]);
            k++; // next unique word
        }
    }
    //  printf("K = %d\n", k); // number of unique words

    // adjust probabilities
    for(i = 1 ; i <= k ; i++)
    {
        probs[i] = probs[i]/2045;
    }

    searchTree(unique, probs, k);

    for (int i = 0; i < k; i++) {
        entries[i].prob = probs[i + 1];
	      strcpy(entries[i].word, unique[i + 1]);
    }

    qsort(entries, k, sizeof(Node), cmpProb);

    tree = greedyBST(entries, k);
    printf("\n(Q2) Enter a key: ");
    scanf("%s", key);
    searchTreeGreedy(tree, key);
    free(key);

    // free array of words from file
    for(i = 0 ; i < 2045 ; i++)
    {
        free(words[i]);
    }

    return 0;
}
