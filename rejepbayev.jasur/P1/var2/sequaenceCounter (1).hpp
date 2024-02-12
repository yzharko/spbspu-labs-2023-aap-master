#ifndef sequaenceCounter_HPP
#define sequaenceCounter_HPP

// Namespace for sequence counting functionality
namespace number
{
  // Struct to count sequences based on specific conditions
struct SequenceCounter
  {
  public:
    void operator()(int & newNumber);
    // Updates sequence and counts if conditions are met
    void updateAndCountSequence();
    // Returns the count of valid sequences
    int getSequenceCount();
  private:
    int firstNum = 0;
    int secondNum = 0;
    int thirdNum = 0;
    int sequenceUpdates = 0;
    int sequenceUpdateser = 0;
  };
}

#endif
