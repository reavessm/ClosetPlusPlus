/**************************************************************************//**
 * @class Clothes
 * @author Stephen M. Reaves
 * @date July 14th, 2018
 *
 * @brief Clothes abstract class to be used by members of closet.
 *        Handles the light work.
 *
 * @detail These global variables are set for all clothes, but not all
 *         clothes use them.  For instance, pants will never need a 'collar'
 *         variable, but they do to make inheritence easier
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
    Clothes(){};
    virtual ~Clothes(){}

    //General Functions
    int GetID() { return id_; }
  /*  string GetName() { return name_; }
    string GetPrimColor() { return primary_color_; }
    string GetSecColor() { return secondary_color_; }
    string GetTertColor() { return tertiary_color_; }
    string GetPattern() { return pattern_; }
    string GetMaterial() { return material_; }
    string GetStyle() { return style_; }
    string GetLength() { return length_; }
    string GetCut() { return cut_; }
    string GetSleeveLength() { return sleeve_length_; }
    string GetCollar() { return collar_; }

    void SetName(string name) { name_ = name; }
    void SetPrimColor(string color) { primary_color_ = color; }
    void SetSecColor(string color) { secondary_color_ = color; }
    void SetTertColor(string color) { tertiary_color_ = color; }
    void SetPattern(string pattern) { pattern_ = pattern; }
    void SetMatterial(string material) { material_ = material; }
    void SetStyle(string style) { style_ = style; }
    void SetLength(string length) { length_ = length; }
    void SetCut(string cut) { cut_ = cut; }
    void SetSleeveLength(string length) { sleeve_length_ = length; }
    void SetCollar(string collar) { collar_ = collar; }
    */

    /*
    string ParmName(string name = name_) { name_ = name; return name; }
    string ParmPrimColor(string color = primary_color_) { primary_color_ = color; return color; }
    string ParmSecColor(string color = secondary_color_) { secondary_color_ = color; return color; }
    string ParmTertColor(string color = tertiary_color_) { tertiary_color_ = color; return color; }
    string ParmPattern(string pattern = pattern_) { pattern_ = pattern; return pattern; }
    string ParmMaterial(string material = material_) { material_ = material; return material; }
    string ParmStyle(string style = style_) { style_ = style; return style; }
    string ParmLength(string length = length_) { length_ = length; return length; }
    string ParmCut(string cut = cut_) { cut_ = cut; return cut; }
    string ParmSleeveLength(string length = length_) { length_ = length; return length; }
    string ParmCollar(string collar = collar_) { collar_ = collar; return collar; }
    */
 
    virtual string ToString() const = 0; ///< This is what makes this a purely
                                         ///< abstract class. The implementation
                                         ///< of these will be changed from one 
                                         ///< article of clothing to the next. 

  protected:
    int    id_              = kDummyID; ///< Global unique identifier
    string name_            = kDummyName; ///< User readable name
    string primary_color_   = kDummyPrimColor; ///< Primary color
    string secondary_color_ = kDummySecColor; ///< Secondary color
    string tertiary_color_  = kDummyTertColor; ///< Tertiary color
    string pattern_         = kDummyPattern; ///< Design pattern
    string material_        = kDummyMaterial; ///< Material
    string style_           = kDummyStyle; ///< Design style
    string length_          = kDummyLength; ///< Length of the clothing
    string cut_             = kDummyCut; ///< Cut of the clothing
    string sleeve_length_   = kDummySleeveLength; ///< Length of the sleeve
    string collar_          = kDummyCollar; ///< Type of collar

};


#endif /* CLOTHES_H */ 
