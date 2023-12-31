/*
  i chose to change this game a little bit to make it nicer.
  i wanted to be able to track the cards each player has, and i wanted to pop
  them out of the original deck.
  to do so i changed deck to be a std::vector instead of an std::array.
  i also made some printing to show the hand after each play
*/

#include "clearCin.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <chrono>
#include <random>
#include <cassert>

enum class CardRank
{
  rank_2,
  rank_3,
  rank_4,
  rank_5,
  rank_6,
  rank_7,
  rank_8,
  rank_9,
  rank_10,
  rank_jack,
  rank_queen,
  rank_king,
  rank_ace,
  max_rank,
};

enum class Suit
{
  club,
  diamond,
  heart,
  spade,
  max_suit,
};

enum class GameState
{
  win,
  lose,
  tie,
};

struct Card
{
  CardRank rank{};
  Suit suit{};
};

struct Player
{
  std::string playerType{};
  std::vector<Card> cards{};
  int sum{};
};

using Deck = std::vector<Card>;

constexpr int maxScore { 21 };
constexpr int dealerMaxHitNum { 17 };
constexpr int deckSize { 52 };

// forward declarations
void printCard(const Card& card);
Deck createDeck();
void printDeck(const Deck& deck);
void shuffleDeck(Deck& deck);
int getCardValue(const Card& card);
void getCard(Deck& deck, Player& player);
void deal(Deck& deck, Player& dealer, Player& player);
void printPlayerCards(const Player& player);
void playerTurn(Player& player, Deck& deck);
void dealerTurn(Player& dealer, Deck& deck);
GameState decideWinner(const Player& player, const Player& dealer);
void announceWinner(const GameState gameState);
void printPlayerState(const Player& player);

GameState playBlackjack(Deck& deck);

int main()
{
  Deck deck { createDeck() };

  shuffleDeck(deck);

  announceWinner(playBlackjack(deck));

  return 0;
}

void printCard(const Card& card)
{
  switch(card.rank)
  {
  case CardRank::rank_2:
    std::cout << 2;
    break;
  case CardRank::rank_3:
    std::cout << 3;
    break;
  case CardRank::rank_4:
    std::cout << 4;
    break;
  case CardRank::rank_5:
    std::cout << 5;
    break;
  case CardRank::rank_6:
    std::cout << 6;
    break;
  case CardRank::rank_7:
    std::cout << 7;
    break;
  case CardRank::rank_8:
    std::cout << 8;
    break;
  case CardRank::rank_9:
    std::cout << 9;
    break;
  case CardRank::rank_10:
    std::cout << 10;
    break;
  case CardRank::rank_jack:
    std::cout << 'J';
    break;
  case CardRank::rank_queen:
    std::cout << 'Q';
    break;
  case CardRank::rank_king:
    std::cout << 'K';
    break;
  case CardRank::rank_ace:
    std::cout << 'A';
    break;
  default:
    std::cout << "???";
    break;
  }

  switch (card.suit)
  {
  case Suit::club:
    std::cout << 'C';
    return;
  case Suit::diamond:
    std::cout << 'D';
    return;
  case Suit::heart:
    std::cout << 'H';
    return;
  case Suit::spade:
    std::cout << 'S';
    return;
  default:
    std::cout << "???";
    break;
  }
}

Deck createDeck()
{
  Deck deck(deckSize);
  int cardIndex{ 0 };
  for (int i{0}; i < static_cast<int>(Suit::max_suit); ++i)
  {
    for (int j { 0 }; j < static_cast<int>(CardRank::max_rank); ++j)
    {
      deck[cardIndex].suit = static_cast<Suit>(i);
      deck[cardIndex].rank = static_cast<CardRank>(j);
      ++cardIndex;
    }
  }

  return deck;
}

void printDeck(const Deck& deck)
{
  for (auto card : deck)
  {
    printCard(card);
    std::cout << ' ';
  }
  std::cout << '\n';
}

void shuffleDeck(Deck& deck)
{
  static std::mt19937 mt { static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };
  std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card)
{
  switch(card.rank)
  {
  case CardRank::rank_2:
    return 2;
  case CardRank::rank_3:
    return 3;
  case CardRank::rank_4:
    return 4;
  case CardRank::rank_5:
    return 5;
  case CardRank::rank_6:
    return 6;
  case CardRank::rank_7:
    return 7;
  case CardRank::rank_8:
    return 8;
  case CardRank::rank_9:
    return 9;
  case CardRank::rank_10:
  case CardRank::rank_jack:
  case CardRank::rank_queen:
  case CardRank::rank_king:
    return 10;
  case CardRank::rank_ace:
    return 11;
  default:
    assert(false && "should never happen");
    return 0;
  }
}

void getCard(Deck& deck, Player& player)
{
  Card tempCard{ deck.at(deck.size() - 1) };
  player.cards.insert(player.cards.end(), tempCard);
  player.sum += getCardValue(tempCard);
  deck.pop_back();
}

void deal(Deck& deck, Player& dealer, Player& player)
{
  getCard(deck, dealer);
  // this might be funny to do in a loop but if number of dealt cards changes
  // it'll make an easier fix
  for (int i { 0 }; i < 2; ++i)
  {
    getCard(deck, player);
  }
}

void printPlayerCards(const Player& player)
{
  for (auto card : player.cards)
  {
    printCard(card);
    std::cout << ' ';
  }
  std::cout << '\n';
}

void playerTurn(Player& player, Deck& deck)
{
  std::cout << "Player's turn!\n";
  std::string choice{};
  while(choice != "stand")
  {
    std::cout << "hit or stand? ";
    std::cin >> choice;
    handleCinBuffer();
  
    if (choice == "hit")
    {
      std::cout << "Player hits!\n";
      getCard(deck, player);
      printPlayerState(player);
      if(player.sum > maxScore)
      {
        return;
      }
    }
  }
  std::cout << "Player stands.\n";
  std::cout << "Player's turn is over, dealer plays next.\n";
}

void dealerTurn(Player& dealer, Deck& deck)
{
  std::cout << "Dealer's turn!\n";
  while(dealer.sum < dealerMaxHitNum)
  {
    std::cout << "Dealer hits!\n";
    getCard(deck, dealer);
    printPlayerState(dealer);
    if (dealer.sum > maxScore)
    {
      return;
    }
  }
  if (dealer.sum <= maxScore)
  {
    std::cout << "Dealer stands.\n";
  }
}

GameState decideWinner(const Player& player, const Player& dealer)
{
  std::cout << "Player has " << player.sum << " points.\n";
  std::cout << "Dealer has " << dealer.sum << " points.\n";
  if (player.sum == dealer.sum)
  {
    return GameState::tie;
  }
  else if (player.sum > dealer.sum && player.sum <= maxScore)
  {
    return GameState::win;
  }
  return GameState::lose;
}

void announceWinner(const GameState gameState)
{
  switch(gameState)
  {
  case GameState::win:
    std::cout << "Player won!!\n";
    return;
  case GameState::lose:
    std::cout << "Dealer won. Better luck next time!\n";
    return;
  case GameState::tie:
    std::cout << "It's a tie. No one won. Better luck next time.\n";
    return;
  default:
    assert(false && "should never happen");
    return;
  }
}

void printPlayerState(const Player& player)
{
  std::cout << player.playerType << " hand is: ";
  printPlayerCards(player);
  std::cout << player.playerType << " has " << player.sum << " points.\n";
}

GameState playBlackjack(Deck& deck)
{
  Player dealer{ "Dealer" };
  Player player{ "Player" };

  deal(deck, dealer, player);

  printPlayerState(player);
  printPlayerState(dealer);

  playerTurn(player, deck);
  if (player.sum > maxScore)
  {
    std::cout << "Player has gone over " << maxScore << " points.\n";
    return GameState::lose;
  }
  if(player.sum <= maxScore)
  {
    dealerTurn(dealer, deck);
    if (dealer.sum > maxScore)
    {
      std::cout << "Dealer has gone over " << maxScore << " points.\n";
      return GameState::win;
    }
  }
  return decideWinner(player, dealer);
}
