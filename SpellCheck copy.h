//
//  SpellCheck.h
//  Spell Checker1
//
//  Created by Eva on 1/12/21.
//  Copyright © 2021 Eva. All rights reserved.
//

#ifndef SpellCheck_h
#define SpellCheck_h
#include <unordered_set>
#include <string>

class SpellCheck{
    
private:
    std::unordered_set <std::string> dictionary;
public:

/**
Default with no words
*/
    SpellCheck();

/**
This function transfers the words in the dictionary file to an unordered set
*/ 
 void read_dictionary();

/**
This function checks if the modified word from the imported text is in the dictionary unordered set
@param string 1- word
@return bool- true if the word is found
*/
  bool is_valid(std::string string1);


/**
This function processes the imported text. It opens the user textfile, and builds strings of the words in it. It calls other helper functions to modify the word so that it can be compared to the dictionary. It then puts the original word into a string to be printed to the display
@param string- name of file to open
*/
  void process_file(std::string filename);
    
};

/**
This function checks if a given charachter is a white space
@param char - the charachter we are checking 
@return- bool- true if c is white space
*/
bool is_white_space(char c);


/**
This function checks if the word ends in a punctuation mark
@param string- word
@return bool - true if string ends in a punctuation mark
*/
bool final_punctuation(std::string string1);


/**
This function removes the last charachter of a string that ends in a punctuation mark
@param string- word
*/
void depunctuate(std::string& string1);


/**
This function checks if the first letter of a word is capitalizaed and if it is, makes it lowercase
@param string- word
*/
void decapitalize(std::string& string1);


#endif /* SpellCheck_h */
