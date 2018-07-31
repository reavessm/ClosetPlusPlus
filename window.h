/**
 * @class Window
 * @author Stephen M. Reaves
 * @headerfile window.h
 * @date Jul 19, 2018
 * @brief Abstract class for User Interfaces
 */

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef WINDOW_H
#define WINDOW_H

class Window {
 public:
  // Define these with empty braces to not inherit
  Window(){};
  virtual ~Window(){};

  // These abstract functions will be different for each type of window
  virtual bool Init() = 0;
  virtual void Die() = 0;
  virtual char MakeWindowChar(string message) = 0;
  virtual string MakeWindow(string message) = 0;

 protected:
  bool isInit_ = false;
};

#endif /* WINDOW_H */
