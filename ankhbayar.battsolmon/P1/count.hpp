#ifndef FINDINGCOUNT_HPP
#define FINDINGCOUNT_HPP
#include <cstddef>
#include <limits>
namespace tsomo
{
    struct FindingCount
    {
    public:
        FindingCount();
        void operator()(size_t value);
        size_t operator()() const;
    private:
        size_t lenghts_;
        size_t count_;
        size_t firstNum_;
        size_t secondNum_;
    };
}
#endif
