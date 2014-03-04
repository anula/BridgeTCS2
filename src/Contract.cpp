enum Trumpf
{
  Clubs,
  Diamonds,
  Hearts,
  Spades,
  NT
};

struct Contract
{
  int count;
  Trumpf trumpf;
  int multiplier;
};
