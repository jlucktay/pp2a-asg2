/*
 * Filename: unbal-binary-search-tree.c
 *
 * Student: James Lucktaylor
 *
 * Student ID#: 3015905
 *
 * File Description: This WordCollection implementation utilises an unbalanced
 *                   binary search tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "unbal-binary-search-tree.h"

/*---------------------------------------------------------------------------*/

int MakeCollection(WordCollection *wordList)
{
    wordList->root = NULL;
    wordList->size = 0;

    return SUCCESS;
}

/*---------------------------------------------------------------------------*/

void FreeCollection(WordCollection *wordList)
{
    PostOrderFree(wordList->root);
}

/*---------------------------------------------------------------------------*/

int AddCollection(WordCollection *wc, const char *c)
{
    BstNodePtr current = wc->root, previous = NULL, newNode;

    while (current != NULL)
    {
        previous = current;

        if (strcmp(current->word, c) > 0)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if ((newNode = malloc(sizeof(BstNode))) == NULL)
    {
        printf("Unable to allocate the required amount of memory.\n");

        return FAILURE;
    }

    newNode->right = NULL;
    newNode->left = NULL;

    if ((newNode->word = malloc(sizeof(char) * (strlen(c) + 1))) == NULL)
    {
        printf("Unable to allocate the required amount of memory.\n");

        return FAILURE;
    }

    strcpy(newNode->word, c);
    wc->size++;

    if (previous == NULL)
    {
        wc->root = newNode;

        return SUCCESS;
    }

    if (strcmp(previous->word, c) > 0)
    {
        previous->left = newNode;
    }
    else
    {
        previous->right = newNode;
    }

    return SUCCESS;
}

/*---------------------------------------------------------------------------*/

int SearchCollection(WordCollection *wc, const char *c)
{
    BstNodePtr current;
    current = wc->root;

    while (current != NULL)
    {
        if (strcmp(current->word, c) == 0)
        {
            return SUCCESS;
        }
        else if (strcmp(current->word, c) > 0)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
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
    DisplayBst(wc->root);
}

/*---------------------------------------------------------------------------*/

void PostOrderFree(BstNodePtr bstNode)
{
    if (bstNode)
    {
        PostOrderFree(bstNode->left);
        PostOrderFree(bstNode->right);
        free(bstNode->word);
        free(bstNode);
    }
}

/*---------------------------------------------------------------------------*/

void DisplayBst(BstNodePtr bstNode)
{
    if (bstNode)
    {
        DisplayBst(bstNode->left);
        printf("%s\n", bstNode->word);
        DisplayBst(bstNode->right);
    }
}
