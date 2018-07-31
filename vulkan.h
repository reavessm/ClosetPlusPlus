/******************************************************************************
 * File Name: vulkan.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "window.h"

using namespace std;

#ifndef VULKAN_H
#define VULKAN_H

class Vulkan : public Window {
 public:
  Vulkan();
  virtual ~Vulkan();

  bool Init();
  void Die();
  char MakeWindowChar(string message);
  string MakeWindow(string message);

 private:
  bool isInit_ = false;
};

#endif /* VULKAN_H */
