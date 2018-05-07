// Poker.cpp : Defines the entry point for the console application.
// C++ Game: Poker
// Gameplay features: hand draw, poker hand match, card shuffle- Fisher Yates Algorithm, sort- Quicksort Algorithm, cards swap
// Author: Shweta Patil
// Copyright: Shweta Patil � 2018
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
#include "card_game.h"
#include<cstdlib>
#include<ctime>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned)time(NULL));
	
	POKER game;

	system("pause");
	return 0;
}

