/**
 * @class SQL
 * @author Stephen M. Reaves
 * @file sql.cc
 * @date Sep 17, 2018
 * @brief This class stores clothes using a sqlite3 interface
 * @todo Put table names in a variable. sql.h/label.h?
 */

#include "sql.h"

using namespace std;

string SQL::myResults = "";

/**
 * Default Constructor
 */
SQL::SQL() {}

/**
 * Deconstructor
 */
SQL::~SQL() {}

/**
 * Init
 * @brief Sets closet name then calls Init()
 * @param name String representing closet name
 * @returns Boolean representing success (or failure) of Init
 */
bool SQL::Init(string name) {
  this->closet_name_ = name;
  return this->Init();
}

/**
 * Init
 * @brief Creates the tables
 * @returns Boolean representing success (or failure) of initialization
 */
bool SQL::Init() {
  bool isInit = false;

  // Create a connection to the db
  closet_name_ += ".db";
  std::cout << closet_name_ << std::endl;
  rc = sqlite3_open(closet_name_.c_str(), &db);

  // Check if connection failed
  if (!rc) {
    isInit = true;
  }

  // Create Shirt Table
  sql = "CREATE TABLE IF NOT EXISTS Shirts(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "PATTERN         TEXT  NOT NULL,";
  sql += "SLEEVE_LENGTH   TEXT  NOT NULL,";
  sql += "COLLAR          TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // Create Pants Table
  sql = "CREATE TABLE IF NOT EXISTS Pants(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "MATERIAL        TEXT  NOT NULL,";
  sql += "LENGTH          TEXT  NOT NULL,";
  sql += "STYLE           TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // Create Socks Table
  sql = "CREATE TABLE IF NOT EXISTS Socks(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "PATTERN         TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // Create Shoes Table
  sql = "CREATE TABLE IF NOT EXISTS Shoes(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "MATERIAL        TEXT  NOT NULL,";
  sql += "STYLE           TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // Create Belt Table
  sql = "CREATE TABLE IF NOT EXISTS Belts(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "MATERIAL        TEXT  NOT NULL,";
  sql += "PATTERN         TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // could `return exec1 || exec2 || ..`
  return isInit;
}

/**
 * Die
 * @brief Saves and kills the connection to the database
 */
void SQL::Die() { sqlite3_close(db); }

/**
 * Callback
 * @brief Buffer to replay Select statements
 */
int SQL::Callback(void *unused, int count, char **data, char **columns) {
  for (int i = 0; i < count; ++i) {
    myResults += to_string(*columns[i]) + '\t' + to_string(*data[i]);
  }
  myResults += '\n';
  return 0;
}

/**
 * InsertShirt
 * @brief Inserts shirt into 'Shirts' table using params
 *
 * @param name String for name of the shirt
 * @param primary_color String for the primary color of shirt
 * @param secondary_color String for the secondary color of shirt
 * @param tertiary_color String for the 3rd color of shirt
 * @param pattern String for the pattern of the shirt
 * @param sleeve_length String for the length of sleeves. 'Short', 'Long',
 *        'Tank', etc, NOT numeric.
 * @param collar String for type of collar
 *
 * @returns Boolean for success (or failure) or insert
 */
bool SQL::InsertShirt(string name, string primary_color, string secondary_color,
                      string tertiary_color, string pattern,
                      string sleeve_length, string collar) {
  bool isSuccessful = false;

  // Get ID
  int id = this->AssignID("shirt");

  // Prepare Insert statement
  sql = "INSERT INTO Shirts VALUES (";
  sql += to_string(id);
  sql += ",'" + name + "',";
  sql += "'" + primary_color + "',";
  sql += "'" + secondary_color + "',";
  sql += "'" + tertiary_color + "',";
  sql += "'" + pattern + "',";
  sql += "'" + sleeve_length + "',";
  sql += "'" + collar + "');";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    num_of_shirts_++;
    isSuccessful = true;
  }

  return isSuccessful;
}

/**
 * InsertPants
 * @brief Inserts pants into 'Pants' table using params
 *
 * @param name String for name of the pants
 * @param primary_color String for the primary color of pants
 * @param secondary_color String for the secondary color of pants
 * @param tertiary_color String for the 3rd color of pants
 * @param material String for the material of the pants
 * @param length String for the length of pants. 'Short', 'Long', etc,
 *        NOT numeric.
 * @param cut String for type of cut
 *
 * @returns Boolean for success (or failure) or insert
 */
bool SQL::InsertPants(string name, string primary_color, string secondary_color,
                      string tertiary_color, string material, string length,
                      string cut) {
  bool isSuccessful = false;

  // Get ID
  int id = this->AssignID("pants");

  // Prepare Insert Statement
  sql = "INSERT INTO Pants VALUES(";
  sql += to_string(id);
  sql += ",'" + name + "'";
  sql += "'" + primary_color + "'";
  sql += "'" + secondary_color + "'";
  sql += "'" + tertiary_color + "'";
  sql += "'" + material + "'";
  sql += "'" + length + "'";
  sql += "'" + cut + "');";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    num_of_pants_++;
    isSuccessful = true;
  }

  return isSuccessful;
}

/**
 * InsertSocks
 * @brief Inserts socks into 'Socks' table using params
 *
 * @param name String for name of the socks
 * @param primary_color String for the primary color of socks
 * @param secondary_color String for the secondary color of socks
 * @param tertiary_color String for the 3rd color of socks
 * @param pattern String for pattern of socks
 *
 * @returns Boolean for success (or failure) or insert
 */
bool SQL::InsertSocks(string name, string primary_color, string secondary_color,
                      string tertiary_color, string pattern) {
  bool isSuccessful = false;

  // Get ID
  int id = this->AssignID("socks");

  // Prepare Insert Statement
  sql = "INSERT INTO Socks VALUES(";
  sql += to_string(id);
  sql += ",'" + name + "'";
  sql += "'" + primary_color + "'";
  sql += "'" + secondary_color + "'";
  sql += "'" + tertiary_color + "'";
  sql += "'" + pattern + "');";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    num_of_socks_++;
    isSuccessful = true;
  }

  return isSuccessful;
}

/**
 * InsertShoes
 * @brief Inserts shoes into 'Shoes' table using params
 *
 * @param name String for name of the shoes
 * @param primary_color String for the primary color of shoes
 * @param secondary_color String for the secondary color of shoes
 * @param tertiary_color String for the 3rd color of shoes
 * @param material String for the material of the shoes
 * @param style String for style of shoes
 *
 * @returns Boolean for success (or failure) or insert
 */
bool SQL::InsertShoes(string name, string primary_color, string secondary_color,
                      string tertiary_color, string material, string style) {
  bool isSuccessful = false;

  // Get ID
  int id = this->AssignID("shoes");

  // Prepare Insert Statement
  sql = "INSERT INTO Shoes VALUES(";
  sql += to_string(id);
  sql += ",'" + name + "'";
  sql += "'" + primary_color + "'";
  sql += "'" + secondary_color + "'";
  sql += "'" + tertiary_color + "'";
  sql += "'" + material + "'";
  sql += "'" + style + "');";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    num_of_shoes_++;
    isSuccessful = true;
  }

  return isSuccessful;
}

/**
 * InsertBelt
 * @brief Inserts belts into 'Belts' table using params
 *
 * @param name String for name of the belts
 * @param primary_color String for the primary color of belts
 * @param secondary_color String for the secondary color of belts
 * @param tertiary_color String for the 3rd color of belts
 * @param material String for the material of the belts
 * @param pattern String for pattern of belts
 *
 * @returns Boolean for success (or failure) or insert
 */
bool SQL::InsertBelt(string name, string primary_color, string secondary_color,
                     string tertiary_color, string material, string pattern) {
  bool isSuccessful = false;

  // Get ID
  int id = this->AssignID("belt");

  // Prepare Insert Statement
  sql = "INSERT INTO Belt VALUES(";
  sql += to_string(id);
  sql += ",'" + name + "'";
  sql += "'" + primary_color + "'";
  sql += "'" + secondary_color + "'";
  sql += "'" + tertiary_color + "'";
  sql += "'" + material + "'";
  sql += "'" + pattern + "');";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    num_of_belts_++;
    isSuccessful = true;
  }

  return isSuccessful;
}

/**
 * SelectShirt
 */
string SQL::SelectShirt(int id) {
  // bool isSuccessful = false;

  // Clean result buffer
  myResults = "";

  sql = "SELECT * FROM Shirts WHERE ID == " + to_string(id);

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    // isSuccessful = true;
  }

  return myResults;
}

/**
 * SelectAllShirts
 */
string SQL::SelectAllShirts() {
  // bool isSuccessful = false;

  // Clean result buffer
  myResults = "";

  sql = "SELECT * FROM Shirts";

  // Insert and check for errors
  if (sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    // isSuccessful = true;
  }

  return myResults;
}

/**
 * ToString
 */
string SQL::ToString() { return this->SelectAllShirts(); }
