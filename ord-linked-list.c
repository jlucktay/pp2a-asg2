/*
 * Filename: ord-linked-list.c
 *
 * Student: James Lucktaylor
 *
 * Student ID#: 3015905
 *
 * File Description: This WordCollection implementation utilises an ordered
 *                   linked list, with a linear insertion/search method.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ord-linked-list.h"

/*---------------------------------------------------------------------------*/

int MakeCollection(WordCollection *wc)
{
   wc->head = NULL;
   wc->size = 0;

   return SUCCESS;
}

/*---------------------------------------------------------------------------*/

void FreeCollection(WordCollection *wc)
{
   wc->current = wc->head;

   while (wc->current != NULL)
   {
      wc->next = wc->current->next;
      free(wc->current->word);
      free(wc->current);
      wc->current = wc->next;
   }
}

/*---------------------------------------------------------------------------*/

int AddCollection(WordCollection *wc, const char *c)
{
   if ((wc->newNode = malloc(sizeof(ListNode))) == NULL)
   {
      printf("Unable to allocate the required amount of memory.\n");

      return FAILURE;
   }

   wc->current = wc->head;
   wc->prev = NULL;

   while ((wc->current != NULL) && (strcmp(wc->current->word, c) < 0))
   {
      wc->prev = wc->current;
      wc->current = wc->current->next;
   }

   wc->newNode->word = malloc(sizeof(char) * (strlen(c) + 1));

   if (!wc->newNode->word)
   {
      printf("Unable to allocate the required amount of memory.\n");

      return FAILURE;
   }

   strcpy(wc->newNode->word, c);
   wc->newNode->next = wc->current;
   wc->size++;

   if (wc->prev == NULL)
   {
      wc->head = wc->newNode;
   }
   else
   {
      wc->prev->next = wc->newNode;
   }

   return SUCCESS;
}

/*---------------------------------------------------------------------------*/

int SearchCollection(WordCollection *wc, const char *c)
{
   wc->current = wc->head;

   while (wc->current != NULL)
   {
      if (strcmp(wc->current->word, c) == 0)
      {
         return SUCCESS;
      }
      else if (strcmp(wc->current->word, c) > 0)
      {
         return FAILURE;
      }
      else
      {
         wc->current = wc->current->next;
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
   unsigned i = 0;

   wc->current = wc->head;

   while (wc->current != NULL)
   {
      printf("Element #%d:\t%s\n", i++, wc->current->word);
      wc->current = wc->current->next;
   }
}
