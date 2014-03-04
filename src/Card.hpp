enum Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
};

enum Rank
{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

struct Card
{
    Suit suit;
    Rank rank;

    Card(Rank r, Suit s)
    {
        rank = r;
        suit = s;
    }
};

