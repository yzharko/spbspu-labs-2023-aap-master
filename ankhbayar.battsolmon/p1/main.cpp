#include <iostream>  
  
int foo()  
{  
  
  int first=123;  
  int second=123;  
  int third=123;  
  int minValue=123;  
  int maxValue=123;  
  int averageValue;  
  int cnt=0;  
  bool pifagor;  
  
  std::cin >> first;  
  if (!std::cin)  
  {  
   std::cout << "ERROR. String didnt read. \n";  
   return 0;  
  }  
  if (first ==0)  
  {  
  std::cout << 0;  
  return 0;  
  }  
  std::cin >> second;  
  if (!std::cin)  
  {  
   std::cout << "ERROR. String didnt read. \n";  
   return 0;  
  }  
  if (second ==0)  
  {  
   std::cout<< 0;  
   return 0;  
  }  
  while(std::cin >> third && third !=0)  
  {    
    minValue=std::min(first, std::min(second, third));
    maxValue = std::max(first, std::max(second, third));
    averageValue = first+second+third-minValue-maxValue;
    pifagor = (minValue*minValue+averageValue*averageValue==maxValue*maxValue);
    if (pifagor)
    {
     cnt++;

     std::cin >> first;

     if (!std::cin)
     {
       std::cout << "ERROR. String didnt read. \n";
       return 0;
     } 

     if (first==0)
     {
       break;
     }

     std::cin >> second;

     if (!std::cin)
     {
       std::cout << "ERROR. String didnt read. \n";
       return 0;
     }

     if (second==0)
      {
       break;
      }
     } 
     else
     {
      first=second;
      second=third;

     }
   }
   std::cout << cnt << "\n";
   return 0;
}
