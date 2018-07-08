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

#ifndef CUST_NCURSES_H
#define CUST_NCURSES_H

class Ncurses {
  public:
    Ncurses();
    virtual ~Ncurses();

    bool Init();
    void Die();
    char MakeWindowChar(string message);
    string MakeWindow(string message);

  private:
    bool isInit_ = false;
};

#endif /* CUST_NCURSES_H */

