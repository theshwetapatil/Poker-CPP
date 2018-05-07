// node.cpp : Defines the node struct for the console application.
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
#include "node.h"

node::node()
{
	data = new card_type();
	next = 0;
}

node::node(card_type *data)
{
	this->data = data;
	this->next = 0;
}

node::node(const node& n)
{
	data = new card_type();
	data = n.data;

	if (n.next == 0)
		next = 0;
	else
	{
		next = new node;
		*next = *n.next;

		node *iter = next;
		node *next_node = n.next->next;

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

bool node::is_empty()
{
	return ((this == 0) || data->is_empty());
}

bool node::is_equal_suit(card_suit suit)
{
	return (this->data->suit == suit);
}

bool node::is_equal_rank(card_rank rank)
{
	return (this->data->rank == rank);
}

bool node::is_equal_data(card_type *data)
{
	return (is_equal_suit(data->suit) && is_equal_rank(data->rank));
}

void node::display_node()
{
	data->display_card();
}

std::string node::get_suit()
{
	return data->get_suit();
}

std::string node::get_rank()
{
	return data->get_rank();
}

node::~node()
{
	data = 0;
	next = 0;
}
