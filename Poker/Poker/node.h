// node.cpp : Defines the node header for the console application.
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
#include "card_type.h"

typedef struct node
{
	card_type *data;
	node *next;

	node();
	node(card_type *data);
	node(const node& n);
	bool is_empty();
	bool is_equal_suit(card_suit suit);
	bool is_equal_rank(card_rank rank);
	bool is_equal_data(card_type *data);
	void display_node();
	std::string get_suit();
	std::string get_rank();
	~node();
};

