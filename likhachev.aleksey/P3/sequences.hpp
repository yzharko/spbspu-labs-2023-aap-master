#ifndef SEQUENCES_HPP
#define SEQUENCES_HPP
namespace likhachev
{
  char* readSequence(int &size);
  void copyCharArray(char *copyFrom, char *copyTo, int size);

  int strDoesHasSame(char *array1, int size1, char *array2, int size2);
  char* strRemoveDigits(int maxSize, char *array, int &size);

  void outLine(char *array, int size);
};
#endif
