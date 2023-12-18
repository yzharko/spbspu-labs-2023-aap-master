#ifndef FINDLOCAL_HPP
#define FINDLOCAL_HPP
#include <cstddef>

namespace lisitsyna
{
    struct FindLocalMax
    {
    public:
        FindLocalMax();
        void operator()(int value);
        size_t operator()() const;
    private:
        size_t countmaxs_;
        int maxValue;
    };
}

#endif
