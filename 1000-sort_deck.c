#include "deck.h"

/**
 * find_len - find the length of a list
 * @list: pointer to a list
 *
 * Description: This function finds the length of a list
 * Return: int
 */
size_t find_len(deck_node_t *list)
{
	size_t list_len = 0;

	while (list)
	{
		list_len++;
		list = list->next;
	}
	return (list_len);
}

/**
 * _strcmp - compares two string
 * @str1: first string
 * @str2: second string
 *
 * Description: This function compares two strings using their
 * byte difference
 * Return: int
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * cvk - card value kind
 * @node: a particular card
 *
 * Description: This function checks the number corresponding to a particular
 * kind of card in a deck
 * Return: int
 */
int cvk(deck_node_t *node)
{
	char *value[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "Jack", "Queen", "King"};
	char *kind[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, kval  = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, value[i - 1]))
			kval = i;
	}
	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kind[node->card->kind], kind[i - 1]))
			kval = kval + (13 * i);
	}
	return (kval);
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: doubly linked list
 *
 * Description: This function that sorts a deck of cards
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *pst1, *pst2, *pst3, *pst4;

	if (deck == NULL || *deck == NULL || find_len(*deck) < 2)
		return;
	current = *deck;
	while (current)
	{
		if (current->prev && cvk(current) < cvk(current->prev))
		{
			pst1 = current->prev->prev;
			pst2 = current->prev;
			pst3 = current;
			pst4 = current->next;

			pst2->next = pst4;
			if (pst4)
				pst4->prev = pst2;
			pst3->next = pst2;
			pst3->prev = pst1;
			if (pst1)
				pst1->next = pst3;
			else
				*deck = pst3;
			pst2->prev = pst3;
			current = *deck;
			continue;
		}
		else
		{
			current = current->next;
		}
	}
}

