/*
 * Filename: ord-linked-list.h
 *
 * Student: James Lucktaylor
 *
 * Student ID#: 3015905
 *
 * File Description: Ordered Linked List (WordCollection) of ListNode structs.
 *    Type:      ListNode, *ListNodePtr, WordCollection
 *    Constants: SUCCESS, FAILURE
 */

#define SUCCESS 1
#define FAILURE 0

typedef struct node
{
   char *word;
   struct node *next;
} ListNode;

typedef ListNode *ListNodePtr;

typedef struct
{
   ListNodePtr head, newNode, current, prev, next;
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
 * parameter.
 */
void FreeCollection(WordCollection *);

/*
 * AddCollection adds the string, given by the second parameter, to the
 * WordCollection given by the first parameter. It returns SUCCESS or FAILURE,
 * depending on the outcome of the dynamic allocation of memory. The string is
 * added so that the WordCollection is in alphabetical order at all times.
 */
int AddCollection(WordCollection *, const char *);

/*
 * SearchCollection searches for the string, given by the second parameter, in
 * the WordCollection given by the first parameter. This utilises a linear
 * search algorithm, and returns SUCCESS or FAILURE depending upon the outcome
 * of the search.
 */
int SearchCollection(WordCollection *, const char *);

/*
 * SizeCollection returns the number of words in the WordCollection given as
 * the parameter.
 */
int SizeCollection(WordCollection *);

/*
 * DisplayCollection prints the contents of the WordCollection given as the
 * parameter to standard output.
 */
void DisplayCollection(WordCollection *);
