/*
 * Filename: ord-array-linear.c
 *
 * Student: James Lucktaylor
 *
 * Student ID#: 3015905
 *
 * File Description: This WordCollection implementation utilises an ordered
 *                   array, with a linear insertion/search method.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ord-array-linear.h"

/*---------------------------------------------------------------------------*/

int MakeCollection(WordCollection *wc)
{
   int i;

   for (i = 0; i < WCSIZE; i++)
   {
      wc->words[i] = NULL;
   }

   wc->size = 0;

   return SUCCESS;
}

/*---------------------------------------------------------------------------*/

void FreeCollection(WordCollection *wc)
{
   int i;

   for (i = 0; i < wc->size; i++)
   {
      free(wc->words[i]);
   }

   wc->size = 0;
}

/*---------------------------------------------------------------------------*/

int AddCollection(WordCollection *wc, const char *c)
{
   int i = wc->size;

   while (i > 0 && strcmp(wc->words[i - 1], c) > 0)
   {
      wc->words[i] = wc->words[i - 1];
      i--;
   }

   if ((wc->words[i] = malloc(sizeof(char) * (strlen(c) + 1))) == NULL)
   {
      printf("Unable to allocate the required amount of memory.\n");

      return FAILURE;
   }

   strcpy(wc->words[i], c);
   wc->size++;

   return SUCCESS;
}

/*---------------------------------------------------------------------------*/

int SearchCollection(WordCollection *wc, const char *c)
{
   int i;

   for (i = 0; i < wc->size; i++)
   {
      if (strcmp(wc->words[i], c) == 0)
      {
         return SUCCESS;
      }
      else if (strcmp(wc->words[i], c) > 0)
      {
         return FAILURE;
      }
   }

   return FAILURE;
}

/*---------------------------------------------------------------------------*/

int SizeCollection(WordCollection *wc)
{
   return wc->size;
}

/*---------------------------------------------------------------------------*/

void DisplayCollection(WordCollection *wc)
{
   int i;

   for (i = 0; i < wc->size; i++)
   {
      printf("Element #%d:\t%s\n", i, wc->words[i]);
   }
}
