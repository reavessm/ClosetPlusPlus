/**
 * @class Ncurses
 * @headerfile ncurses.h
 * @author Stephen M. Reaves
 * @date July 14th, 2018
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

 private:
  // bool isInit_ = false;
  void AddShirt();
  void AddPants();
  void AddSocks();
  void AddShoes();
  void AddBelt();
};

#endif /* CUST_NCURSES_H */
