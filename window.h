/******************************************************************************
 * File Name: window.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */


#ifndef window_H
#define window_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "ncurses.h"
#include "vulkan.h"

using namespace std;

class Window {
  public:
    //Constructors and Deconstructors
    Window(){};
    virtual ~Window(){}

    bool IsInit();

    boot Init(string type = "ncurses") {
      bool ret = false
      switch (type) {
        case "ncurses" :
          Ncurses ncurses;
          ret = ncurses.Init();
          break;
        case "vulkan" :
          Vulkan vulkan;
          ret = vulkan.Init();
          break;
        default :
          cerr << "Error, no window type specified" << endl;
          ret = false;
      }

    bool Init();
    void Die();
    string Window();
    char WindowChar();

  protected:
    // Set Globals
    bool isInit_ = false;
    enum type {
      ncurses,
      vulkan
    };
};


#endif /* window_H */ 
