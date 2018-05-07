// card_game.cpp : Defines the card_game struct for the console application.
// C++ Game: Poker
// Gameplay features: hand draw, poker hand match, card shuffle- Fisher Yates Algorithm, sort- Quicksort Algorithm, cards swap
// Author: Shweta Patil
// Copyright: Shweta Patil © 2018
#include "stdafx.h"
#include "card_game.h"

card_game::card_game()
{
	default_mode();
}

void card_game::create_deck()
{
	deck = 0;
	card_suit iter_suit = clubs;
	card_rank iter_rank = ace;
	int counter = 0;

	while (counter < DECKSIZE)
	{
		while (iter_suit <= spades)
		{
			while (iter_rank <= king)
			{
				deck.add_node(iter_suit, iter_rank);
				counter++;
				iter_rank = (card_rank)(iter_rank + 1);
			}
			iter_suit = (card_suit)(iter_suit + 1);
			iter_rank = ace;
		}
	}
}

void card_game::create_hand()
{
	hand = 0;
	deck.shuffle_ll();
	int count = 5;
	while (count != 0)
	{
		if (card_count < count)
			create_deck();
		int rand_pos = 0 + rand() % (card_count - 1 + 1);
		node *new_card = deck.get_node_at(rand_pos);
		deck.delete_node(new_card);
		hand.add_node(new_card);
		count--;
		card_count--;
	}
}

void card_game::update_hand()
{
	create_hand();
	display_hand();
}

bool card_game::is_valid(std::string str)
{
	bool flag = true;
	for (auto ch : str)
	{
		if (!((tolower(ch) >= 'a') && (tolower(ch) <= 'e')))
		{
			flag = false;
			break;
		}
	}
		
	return flag;
}

bool card_game::is_valid(char ch)
{
	return (tolower(ch) == 'y' || tolower(ch) == 'n');
}

bool card_game::is_valid(int num)
{
	return ((num > 0) && (num < 5));
}

bool card_game::check_valid(char ch)
{
	return ((tolower(ch) >= 'a') && (tolower(ch) <= 'e'));
}

bool card_game::check_valid(int num)
{
	return ((num > 0) && (num < 14));
}

void card_game::print_hand()
{
	char ch;
	int pos;
	for (ch = 'A', pos = 0; ch < 'F', pos < 5; ch++, pos++)
	{
		std::cout << ch << "::";
		(hand.get_node_at(pos))->display_node();
	}
}

void card_game::get_player_hand()
{
	std::string str = "";
	std::cout << "\nEnter card/s to keep::";
	while (!(std::cin >> str) || !is_valid(str))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!is_valid(str))
			std::cout << "Error::Please select from the given options: A, B, C, D, E..." << std::endl;
		else
			std::cout << "Error::Please select from the given options without space in-between value..." << std::endl;
		std::cout << std::endl;
		std::cout << "Enter card/s to keep::";
	}

	std::string str_discard = "abcde";
	for (auto ch : str)
	{
		int pos = str_discard.find(tolower(ch));
		str_discard.erase(str_discard.begin() + pos);
	}

	for (auto ch : str_discard)
	{
		switch (ch)
		{
			case 'a':replace_card(a);
				break;
			case 'b':replace_card(b);
				break;
			case 'c':replace_card(c);
				break;
			case 'd':replace_card(d);
				break;
			case 'e':replace_card(e);
				break;
		}
	}
}

void card_game::display_game_round()
{
	std::cout << std::endl;
	std::cout << "Round::" << round << std::endl;
	std::cout << "You have $" << money << std::endl;
	std::cout << std::endl;
	std::cout << "1::Deck" << std::endl;
	std::cout << "2::Swap" << std::endl;
	std::cout << "3::Play" << std::endl;
	std::cout << "4::Exit" << std::endl;
}

void card_game::get_response()
{
	int option = 1;
	std::cout << "\nSelect option::";
	while (!(std::cin >> option) || !is_valid(option))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!is_valid(option))
			std::cout << "Error::Please select from the given options: 1, 2, 3, 4..." << std::endl;
		else
			std::cout << "Error::Please enter an integer value..." << std::endl;
		std::cout << std::endl;
		std::cout << "Select option::";
	}
	std::cout << std::endl;
	switch (option)
	{
		case 1:	display_deck();
			break;
		case 2: swap_cards();
			break;
		case 3: play_game();
			break;
		case 4:	play_again = false;
			break;
	}
}

void card_game::display_hand()
{
	std::cout << std::endl;
	if (swap_flag)
		std::cout << "Your updated hand after swap:" << std::endl;
	else
	if (play_flag)
		std::cout << "Your updated hand after keep:" << std::endl;
	else
		std::cout << "Your hand:" << std::endl;

	print_hand();
}

void card_game::display_deck()
{
	deck.sort_ll(q_sort);
	std::cout << "Deck at the moment::" << std::endl;
	deck.display_ll();
	std::cout << "Cards left::" << card_count << std::endl;
}

card_suit card_game::get_suit_type(char ch)
{
	switch (tolower(ch))
	{
		case 'a':	return clubs;
			break;
		case 'b':	return diamonds;
			break;
		case 'c':	return hearts;
			break;
		case 'd':	return spades;
			break;
	}
}

card_rank card_game::get_rank_type(int num)
{
	switch (num)
	{
		case 1: return ace;
			break;
		case 2: return two;
			break;
		case 3: return three;
			break;
		case 4: return four;
			break;
		case 5: return five;
			break;
		case 6: return six;
			break;
		case 7: return seven;
			break;
		case 8: return eight;
			break;
		case 9: return nine;
			break;
		case 10: return ten;
			break;
		case 11: return jack;
			break;
		case 12: return queen;
			break;
		case 13: return king;
			break;
	}
}

void card_game::get_player_swap()
{
	//Get card to be replaced from hand
	char hand_suit;
	int hand_rank;
	card_suit hand_suit_type;
	card_rank hand_rank_type;
	do
	{
		std::cout << "\nEnter card to be replaced from the given hand::" << std::endl;
		std::cout << "\nSelect suit::" << std::endl;
		std::cout << "A::clubs" << std::endl;
		std::cout << "B::diamonds" << std::endl;
		std::cout << "C::hearts" << std::endl;
		std::cout << "D::spades" << std::endl;
		std::cout << "\nEnter suit::";

		while (!(std::cin >> hand_suit) || !check_valid(hand_suit))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (!check_valid(hand_suit))
				std::cout << "Error::Please select from the given options: A, B, C, D..." << std::endl;
			else
				std::cout << "Error::Please select from the given options without space in-between value..." << std::endl;
			std::cout << std::endl;
			std::cout << "Enter suit::";
		}

		std::cout << "\nSelect rank::" << std::endl;
		std::cout << "1::ace" << std::endl;
		std::cout << "2::two" << std::endl;
		std::cout << "3::three" << std::endl;
		std::cout << "4::four" << std::endl;
		std::cout << "5::five" << std::endl;
		std::cout << "6::six" << std::endl;
		std::cout << "7::seven" << std::endl;
		std::cout << "8::eight" << std::endl;
		std::cout << "9::nine" << std::endl;
		std::cout << "10::ten" << std::endl;
		std::cout << "11::jack" << std::endl;
		std::cout << "12::queen" << std::endl;
		std::cout << "13::king" << std::endl;
		std::cout << "\nEnter rank::";

		while (!(std::cin >> hand_rank) || !check_valid(hand_rank))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (!check_valid(hand_rank))
				std::cout << "Error::Please select from the given options: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13..." << std::endl;
			else
				std::cout << "Error::Please select from the given options without space in-between value..." << std::endl;
			std::cout << std::endl;
			std::cout << "Enter rank::";
		}

		hand_suit_type = get_suit_type(hand_suit);
		hand_rank_type = get_rank_type(hand_rank);
		if (!hand.search_node(hand_suit_type, hand_rank_type))
		{
			std::cout << "Invalid card in the given hand. Please select card(suit and rank) from the given hand..." << std::endl;
			std::cout << std::endl;
			display_hand();
		}
		std::cout << std::endl;
	} while (!hand.search_node(hand_suit_type, hand_rank_type));

	//Get card to be swapped with from deck
	char deck_suit;
	int deck_rank;
	card_suit deck_suit_type;
	card_rank deck_rank_type;
	do
	{
		std::cout << "Enter card to be swapped with from deck::" << std::endl;
		std::cout << "\nSelect suit::" << std::endl;
		std::cout << "A::clubs" << std::endl;
		std::cout << "B::diamonds" << std::endl;
		std::cout << "C::hearts" << std::endl;
		std::cout << "D::spades" << std::endl;
		std::cout << "\nEnter suit::";

		while (!(std::cin >> deck_suit) || !check_valid(deck_suit))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (!check_valid(deck_suit))
				std::cout << "Error::Please select from the given options: A, B, C, D..." << std::endl;
			else
				std::cout << "Error::Please select from the given options without space in-between value..." << std::endl;
			std::cout << std::endl;
			std::cout << "Enter suit::";
		}

		std::cout << "\nSelect rank::" << std::endl;
		std::cout << "1::ace" << std::endl;
		std::cout << "2::two" << std::endl;
		std::cout << "3::three" << std::endl;
		std::cout << "4::four" << std::endl;
		std::cout << "5::five" << std::endl;
		std::cout << "6::six" << std::endl;
		std::cout << "7::seven" << std::endl;
		std::cout << "8::eight" << std::endl;
		std::cout << "9::nine" << std::endl;
		std::cout << "10::ten" << std::endl;
		std::cout << "11::jack" << std::endl;
		std::cout << "12::queen" << std::endl;
		std::cout << "13::king" << std::endl;
		std::cout << "\nEnter rank::";

		while (!(std::cin >> deck_rank) || !check_valid(deck_rank))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (!check_valid(deck_rank))
				std::cout << "Error::Please select from the given options: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13..." << std::endl;
			else
				std::cout << "Error::Please select from the given options without space in-between value..." << std::endl;
			std::cout << std::endl;
			std::cout << "Enter suit::";
		}

		deck_suit_type = get_suit_type(deck_suit);
		deck_rank_type = get_rank_type(deck_rank);
		if (!deck.search_node(deck_suit_type, deck_rank_type))
		{
			std::cout << "Invalid card in the given deck. Please select card(suit and rank) from the given deck..." << std::endl;
			std::cout << std::endl;
			display_deck();
			std::cout << std::endl;
		}
		std::cout << std::endl;
	} while (!deck.search_node(deck_suit_type, deck_rank_type));

	swap_deck_hand(hand_suit_type, hand_rank_type, deck_suit_type, deck_rank_type);
}

void card_game::swap_deck_hand(card_suit &hand_suit_type, card_rank &hand_rank_type, card_suit &deck_suit_type, card_rank &deck_rank_type)
{
	//swap cards from hand and deck
	int hand_replace_pos = hand.get_position(hand_suit_type, hand_rank_type);
	int deck_swap_pos = deck.get_position(deck_suit_type, deck_rank_type);
	node* hand_replace_node = hand.get_node_at(hand_replace_pos);
	node* deck_swap_node = deck.get_node_at(deck_swap_pos);
	hand_replace_node->data->suit = deck_suit_type;
	hand_replace_node->data->rank = deck_rank_type;
	deck_swap_node->data->suit = hand_suit_type;
	deck_swap_node->data->rank = hand_rank_type;
}

void card_game::swap_cards()
{
	money--;
	round++;
	update_hand();
	do
	{
		get_player_swap();
		swap_flag = true;
		display_hand();
		std::cout << "\nWould you like to swap again? : \'Y/y\': Yes \'N/n\': No ::  ";
		char ch;
		while (!(std::cin >> ch) || !is_valid(ch))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error::Please enter Y or N..." << std::endl;
			std::cout << "\nWould you like to play again? : \'Y/y\': Yes \'N/n\': No :: ";
		}

		if (tolower(ch) == 'y')
			swap_again = true;

		if (tolower(ch) == 'n')
			swap_again = false;

	} while (swap_again);

	check_poker_hand();
}

void card_game::replace_card(hand_card card)
{
	int rand_pos = 0 + rand() % (card_count - 1 + 1);
	node *new_card = deck.get_node_at(rand_pos);
	deck.delete_node(new_card);
	node *replacable_card = hand.get_node_at(card);
	replacable_card->data = new_card->data;
	card_count--;
}

int card_game::get_amount()
{
	return (int)p_hand;
}

std::string card_game::get_poker_hand()
{
	switch (p_hand)
	{
		case one_pair:			return "One Pair, Jack or Higher";
		case two_pair:			return "Two Pair";
		case three_of_a_kind:	return "Three of a Kind";
		case straight:			return "Straight";
		case flush:				return "Flush";
		case full_house:		return "Full House";
		case four_of_a_kind:	return "Four of a Kind";
		case straight_flush:	return "Straigh Flush";
		case royal_flush:		return "Royal Flush";
	}
}

int card_game::count_equal_rank()
{
	linked_list dummy_hand = hand;
	dummy_hand.sort_ll(rank_sort);
	int count = 0;
	node* iter = dummy_hand.get_node_at(0);
	while (iter->next)
	{
		if (iter->data->rank == iter->next->data->rank)
			count++;

		iter = iter->next;
	}
	return count;
}

bool card_game::is_match_value_equal()
{
	linked_list dummy_hand = hand;
	dummy_hand.sort_ll(rank_sort);
	int count = 0;
	node* iter = dummy_hand.get_node_at(0);
	card_rank match_rank = zero, prev_match_rank = zero;
	bool flag = true;
	while (iter->next)
	{
		if (iter->data->rank == iter->next->data->rank)
		{
			match_rank = iter->data->rank;
			count++;
			if (prev_match_rank != zero && prev_match_rank != match_rank)
				return false;
		}
		else
		{
			prev_match_rank = match_rank;
		}

		iter = iter->next;
	}
	return flag;
}

bool card_game::is_one_pair()
{
	int count = count_equal_rank();
	int royal_count = 0;

	linked_list dummy_hand = hand;
	dummy_hand.sort_ll(rank_sort);
	node* iter = dummy_hand.get_node_at(0);
	while (iter->next)
	{
		if ((iter->data->rank == jack)
			&& ((iter->next->data->rank == jack))
			|| (iter->data->rank == queen)
			&& ((iter->next->data->rank == queen))
			|| (iter->data->rank == king)
			&& ((iter->next->data->rank == king))
			|| (iter->data->rank == ace)
			&& ((iter->next->data->rank == ace)))
			royal_count++;
		iter = iter->next;
	}

	return (count == 1 && royal_count == 1);
}

bool card_game::is_two_pair()
{
	int count = count_equal_rank();
	bool flag = false;
	if (count == 2)
		flag = !(is_match_value_equal());

	return flag;
}

bool card_game::is_three_of_a_kind()
{
	int count = count_equal_rank();
	bool flag = false;
	if (count == 2)
		flag = is_match_value_equal();

	return flag;
}

bool card_game::is_four_of_a_kind()
{
	int count = count_equal_rank();
	bool flag = false;
	if (count == 3)
		flag = is_match_value_equal();

	return flag;
}

bool card_game::is_full_house()
{
	int count = count_equal_rank();
	bool flag = false;
	if (count == 3)
		flag = !(is_match_value_equal());

	return flag;
}

bool card_game::is_staright()
{
	linked_list dummy_hand = hand;
	dummy_hand.sort_ll(rank_sort);
	node* iter = dummy_hand.get_node_at(0);
	while (iter->next)
	{
		int curr_rank = iter->data->rank;
		int next_rank = iter->next->data->rank;
		if (next_rank - curr_rank != 1)
			return false;
		iter = iter->next;
	}
	return true;
}

bool card_game::is_flush()
{
	linked_list dummy_hand = hand;
	dummy_hand.sort_ll(suit_sort);
	node* iter = dummy_hand.get_node_at(0);
	while (iter->next)
	{
		if (iter->data->suit != iter->next->data->suit)
			return false;
		iter = iter->next;
	}
	return true;
}

bool card_game::is_straight_flush()
{
	return (is_staright() && is_flush());
}

bool card_game::is_royal_flush()
{
	linked_list dummy_hand = hand;
	dummy_hand.sort_ll(rank_sort);

	bool flag_ace = (dummy_hand.get_node_at(0)->data->rank == 1);
	bool flag_ten = (dummy_hand.get_node_at(1)->data->rank == 10);
	bool flag_jack = (dummy_hand.get_node_at(2)->data->rank == 11);
	bool flag_queen = (dummy_hand.get_node_at(3)->data->rank == 12);
	bool flag_king = (dummy_hand.get_node_at(4)->data->rank == 13);

	bool flag_royal = (flag_ace && flag_ten && flag_jack
						&& flag_queen && flag_king);

	return (is_flush() && flag_royal);
}

bool card_game::is_poker_hand()
{
	p_hand = get_win_conditon();
	return (p_hand != none);
}

poker_hand card_game::get_win_conditon()
{
	if (is_royal_flush())
		return royal_flush;

	if (is_straight_flush())
		return straight_flush;

	if (is_flush())
		return flush;

	if (is_staright())
		return straight;

	if (is_full_house())
		return full_house;

	if (is_four_of_a_kind())
		return four_of_a_kind;

	if (is_three_of_a_kind())
		return three_of_a_kind;

	if (is_two_pair())
		return two_pair;

	if (is_one_pair())
		return one_pair;

	return none;
}

void card_game::display_win_message()
{
	poker_hand p_hand = get_win_conditon();
	std::cout << "\n**************************************************************************" << std::endl << std::endl;
	std::cout << "Poker hand::" << get_poker_hand() << "::Amount won::" << get_amount() << std::endl;
	std::cout << "Congratulations! you've won this round..." << std::endl;
	std::cout << "Keep up the good luck!" << std::endl;
	std::cout << "\n\n**************************************************************************" << std::endl;
	money += get_amount();
}

void card_game::display_lose_message()
{
	std::cout << "\n**************************************************************************" << std::endl << std::endl;
	std::cout << "No Poker Hand matched!" << std::endl;
	std::cout << "Sorry, you've lost this round..." << std::endl;
	std::cout << "Better luck next time!" << std::endl;
	std::cout << "\n\n**************************************************************************" << std::endl;
}

void card_game::check_poker_hand()
{
	swap_flag = false; play_flag = false;
	if (is_poker_hand())
		display_win_message();
	else
		display_lose_message();
	display_hand();
	std::cout << "\nYour money::" << money << std::endl;
}

bool card_game::is_game_over()
{
	return (play_again || money == 0);
}

void card_game::play_game()
{
	money--;
	round++;
	update_hand();
	get_player_hand();
	play_flag = true;
	display_hand();
	check_poker_hand();
}

void card_game::game_reset()
{
	bool play_again = true;
	bool swap_flag = false;
	bool play_flag = false;
	bool game_over = false;
	create_deck();
}

void card_game::default_mode()
{
	std::cout << "Welcome to Poker..." << std::endl;
	game_reset();
	//Loop till gameover
	do
	{
		display_game_round();
		get_response();
	} while (is_game_over());

	std::cout << "\nThank you for playing...\n" << std::endl;
}

card_game::~card_game()
{

}