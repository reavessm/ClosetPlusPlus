/**
* @class Vulkan
* @author Stephen M. Reaves
* @headerfile vulkan.h
* @date Aug 12, 2018
*/
#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "frontend.h"

using namespace std;

#ifndef VULKAN_H
#define VULKAN_H

class Vulkan : public Frontend {
 public:
  Vulkan();
  virtual ~Vulkan();

  //bool Init();
  //void Die();
  //char MakeWindowChar(string message);
  //string MakeWindow(string message);

 private:
  //bool isInit_ = false;
};

#endif /* VULKAN_H */
