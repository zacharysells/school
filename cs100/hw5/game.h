using namespace std;

class game
{
	private:
	double IGNRating;
	
	public:
	
	double rating()
	{
		return IGNRating;
	}
	
	game(double rating = 0.0)
	{
		IGNRating = rating;
	}
	
	virtual void play() const = 0;
};
class guessingGame: public game
{
	public:
	guessingGame(double rate = 0.0);
	void play() const;
};
class hangman: public game
{
	public:
	hangman(double rate = 0.0);
	void play() const;
};
class mathGame: public game
{
	public:
	mathGame(double rate = 0.0);
	void play() const;
};
	
