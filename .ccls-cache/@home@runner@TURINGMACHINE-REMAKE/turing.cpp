#include<vector>
#include <fstream>
#include "turing.h"
#include <iostream>
#include <sstream>
#include <string>
#include<iterator>

// the default state is 0 and always 0 
Turing_machine::Turing_machine(){
  current_square=0; // the current square still in starting position 
}

//check the tape file 
Turing_machine::Turing_machine(std::string tape_file){
  vector<string> tape_;
  ifstream file("tape.txt");
  while (file >> tape_file){
    tape_.push_back(tape_file);
  }
 getline(file, tape_file); //checking line in tape file 
 cout<< tape_file <<endl;
 file.close();
}


//// moves the read head 1 square left
void Turing_machine::move_left(){
  current_square -=1;
  
}

//moves the read head 1 square right
void Turing_machine::move_right(){
  current_square +=1;
}

// returns true if there is a mark
bool Turing_machine:: read_square() // initialit e the square 
{
  for(int i=0;i<tape_.size();i++){
           if(current_square==tape_[i])
               return true;
       }
       return false;
}

 // marks the current square, if it is not already marked
void Turing_machine::make_mark()
{
if (read_square()==false){
  tape_.push_back(current_square);
}
}

// // if there is a mark on the curren square, remove it
void Turing_machine::remove_mark(){
  if (read_square()==true){
    for(int i=0;tape_.size();i++){
      tape_.erase(tape_.begin()+i);//Removes from the vector either a single element (position) or a range of elements.
      break;
    }
  }
}

//returns a string representation of the tape
std::string Turing_machine::get_tape()
{
  std::stringstream myTape;
  for(int i=0;i < tape_.size();i++){
    myTape << tape_[i];
  }
  std::string myOtherTape= myTape.str();
  return myOtherTape;
  
}
// returns the location of the read head
long Turing_machine::get_current_square()
{
  return current_square;// immdiately return to current_square, which is location 0 in tape 
}

//Model your output for get_tape() and get_current_square() off the output given in the reference solution. 
void Turing_machine::read_tape_file(std::ifstream &file){
  std::string myFile;
  while(file.eof()){
    file>>myFile;
    getline(file, myFile); 
    tape_.push_back(stoi(myFile));
    std::cout<<current_square<<std::endl;
  }
} //read file  and extract file 

void Turing_machine::createTuringMachine(){
  std::cout <<"Tape: [";
  int n = tape_.size();
  for(int i=0;i<n;i++){
           if(i!=n-1)
               std::cout<<tape_[i]<<',';
           else{
               std::cout<<tape_[i];
              }
       }
       std::cout<<" ]"<<std::endl;
       std::cout<<"Current Square :"<< current_square <<std::endl;
}

//update to continue moving and changing
void Turing_machine:: update(){
  if(current_square ==1 && current_square==0 ){
    tape_.push_back(current_square);
    current_square +=1;
    }else
    current_square =2;
  }
  

// run constantly without stopping after the result equal 0 then stop
void Turing_machine::run(){
  while(current_square ==1 && current_square ==2){
     update();
     if(current_square ==0){
       break;
      }
  }

}