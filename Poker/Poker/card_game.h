// card_game.cpp : Defines the card_game header for the console application.
// C++ Game: Poker
// Gameplay features: hand draw, poker hand match, card shuffle- Fisher Yates Algorithm, sort- Quicksort Algorithm, cards swap
// Author: Shweta Patil
// Copyright: Shweta Patil © 2018
#pragma once
#include "linked_list.h"

typedef struct card_game
{
	private:
		DECK deck;
		DECK hand;
		int money = 10;
		int card_count = DECKSIZE;
		int round = 1;
		bool play_again = true;
		bool swap_again = false;
		bool swap_flag = false;
		bool play_flag = false;
		poker_hand p_hand;

	public:
		card_game();
		void create_deck();
		void create_hand();
		void update_hand();
		bool is_valid(std::string str);
		bool is_valid(char ch);
		bool is_valid(int num);
		bool check_valid(char ch);
		bool check_valid(int num);
		void print_hand();
		void get_player_hand();
		void display_game_round();
		void get_response();
		void display_hand();
		void display_deck();
		card_suit get_suit_type(char ch);
		card_rank get_rank_type(int num);
		void get_player_swap();
		void swap_deck_hand(card_suit &hand_suit_type, card_rank &hand_rank_type,
							card_suit &deck_suit_type, card_rank &deck_rank_type);
		void swap_cards();
		void replace_card(hand_card card);
		int get_amount();
		std::string get_poker_hand();
		int count_equal_rank();
		bool is_match_value_equal();
		bool is_one_pair();
		bool is_two_pair();
		bool is_three_of_a_kind();
		bool is_four_of_a_kind();
		bool is_full_house();
		bool is_staright();
		bool is_flush();
		bool is_straight_flush();
		bool is_royal_flush();
		bool is_poker_hand();
		poker_hand get_win_conditon();
		void display_win_message();
		void display_lose_message();
		void check_poker_hand();
		bool is_game_over();
		void play_game();
		void game_reset();
		void default_mode();
		~card_game();
}POKER;
