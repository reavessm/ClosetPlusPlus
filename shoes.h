/******************************************************************************
 * File Name: shoes.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary: Header File for 'Shoes' class in the Closet++ program
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef SHOES_H
#define SHOES_H

/* const int kDummyShoesID = -1;
const string kDummyShoesName = "Fake Name";
const string kDummyShoesPrimColor = "Fake Primary Color";
const string kDummyShoesSecColor = "Fake Secondary Color";
const string kDummyShoesTertColor = "Fake Tertiary Color";
const string kDummyShoesMaterial = "Fake Material";
const string kDummyShoesStyle = "Fake Style"; */

class Shoes {
  public:
    //Constructors and Deconstructors
    Shoes();
    Shoes(int id, string name, string prim_color, string sec_color, 
          string tert_color, string material, string style); 
    virtual ~Shoes();

    //General Functions
    int GetID();
    string GetName();
    string GetPrimColor();
    string GetSecColor();
    string GetTertColor();
    string GetMaterial();
    string GetStyle();

    void SetName(string name);
    void SetPrimColor(string color);
    void SetSecColor(string color);
    void SetTertColor(string color);
    void SetMaterial(string material);
    void SetStyle(string style);

    //bool IsDirty();

    string ToXML() const;
    string ToString() const;
  
  private:
    //Variables
    int id_ = kDummyShoesID;
    string name_ = kDummyShoesName;
    string primary_color_ = kDummyShoesPrimColor;
    string secondary_color_ = kDummyShoesSecColor;
    string tertiary_color_ = kDummyShoesTertColor;
    string material_ = kDummyShoesMaterial;
    string style_ = kDummyShoesStyle;

    //Private Functions


};


#endif /* SHOES_H */ 
