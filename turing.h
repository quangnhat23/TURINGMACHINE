//Turing_machine.h

#pragma once
#include<vector>
#include<string>
#include<iostream>
#include <fstream>
#include <sstream>

using namespace std;
class Turing_machine{
  private:
  int current_square;
  // tape 
  std::vector<int> tape_={-10, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3};

  public: 
  Turing_machine();
  Turing_machine( string tape_file );
  void move_left();
  void move_right();
  bool read_square();
  void make_mark();
  void remove_mark();
  long get_current_square();
  std::string get_tape();
  void read_tape_file(std::ifstream &file);
  void createTuringMachine();
  void update();
  void run(); 
 
};
