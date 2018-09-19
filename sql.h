/**
 * @class SQL
 * @author Stephen M. Reaves
 * @headerfile sql.h
 * @date Sep 18, 2018
 */

#include <sqlite3.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio>
#include <string>
#include "backend.h"

using namespace std;

#ifndef SQL_H
#define SQL_H

class SQL : public Backend {
 public:
  // Constructors and Destructors
  SQL();
  virtual ~SQL();
  bool Init();
  void Die();
  bool Store(string file = kDummyFileName) const { return true; };
  bool Open(string file = kDummyFileName) const { return true; };
  void MakeCloset(){};
  string GetClosetName();
  string ToString() const;

  // Inserts for each type of clothing
  // @todo Refactor?
  bool InsertShirt(string name, string primary_color, string secondary_color,
                   string tertiary_color, string pattern, string sleeve_length,
                   string collar);
  bool InsertPants(string name, string primary_color, string secondary_color,
                   string tertiary_color, string material, string length,
                   string cut);
  bool InsertSocks(string name, string primary_color, string secondary_color,
                   string tertiary_color, string pattern);
  bool InsertShoes(string name, string primary_color, string secondary_color,
                   string tertiary_color, string material, string style);
  bool InsertBelt(string name, string primary_color, string secondary_color,
                  string tertiary_color, string material, string pattern);
  bool SelectShirt(int id);
  bool SelectAllShirts();

 private:
  // Variables
  string closet_name_ = kDummyClosetName;
  sqlite3 *db;  ///< DB connection
  char *sql;    ///< Prepared SQL statements
  char *zErrMsg = 0;
  int rc;

  // Functions
  int AssignID(string type);
  static int callback(void *data, int argc, char **argv, char **azColName);
};

#endif /* SQL_H */
