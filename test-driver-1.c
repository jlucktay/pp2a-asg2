/*
 * a Simple, non-exhaustive, test driver for a WordCollection module
 *
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef WORDCOLL_HEADER
#error WORDCOLL_HEADER must be defined with the name of a suitable header file
#else
#include WORDCOLL_HEADER
#endif

int main(void)
{
   WordCollection names;

   const char *name[] = {"Peter", "Sathish", "Wade", "Don", "Indrajit",
                         "Rahul", "Sam", "Kevin", NULL};

   int i;

   printf("Current Implementation based on: %s\n", WORDCOLL_HEADER);

   if (MakeCollection(&names) == FAILURE)
   {
      fprintf(stderr, "Unable to initialise WordCollection\n");
      return EXIT_FAILURE;
   }

   i = 0;

   while (name[i])
   {
      if (AddCollection(&names, name[i]) == FAILURE)
      {
         fprintf(stderr, "AddCollection failed\n");
      }

      i++;
   }

   printf("Collection contains %d names\n", SizeCollection(&names));

   printf("The following names are in the Collection:\n");

   DisplayCollection(&names);

   printf("\nSearching for \"Sathish\": ");

   printf("%s\n", SearchCollection(&names, "Sathish") ? "FOUND" : "NOT FOUND");

   FreeCollection(&names);

   return EXIT_SUCCESS;
}
