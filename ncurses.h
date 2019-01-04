/**
 * @class Ncurses
 * @headerfile ncurses.h
 * @author Stephen M. Reaves
 * @date Sep 16, 2018
 */

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "frontend.h"

using namespace std;

#ifndef CUST_NCURSES_H
#define CUST_NCURSES_H

class Ncurses : public Frontend {
 public:
  Ncurses();
  virtual ~Ncurses();

  bool Init();
  void Die();
  void CreateCloset();
  char MakeWindowChar(string message);
  string MakeWindow(string message);
  WINDOW *CreateNewWindow(int height, int width, int starty, int startx);
  void DestroyWindow(WINDOW *local_win);

 private:
  void AddShirt();
  void AddPants();
  void AddSocks();
  void AddShoes();
  void AddBelt();
  WINDOW *win;
};

#endif /* CUST_NCURSES_H */
