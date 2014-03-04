void Deck::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::getCard()
{
    return deck.back();
}

int Deck::count()
{
    return deck.size();
}
