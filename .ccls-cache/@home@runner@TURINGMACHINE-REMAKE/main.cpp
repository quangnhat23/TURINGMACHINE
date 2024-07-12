#include <iostream>
#include "turing.h"

int main() {
  Turing_machine turing;
  turing.make_mark();
  turing.move_right();
  turing.make_mark();
  turing.move_left();
  turing.move_right();
  turing.move_left();
  turing.move_right();
  turing.move_right();
  turing.make_mark();
  turing.get_tape();
  turing.createTuringMachine();
  turing.update();
  
  return 0;
} 