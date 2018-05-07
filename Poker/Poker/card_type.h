// card_type.cpp : Defines the card_type header for the console application.
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
#include <iostream>
#include <string>

#define DECKSIZE 52

enum card_suit { null = 0, clubs = 1, diamonds = 2, hearts = 3, spades = 4 };
enum card_rank {
	zero = 0, ace = 1, two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7,
	eight = 8, nine = 9, ten = 10, jack = 11, queen = 12, king = 13
};
enum hand_card { a, b, c, d, e };
enum poker_hand {
	one_pair = 1, two_pair = 2, three_of_a_kind = 3, straight = 4,
	flush = 6, full_house = 9, four_of_a_kind = 25, straight_flush = 50,
	royal_flush = 800, none = 0
};
enum sort_flag { q_sort, suit_sort, rank_sort };

struct card_type
{
	card_suit suit;
	card_rank rank;

	card_type();
	card_type(card_suit suit, card_rank rank);
	card_type(const card_type& ct);
	bool is_empty();
	std::string get_suit();
	std::string get_rank();
	void display_card();
	~card_type();
};

