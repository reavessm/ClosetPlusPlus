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

#include "window.h"

using namespace std;

#ifndef CUST_NCURSES_H
#define CUST_NCURSES_H

class Ncurses {
  public:
    Ncurses();
    virtual ~Window();

    bool Init();
    void Die();
    char WindowChar();
    string Window();

  private:
    bool isInit_ = false;
    final const Window::type type = ncurses;
}

#endif /* CUST_NCURSES_H */

