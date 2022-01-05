//
//  VectorString.cpp
//  vectorclass1
//
//  Created by Eva on 1/25/21.
//  Copyright © 2021 Eva. All rights reserved.
//

#include "VectorString.hpp"
//#include "VectorString.h"
#include <string>
//#include <cstring>
#include <iostream>
#include <memory>


pic10b::VectorString::VectorString()
{
  vec_size=0;
  vec_capacity=1;

    data = std::shared_ptr<std::string>(std::make_shared <std::string>(std::string()[capacity()]));
};



pic10b::VectorString::VectorString(std::size_t t){
vec_size=t;
vec_capacity=2*t;
data = std::unique_ptr<std::string[]>(new std::string[vec_capacity]());
};

pic10b::VectorString::VectorString(std::size_t t, std::string input){
vec_size=t;
vec_capacity=2*t;
data = std::unique_ptr<std::string[]>(new std::string[vec_capacity]());
for(size_t i=0; i<vec_size; i++){
  data[i]=input;
}
};


pic10b::VectorString::VectorString(const VectorString& input){
  vec_capacity=input.capacity();
  vec_size=input.size();
data = std::unique_ptr<std::string[]>(new std::string[vec_capacity]());
for(size_t i=0; i<input.size(); i++){
   data[i]=input.data[i];
}
};


pic10b::VectorString::VectorString(VectorString&& input){
data=input.data;
vec_capacity=input.capacity();
vec_size=input.size();
};
int pic10b::VectorString::size() const
  {
    return vec_size;
  };

int pic10b::VectorString::capacity() const
  {
    return vec_capacity;
  };



pic10b::VectorString& pic10b::VectorString::operator=(const VectorString& input){
vec_capacity=input.capacity();
vec_size=input.size();
data = std::shared_ptr<std::string>(new std::string[vec_capacity]());

for(size_t i=0; i<input.size(); i++){
   data[i]=input.data[i];
}
return *this;
}


pic10b::VectorString & pic10b::VectorString:: operator=(VectorString&& input) {
data=input.data;
vec_capacity=input.capacity();
vec_size=input.size();
return *this;
}


void pic10b::VectorString::push_back(std::string s){
if(vec_capacity>vec_size){    /** check  if size is less than capacity */
data[vec_size]=s;
vec_size++;
}

else {  /** if size is greater than capacity, make a new array */
vec_capacity *= 2;
std::shared_ptr<std::string> data2(new std::string[vec_capacity]);

for(size_t i=0; i<vec_size; i++){  /** transfer the data to a new array */
  data2[i]=data[i];
}
data2[vec_size]=s;
vec_size++;
data=data2;
}
};


void pic10b::VectorString::pop_back(){
  vec_size--;
  };


void pic10b::VectorString::deleteAt(size_t t){

for(int i=t; i<vec_size-1; i++){  /** transfer all of the elements down by one */
    data[i]=data[i+1];
}
vec_size--;
};


void pic10b::VectorString::insertAt(size_t t, std::string s){

std:: cout << "before insert\n";
  for(int i=0; i<vec_size; i++){
    std::cout <<data[i];}

if(vec_capacity>vec_size){ /** check  if size is less than capacity */
std::cout << "if";
for(int i=vec_size-1; i>t; i--){  /** transfer all of the elements up by one */
    data[i+1]=data[i];
}
data[t]=s;
vec_size++;
}

else{  /** if size is greater than capacity, make a new array */
  std::cout<<"else";
  vec_capacity *= 2;
  std::shared_ptr<std::string> data2(new std::string[vec_capacity]);
  
for(size_t i=0; i<vec_size; i++){  /** transfer the data */
  data2[i]=data[i];
}

for(int i=vec_size-1; i>t; i--){ /** transfer all of the elements up by one */
    data2[i+1]=data2[i];
}
data2[t]=s;
vec_size++;
data=data2;
}

std:: cout << "after insert\n";
  for(int i=0; i<vec_size; i++){
    std::cout <<data[i];}
};

std::string& pic10b::VectorString::at(size_t t){
  return data[t];
}

const std::string& pic10b::VectorString::at(size_t t) const{
  return data[t];
}

