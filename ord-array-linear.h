/*
 * Filename: ord-array-linear.h
 *
 * Student: James Lucktaylor
 *
 * Student ID#: 3015905
 *
 * File Description: Ordered Linear Array inside a WordCollection struct.
 *    Type:      WordCollection
 *    Constants: SUCCESS, FAILURE, WCSIZE
 */

#define SUCCESS 1
#define FAILURE 0
#define WCSIZE 250000

typedef struct
{
   char *words[WCSIZE];
   unsigned size;
} WordCollection;

/*
 * MakeCollection initialises the WordCollection whose pointer it is given as
 * a parameter, up to a size defined by WCSIZE, with NULL entries. It returns
 * SUCCESS upon successful completion.
 */
int MakeCollection(WordCollection*);

/*
 * FreeCollection frees the memory dynamically allocated to the WordCollection
 * parameter.
 */
void FreeCollection(WordCollection*);

/*
 * AddCollection adds the string, given by the second parameter, to the
 * WordCollection given by the first parameter. It returns SUCCESS or FAILURE,
 * depending on whether or not there is space for the string in the
 * WordCollection, and also on the outcome of the dynamic allocation of
 * memory. The string is added so that the WordCollection is in alphabetical
 * order.
 */
int AddCollection(WordCollection*, const char*);

/*
 * SearchCollection searches for the string, given by the second parameter, in
 * the WordCollection given by the first parameter. This utilises a linear
 * search algorithm, and returns SUCCESS or FAILURE depending upon the outcome
 * of the search.
 */
int SearchCollection(WordCollection*, const char*);

/*
 * SizeCollection returns the number of words in the WordCollection given as
 * the parameter.
 */
int SizeCollection(WordCollection*);

/*
 * DisplayCollection prints the contents of the WordCollection given as the
 * parameter to standard output.
 */
void DisplayCollection(WordCollection*);
