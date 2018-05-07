// linked_list.cpp : Defines the linked_list struct for the console application.
// C++ Game: Poker
// Gameplay features: hand draw, poker hand match, card shuffle- Fisher Yates Algorithm, sort- Quicksort Algorithm, cards swap
// Author: Shweta Patil
// Copyright: Shweta Patil © 2018
#pragma once
#define _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC_NEW
#include <cstdlib>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ ,__LINE__)
#define new DBG_NEW
#endif
#endif
#include "stdafx.h"
#include "linked_list.h"

linked_list::linked_list()
{
	head = 0;
}

linked_list::linked_list(node *head)
{
	this->head = head;
}

linked_list::linked_list(const linked_list& ll)
{
	if (ll.head == 0)
		head = 0;
	else
	{
		head = new node;
		*head = *ll.head;

		node *iter = head;
		node *next_node = ll.head->next;

		while (next_node)
		{
			iter->next = new node;
			iter = iter->next;
			*iter = *next_node;
			next_node = next_node->next;
		}
		iter->next = 0;
	}
}

bool linked_list::is_empty()
{
	return ((this == 0) || head->is_empty());
}

void linked_list::add_first_node(card_suit suit, card_rank rank)
{
	card_type *card = new card_type(suit, rank);
	node *new_node = new node(card);
	new_node->next = head;
	head = new_node;
}

void linked_list::add_first_node(node *n)
{
	node *new_node = n;
	new_node->next = head;
	head = new_node;
}

void linked_list::add_node(card_suit suit, card_rank rank)
{
	if (head == 0)
		add_first_node(suit, rank);
	else
	{
		card_type *card = new card_type(suit, rank);
		node *new_node = new node(card);

		node *iter = head;
		while (iter->next)
		{
			iter = iter->next;
		}

		iter->next = new_node;
	}
}

void linked_list::add_node(node *n)
{
	if (head == 0)
		add_first_node(n);
	else
	{
		node *new_node = n;
		new_node->next = 0;

		node *iter = head;
		while (iter->next)
		{
			iter = iter->next;
		}
		iter->next = new_node;
	}
}

void linked_list::delete_first_node()
{
	node *next_node = head->next;
	head = next_node;
	//delete next_node;
}

void linked_list::delete_node(card_suit suit, card_rank rank)
{
	card_type *card = new card_type(suit, rank);

	if (head == 0)
		return;

	if (head->is_equal_data(card))
		delete_first_node();
	else
	{
		node *iter = head;
		node *prev = iter;
		while (iter)
		{
			if (iter->is_equal_data(card))
				break;
			prev = iter;
			iter = iter->next;
		}
		node *next_node = iter->next;
		prev->next = next_node;
		//delete next_node;
	}
}

void linked_list::delete_node(node *n)
{
	if (head == 0)
		return;

	if (head == n)
		delete_first_node();
	else
	{
		node *iter = head;
		node *prev = iter;
		while (iter)
		{
			if (iter == n)
				break;
			prev = iter;
			iter = iter->next;
		}
		node *next_node = iter->next;
		prev->next = next_node;
		//delete next_node;
	}
}

bool linked_list::search_node(card_suit suit, card_rank rank)
{
	node *iter = head;
	card_type *card = new card_type(suit, rank);
	while (iter)
	{
		if (iter->is_equal_data(card))
			return true;
		iter = iter->next;
	}
	return false;
}

int linked_list::get_position(card_suit suit, card_rank rank)
{
	int pos = 0;
	node *iter = head;
	card_type *card = new card_type(suit, rank);
	while (iter)
	{
		if (iter->is_equal_data(card))
			return pos;
		iter = iter->next;
		pos++;
	}
	return -1;
}

int linked_list::get_position(node *n)
{
	node *iter = head;
	int pos = 0;
	while (iter)
	{
		if (iter == n)
			return pos;
		iter = iter->next;
		pos++;
	}
	return -1;
}

node* linked_list::get_node_at(int position)
{
	int pos = position;
	node *iter = head;
	while (iter)
	{
		if (pos == 0)
			break;
		iter = iter->next;
		pos--;
	}
	return iter;
}

int linked_list::get_count()
{
	int count = 1;
	if (head == 0)
		return 0;
	node *iter = head;
	while (iter->next)
	{
		count++;
		iter = iter->next;
	}
	return count;
}

void linked_list::swap(node* a, node* b)
{
	card_type *card = a->data;
	a->data = b->data;
	b->data = card;
}

void linked_list::reverse_ll()
{
	node *next_node = 0;
	node *iter = head;
	head = 0;
	while (iter)
	{
		next_node = iter->next;
		iter->next = head;
		head = iter;
		iter = next_node;
	}
}

node* linked_list::partition(node *head, node *tail, node **first, node **last, sort_flag flag)
{
	node *pivot = tail;
	node *prev = 0, *iter = head, *new_tail = pivot;

	while (iter != pivot)
	{
		bool sort_condition;

		if (flag == suit_sort)
			sort_condition = (iter->data->suit < pivot->data->suit);
		else
		if (flag == rank_sort)
			sort_condition = (iter->data->rank < pivot->data->rank);
		else
			sort_condition = (iter->data->suit < pivot->data->suit)
			|| ((iter->data->suit == pivot->data->suit)
				&& (iter->data->rank < pivot->data->rank));

		if (sort_condition)
		{
			if ((*first) == NULL)
				(*first) = iter;

			prev = iter;
			iter = iter->next;
		}
		else
		{
			if (prev)
				prev->next = iter->next;
			node *new_node = iter->next;
			iter->next = 0;
			new_tail->next = iter;
			new_tail = iter;
			iter = new_node;
		}
	}

	if ((*first) == NULL)
		(*first) = pivot;

	(*last) = new_tail;

	return pivot;
}

node* linked_list::quicksort(node *head, node *tail, sort_flag flag)
{
	if (head == 0 || head == tail)
		return head;

	node *first = 0;
	node *last = 0;

	node *pivot = partition(head, tail, &first, &last, flag);

	if (first != pivot)
	{
		node *iter = first;
		while (iter->next != pivot)
			iter = iter->next;
		iter->next = 0;

		first = quicksort(first, iter, flag);

		node *new_tail = first;
		while (new_tail->next != 0)
		{
			new_tail = new_tail->next;
		}

		iter = new_tail;
		iter->next = pivot;
	}

	pivot->next = quicksort(pivot->next, last, flag);

	return first;
}

void linked_list::sort_ll(sort_flag flag)
{
	//Quicksort Algorithm
	node *tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	head = quicksort(head, tail, flag);
}

void linked_list::shuffle_ll()
{
	//Fisher-Yates Algorithm- Modern
	node *iter = head;
	node *tail = head;
	int count = 0;
	while (tail->next)
	{
		tail = tail->next;
		count++;
	}
	while (iter->next->next)
	{
		int iter_pos = get_position(iter);
		int rand_pos = 0 + rand() % (count - iter_pos + 1);
		swap(get_node_at(iter_pos), get_node_at(rand_pos));
		iter = iter->next;
	}
}

void linked_list::display_ll()
{
	node *iter = head;
	while (iter)
	{
		iter->display_node();
		iter = iter->next;
	}
}

linked_list::~linked_list()
{
	if (head == 0 || head->data == 0)
		return;

	node *iter = head;
	while (iter)
	{
		node *temp = iter;
		iter = iter->next;
		delete temp;
	}
	head = 0;
}
