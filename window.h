/******************************************************************************
 * File Name: ncurses.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <ncurses.h>

using namespace std;

#ifndef WINDOW_H
#define WINDOW_H

class Window {
  public:
    Window();
    virtual ~Window();

    // These abstract functions will be different for each type of window
    virtual bool Init() = 0;
    virtual void Die() = 0;
    virtual char MakeWindowChar(string message) = 0;
    virtual string MakeWindow(string message) = 0;

  protected:
    bool isInit_ = false;
};

#endif /* WINDOW_H */

