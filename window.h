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

    bool Init();
    void Die();
    char MakeWindowChar();
    string MakeWindow();

  private:
    bool isInit_ = false;
};

#endif /* WINDOW_H */

