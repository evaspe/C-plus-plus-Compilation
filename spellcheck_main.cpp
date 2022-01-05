//
//  main.cpp
//  Spell Checker1
//
//  Created by Eva on 1/12/21.
//  Copyright © 2021 Eva. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "SpellCheck.h"



int main() {
    SpellCheck go;

    std::string filename;
    std::cout << "Enter file name to spell check:";
    std::cin>> filename;
  
    go.read_dictionary();
    go.process_file(filename);
    return 0;
}
