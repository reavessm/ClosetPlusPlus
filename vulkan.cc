/******************************************************************************
 * File Name: vulkan.cc
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "vulkan.h"

using namespace std;

Vulkan::Vulkan(){}
Vulkan::~Vulkan(){}

bool Vulkan::Init() {
  isInit_ = false;

  return isInit_;
}

void Vulkan::Die() {
  
}


/*******************************************************************************
 * Function 'MakeWindowChar'
 * Returns: char representing user input
 * Summary: This function rewrites the vulkan window
 */
char Vulkan::MakeWindowChar(string message) {
  return 'a';
}




/*******************************************************************************
 * Function 'MakeWindow'
 * Returns: string representing user input
 * Summary: This function rewrites the vulkan window
 */
string Vulkan::MakeWindow(string message) {
  return message;
}
