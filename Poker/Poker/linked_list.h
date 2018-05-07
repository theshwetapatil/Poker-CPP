// linked_list.cpp : Defines the linked_list header for the console application.
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
#include "node.h"

typedef struct linked_list
{
	private:
		node *head;

	public:
		linked_list();
		linked_list(node *head);
		linked_list(const linked_list& ll);
		bool is_empty();
		void add_first_node(card_suit suit, card_rank rank);
		void add_first_node(node *n);
		void add_node(card_suit suit, card_rank rank);
		void add_node(node *n);
		void delete_first_node();
		void delete_node(card_suit suit, card_rank rank);
		void delete_node(node *n);
		bool search_node(card_suit suit, card_rank rank);
		int get_position(card_suit suit, card_rank rank);
		int get_position(node *n);
		node* get_node_at(int position);
		int get_count();
		void swap(node* a, node* b);
		void reverse_ll();
		node* partition(node *head, node *tail, node **first, node **last, sort_flag flag);
		node* quicksort(node *head, node *tail, sort_flag flag);
		void sort_ll(sort_flag flag);
		void shuffle_ll();
		void display_ll();
		~linked_list();
}DECK;