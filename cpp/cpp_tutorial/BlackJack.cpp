#include <algorithm>  // for std::shuffle
#include <array>
#include <cassert>
#include <iostream>
#include "random.h"  // for Random::mt

struct Card {
  enum Rank {
    rank_ace,
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

    max_ranks
  };

  enum Suit {
    suit_club,
    suit_diamond,
    suit_heart,
    suit_spade,

    max_suits
  };

  // These need to be static so they are only created once per program, not once per Card
  static constexpr std::array allRanks{rank_ace,  rank_2,     rank_3,   rank_4, rank_5,
                                       rank_6,    rank_7,     rank_8,   rank_9, rank_10,
                                       rank_jack, rank_queen, rank_king};
  static constexpr std::array allSuits{suit_club, suit_diamond, suit_heart, suit_spade};

  Rank rank{};
  Suit suit{};

  friend std::ostream& operator<<(std::ostream& out, const Card& card) {
    static constexpr std::array ranks{'A', '2', '3', '4', '5', '6', '7',
                                      '8', '9', 'T', 'J', 'Q', 'K'};
    static constexpr std::array suits{'C', 'D', 'H', 'S'};

    out << ranks[card.rank] << suits[card.suit];
    return out;
  }

  int value() const {
    static constexpr std::array rankValues{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    return rankValues[rank];
  }
};

class Deck {
  std::array<Card, 52> m_cards{};
  std::size_t m_nextCardIndex{0};

 public:
  Deck() {
    for (auto suit : Card::allSuits)
      for (auto rank : Card::allRanks)
        m_cards[rank + suit * Card::max_ranks] = {rank, suit};
  }

  Card dealCard() {
    assert(m_nextCardIndex < 52 && "Deck is empty");
    return m_cards[m_nextCardIndex++];
  }

  void shuffle() {
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    m_nextCardIndex = 0;
  }
};

int main()
{
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}
