#include "count.hpp"
#include <iostream>
#include <stdexcept>
tsomo::FindingCount::FindingCount() :
    lenghts_(0),
    count_(0),
    firstNum_(0),
    secondNum_(0)
{}
void tsomo::FindingCount::operator()(size_t value)
{
    const size_t maxSize = std::numeric_limits< size_t >::max();
    if (count_ == maxSize)
    {
        throw std::logic_error("Sequence is very long\n");
    }
    lenghts_ += (value != 0 ? 1 : 0);
    count_ += ((firstNum_ > secondNum_ && secondNum_ > value) ? 1 : 0);
    firstNum_ = secondNum_;
    secondNum_ = value;
}
size_t tsomo::FindingCount::operator()() const
{
    if (lenghts_ < 3)
    {
        throw std::logic_error("Too short sequence\n");
    }
    else
    {
        return count_;
    }
}
