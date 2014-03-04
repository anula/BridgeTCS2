#include <string>

class Player
{
public:		
	Player(std::string _name) : name(_name) {}	
	
	std::string getName(){
		return name;
	}
	
private:
	std::string name;
};
