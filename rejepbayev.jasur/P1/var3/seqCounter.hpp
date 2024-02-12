
#ifndef REJEPBAYEV_JASUR_SEQUENCE_COUNTER_HPP
#define REJEPBAYEV_JASUR_SEQUENCE_COUNTER_HPP
namespace rejepbayev
{
namespace jasur
{

  struct SequenceCounter
  {
    public:
      SequenceCounter();
      void operator()(int number); 
      int operator()() const; 
    private:
      int count_; 
      int lastElement_; 
  };
}
}
