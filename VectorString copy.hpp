//
//  VectorString.hpp
//  vectorclass1
//
//  Created by Eva on 1/25/21.
//  Copyright © 2021 Eva. All rights reserved.
//

#ifndef VectorString_hpp
#define VectorString_hpp

#include <stdio.h>

#include <iostream>
#include <memory>

namespace pic10b{
class VectorString{
  
  std::unique_ptr<std::string[]> data;
  //data = new std::string[vec_capacity];
  int vec_size;
  int vec_capacity;
  
public:

/**
This function allocates a dynamic array std::string
of one element
 */
  VectorString();

  /**
This function allocates a dynamic array of twice the input size
@param size t is the input size
*/
  VectorString(std::size_t t);

/**
This function allocates a dynamic array of twice the input size and initializes all of the varibles to the input string
@param size t is the input size, string input is the user input string
*/
  VectorString(std::size_t t, std::string input);

/**
This is a copy constructor that takes in an object and makes a copy
@param input is the object that we are copying
*/
  VectorString(const VectorString& input);
  
  /**
This is a move constructor that takes in the data from an object without making a copy
@param input is the reference to the object that we are taking data from
*/
  VectorString(VectorString&& input);

 /**
 This is a copy assignment operator
 @param const reference to an input object
 @return -  reference to new object
*/
  VectorString& operator=(const VectorString& input);


   /**
   This is a move assignment operator
   @param reference to a reference to an input object
   @return - reference to new object
*/
  VectorString& operator=(VectorString&& input);

  /**
This function returns the size of the dynamic array
@return int size of dynamic array */
  int size() const;

 /**
This function returns the capacity of the dynamic array
@return int capacity of dynamic array */
  int capacity() const;


   /**
This function adds a new element to the dynamic array
@param string- the element to be added */
  void push_back(std::string s);

   /**
This function deletes the last element in the dynamic array */
  void pop_back();


 /**
This function removes an element from a specific location in the dynamic array
@param size_t- the location of the removal */
  void deleteAt(size_t t);

 /**
This function adds an element to a specific location in the dynamic array
@param size_t- the location of the addition, string s- the element to be added */
  void insertAt(size_t t, std::string s);

   /**
This function returns a reference to an element at a specific location in the array
@param size_t- the location of the element
@return string&- the reference to the element
 */
  std::string& at(size_t t);

   /**
This const function returns a reference to an element at a specific location in the array
@param size_t- the location of the const element
@return string&- the const reference to the element
 */
  const std::string& at(size_t t) const;

};
}

#endif /* VectorString_hpp */
