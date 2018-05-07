// card_type.cpp : Defines the card_type struct for the console application.
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
#include "card_type.h"

card_type::card_type()
{
	suit = null;
	rank = zero;
}

card_type::card_type(card_suit suit, card_rank rank)
{
	this->suit = suit;
	this->rank = rank;
}

card_type::card_type(const card_type& ct)
{
	suit = ct.suit;
	rank = ct.rank;
}

bool card_type::is_empty()
{
	return (this == 0 || (this->suit == null && this->rank == zero));
}

std::string card_type::get_suit()
{
	switch (suit)
	{
	case clubs:		return "clubs";
		break;
	case diamonds:	return "diamonds";
		break;
	case hearts:	return "hearts";
		break;
	case spades:	return "spades";
		break;
	default:		return "none";
		break;
	}
}

std::string card_type::get_rank()
{
	switch (rank)
	{
	case ace:	return "ace";
		break;
	case two:	return "two";
		break;
	case three: return "three";
		break;
	case four:	return "four";
		break;
	case five:	return "five";
		break;
	case six:	return "six";
		break;
	case seven: return "seven";
		break;
	case eight: return "eight";
		break;
	case nine:	return "nine";
		break;
	case ten:	return "ten";
		break;
	case jack:	return "jack";
		break;
	case queen: return "queen";
		break;
	case king:	return "king";
		break;
	default:	return "none";
		break;
	}
}

void card_type::display_card()
{
	std::cout << "suit::" << get_suit() << "::::rank::" << get_rank() << std::endl;
}

card_type::~card_type()
{
	suit = null;
	rank = zero;
}