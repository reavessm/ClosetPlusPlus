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

bool Vulkan::Init() {
  bool ret = false
  
  initscr();
  start_color();

  init_pair(1, COLOR_BLUE, COLOR_RED);

  wbkgd(stdscr, COLOR_PAIR(1));
  refresh();

  ret = true;

  return ret;
}

void Vulkan::Die() {
  endwin();
}


/*******************************************************************************
 * Function 'MakeWindowChar'
 * Returns: char representing user input
 * Summary: This function rewrites the vulkan window
 */
char Vulkan::WindowChar(string message) {
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
