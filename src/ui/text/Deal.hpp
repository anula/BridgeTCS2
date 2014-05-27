#ifndef UI_TEXT_DEAL_HPP
#define UI_TEXT_DEAL_HPP

#include <iostream>
#include <string>

#include "model/Deal.hpp"
#include "model/Contract.hpp"

namespace ui
{
namespace text 
{

class Deal
{
public:
    
    Deal(int n = 0) : indent("") {
        while (n--)
           indent = indent + "\t";
    }

    void notify(model::Deal const & deal)
    {
        if (deal.playFinished)
	   {
			std::cout << indent << "Rozdanie zakończone." << std::endl;
			return;
	   }
	   if (deal.biddingFinished)
	   {
			std::cout << indent << "Licytacja zakończona." << std::endl;
	   }
    }
private:
    std::string indent;
};

}
}

#endif // UI_TEXT_DEAL_HPP