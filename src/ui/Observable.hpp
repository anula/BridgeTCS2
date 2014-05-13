#ifndef UI_OBSERVABLE_HPP
#define UI_OBSERVABLE_HPP

#include <boost/signals2/signal.hpp>

namespace ui
{

template <class T>
class Observable
{
public:
    boost::signals2::signal<void (T const &)> sigModified;
};

}

#endif // UI_OBSERVABLE_HPP
