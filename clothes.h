/******************************************************************************
 * File Name: shirt.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary: Header File for 'Shirt' class in the Closet++ program
 *
 */


#ifndef CLOTHES_H
#define CLOTHES_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

static const int kDummyID = -1;
static const string kDummyName = "Fake Name";
static const string kDummyPrimColor = "Fake Primary Color";
static const string kDummySecColor = "Fake Secondary Color";
static const string kDummyTertColor = "Fake Tertiary Color";
static const string kDummyPattern = "Fake Pattern";
static const string kDummyMaterial = "Fake Material";
static const string kDummyStyle = "Fake Style";
static const string kDummyLength = "Fake Length";
static const string kDummyCut = "Fake Cut";
static const string kDummySleeveLength = "Fake Sleeve Length";
static const string kDummyCollar = "Fake Collar";

class Clothes {
  public:
    //Constructors and Deconstructors
    Clothes();
    virtual ~Clothes();

    //General Functions
    int GetID() { return id_; }
    string GetName() { return name_; }
    string GetPrimColor() { return primary_color_; }
    string GetSecColor() { return secondary_color_; }
    string GetTertColor() { return tertiary_color_; }
    string GetPattern() {return pattern_; }

    void SetName(string name) { name_ = name; }
    void SetPrimColor(string color) { primary_color_ = color; }
    void SetSecColor(string color) { secondary_color_ = color; }
    void SetTertColor(string color) { tertiary_color_ = color; }
    void SetPattern(string pattern) { pattern_ = pattern; }

    //bool IsDirty();

    virtual string ToString() const = 0;

  protected:
    string name_ = kDummyName;
    string primary_color_ = kDummyPrimColor;
    string secondary_color_ = kDummySecColor;
    string tertiary_color_ = kDummyTertColor;
    string pattern_ = kDummyPattern;
    int id_ = kDummyID;

};


#endif /* CLOTHES_H */ 
