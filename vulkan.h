/******************************************************************************
 * File Name: vulkan.h
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

#ifndef VULKAN_H
#define VULKAN_H

class Vulkan : public Window {
  public:
    Vulkan();
    virtual ~Vulkan();
};

#endif /* VULKAN_H */

