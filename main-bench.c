/*
 * Filename: main-bench.c
 *
 * Student: James Lucktaylor
 *
 * Student ID#: 3015905
 *
 * File Description: This is a benchmark driver for the 4 different
 *                   WordCollection implementations.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

/*
 * WORD_COLL must be defined (as the implementation you wish to benchmark) by
 * the compiler with the -D parameter
 */

#ifndef WORD_COLL
#error WORD_COLL must be defined with the name of a suitable header file
#else
#include WORD_COLL
#endif

#define LINESIZE 1024

/* the 4 data files to be used in the benchmarking process */

#define DICTFILE "dictionary.txt"
#define INPUT1 "AliceWonderland.txt"
#define INPUT2 "RulingPassion.txt"
#define INPUT3 "DivineComedyDante.txt"

int bench(char*, WordCollection*);

/*---------------------------------------------------------------------------*/

int main(void)
{
   char line[LINESIZE], chompLine[LINESIZE];
   FILE *fp;
   hrtime_t startTime, stopTime, final;
   int i;
   WordCollection wordcol;

   printf("---=== WordCollection benchmark ===---\n\n");
   printf("Implementation: %s\n\n", WORD_COLL);

   if (MakeCollection(&wordcol) == FAILURE)
   {
      fprintf(stderr, "Unable to initialise WordCollection\n");
      return EXIT_FAILURE;
   }

   if ((fp = fopen(DICTFILE, "r")) == NULL)
   {
      fprintf(stderr, "Unable to open file: %s\n", DICTFILE);

      return EXIT_FAILURE;
   }

   printf("Reading %s (inserting):\n", DICTFILE);

   startTime = gethrtime(); /* code to be timed begins below here */

   while (fgets(line, LINESIZE, fp) != NULL)
   { /* the next 7 lines remove the newline from the end of the string being
      * inserted, and convert it to lower-case */
      strcpy(chompLine, "");
      strncat(chompLine, line, strlen(line) - 1);

      for (i = 0; i < strlen(chompLine); i++)
      {
         chompLine[i] = tolower(chompLine[i]);
      }

      if (AddCollection(&wordcol, chompLine) == FAILURE)
      {
         fprintf(stderr, "AddCollection failed\n");
      }
   }

   stopTime = gethrtime();  /* timing ends here */

   fclose(fp);
   final = stopTime - startTime;

   printf("%d inserts in %lld nanoseconds (%lf seconds)\n\n",
      SizeCollection(&wordcol), final, (double)final/1e9);

   printf("Reading Books (searching):\n\n");

   bench(INPUT1, &wordcol);
   bench(INPUT2, &wordcol);
   bench(INPUT3, &wordcol);

   FreeCollection(&wordcol);

   return EXIT_SUCCESS;
}

/*---------------------------------------------------------------------------*/

int bench(char *input, WordCollection *wc)
{
   char *strPtr, *delim = { " \t\n!@#$%^*()_+-={}[]|;:',/<>?`~\"." };
   char line[LINESIZE], chompLine[LINESIZE];
   FILE *fp;
   hrtime_t startTime, stopTime, final;
   int i, found = 0, notFound = 0, wordTotal = 0, lineTotal = 0;

   printf("book: %s\n", input);

   if ((fp = fopen(input, "r")) == NULL)
   {
      fprintf(stderr, "Unable to open file: %s\n", DICTFILE);

      return FAILURE;
   }

   startTime = gethrtime(); /* code to be timed begins below here */

   while (fgets(line, LINESIZE, fp) != NULL)
   { /* the next 7 lines remove the newline from the end of the string being
      * inserted, and convert it to lower-case */
      strcpy(chompLine, "");
      strncat(chompLine, line, strlen(line) - 2);

      for (i = 0; i < strlen(chompLine); i++)
      {
         chompLine[i] = tolower(chompLine[i]);
      }
      /* the lower-case, chomped string is now tokenised, based on the
       * delimiters in the 'delim' string, defined above */
      strPtr = strtok(chompLine, delim);

      while (strPtr != NULL)
      {
         if (SearchCollection(wc, strPtr) == SUCCESS)
         {
            found++;
         }
         else
         {
            notFound++;
         }

         wordTotal++;
         strPtr = strtok(NULL, delim); /* the next token is fetched... */
      }

      lineTotal++;
   }

   stopTime = gethrtime();  /* timing ends here */

   fclose(fp);
   final = stopTime - startTime;

   printf("%d words found on %d lines, %d words not found (total %d)\n",
      found, lineTotal, notFound, wordTotal);
   printf("%d searches in %lld nanoseconds (%lf seconds)\n\n", wordTotal,
      final, (double)final/1e9);

   return SUCCESS;
}
