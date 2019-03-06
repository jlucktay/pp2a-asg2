/*
 * Filename: unbal-binary-search-tree.c
 *
 * Student: James Lucktaylor
 *
 * Student ID#: 3015905
 *
 * File Description: Unbalanced Binary Search Tree (WordCollection) of BstNode
 *                   structs.
 *    Type:      BstNode, *BstNodePtr, WordCollection
 *    Constants: SUCCESS, FAILURE
 */

#define SUCCESS 1
#define FAILURE 0

typedef struct node
{
   char *word;
   struct node *right;
   struct node *left;
} BstNode;

typedef BstNode *BstNodePtr;

typedef struct
{
   BstNodePtr root;
   unsigned size;
} WordCollection;

/*
 * MakeCollection initialises the WordCollection whose pointer it is given as
 * a parameter, with one initial NULL entry. It returns SUCCESS upon
 * successful completion.
 */
int MakeCollection(WordCollection *);

/*
 * FreeCollection frees the memory dynamically allocated to the WordCollection
 * parameter, utilising the recursive function PostOrderFree.
 */
void FreeCollection(WordCollection *);

/*
 * AddCollection adds the string, given by the second parameter, to the
 * WordCollection given by the first parameter. It returns SUCCESS or FAILURE,
 * depending on the outcome of the dynamic allocation of memory.
 */
int AddCollection(WordCollection *, const char *);

/*
 * SearchCollection searches for the string, given by the second parameter, in
 * the WordCollection given by the first parameter. This utilises a binary
 * search algorithm (which is what the structure of this implementation is
 * based around), and returns SUCCESS or FAILURE depending upon the outcome of
 * the search.
 */
int SearchCollection(WordCollection *, const char *);

/*
 * SizeCollection returns the number of words in the WordCollection given as
 * the parameter.
 */
int SizeCollection(WordCollection *);

/*
 * DisplayCollection prints the contents of the WordCollection given as the
 * parameter to standard output, utilising the recursive function DisplayBst.
 */
void DisplayCollection(WordCollection *);

/*
 * PostOrderFree is a recursive function that frees the memory dynamically
 * allocated to the nodes in the unbalanced binary search tree.
 */
void PostOrderFree(BstNodePtr);

/*
 * DisplayBst is a recursive function that prints the words in the unbalanced
 * binary search tree to standard output.
 */
void DisplayBst(BstNodePtr);
