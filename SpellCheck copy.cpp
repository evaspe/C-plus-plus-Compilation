//
//  SpellCheck.cpp
//  Spell Checker1
//
//  Created by Eva on 1/12/21.
//  Copyright © 2021 Eva. All rights reserved.
//

#include <stdio.h>
#include "SpellCheck.h"
#include <fstream>
#include <iostream>
#include <string>



void SpellCheck:: read_dictionary(){
    std::ifstream dict;
    dict.open("dictionary.txt");
    
    
    while(dict.get()!= EOF){
        dict.unget();
        std::string line;
        std::getline(dict, line);
        dictionary.insert(line);}
        
    
};


SpellCheck::SpellCheck(){
};


bool SpellCheck::is_valid(std::string s){
    if(dictionary.find(s)==dictionary.end()){
      return false;
    }
    else{
      return true;
    }
};


void SpellCheck::process_file(std::string filename){
 
    std::ifstream file;
    file.open (filename.c_str());

    if(!file.is_open()){
      
      std::cout << "file is not open";
    }
    

    std::string string1; //string to modify word
    std::string copy; // string to make a copy of original to add to display
    std::string display; //display to print
    char c;
 
 while(file.peek()!= EOF){

 c=file.peek();

 if(is_white_space(c)){
 display+=c;
 file.get();
 }

 else{

   while(!is_white_space(c)) 
   { 
    string1 += file.get(); // build word
    copy=string1; 
    c=file.peek();
    if(c== EOF){ 
      break;
    }
    }

  }
  if (final_punctuation(string1))
    {
      depunctuate(string1);
    }

   if(string1!="I") 
    {decapitalize(string1);}

    
    if(is_valid(string1)){
      display+= copy;
    }
    else {
      display+= "*" + copy + "*" ;
    }
    string1.clear();
    copy.clear();
 }

    std::cout << display;
    }

 

bool is_white_space(char c){
    if (c==' ' || c=='\n' || c=='\t'){
      return true;
    }
    else {
      return false;
    }


}


bool final_punctuation(std::string s){
if(s.length()!=0){
    if(s.back()== '.'||s.back()== ',' || s.back()== '!'|| s.back()== '?'|| s.back()== ';'|| s.back()== ':'){
      return true;
    }
    else{return false;}}
    else {return false;}
}


void depunctuate(std::string &s){
  s.resize(s.size()-1); 
}


void decapitalize (std::string& s){
  char c=s[0];
if ( ('A' <= c) && (c <= 'Z') ) 
{ c += ('a' - 'A');
s[0]=c;}
}
