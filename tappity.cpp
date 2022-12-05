#include "tappity.h"
#include <cmath>
#include<iostream>
/**
 * Class for tappity
**/
using namespace std;

//Constructor sets the reference phrase
tappity::tappity(std::string references)
{
  //provide a reference phrase
  reference=references;
}

//Provide the input to be compared to the reference. Before this
//function is called, the input should be considered an empty string
void tappity::entry(std::string inputs)
{
  //this is passed in what the user inputed and if done correctly the input will match the reference
  input = inputs;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  //calculates the absolute value of the difference
  ldifference=(reference.size()-input.size());
  if(ldifference<0)
  {
    ldifference=ldifference*-1;
  }
  return ldifference;
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  //this is how close the users entry was to the reference string
  double score=0;
  int length=max(reference.length(),input.length());
  if((reference.length()==0)&&(input.length()==0))
  {
    return 100;
  }
  if(reference.length()==0)
  {
    return 0;
  }
  for(int i=0; i<length;i++)
  {
    if(reference[i]==input[i])
    {
      score++;
    }
    if(reference[i+1]==NULL||input[i+1]==NULL)
    {
      break;
    }
  }

  return ((score/length)*100);
}