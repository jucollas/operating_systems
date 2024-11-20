#include "address-register.h"

AR::AR() : content(0) {}

void AR::set(int data){
  this->content = data;
}

int AR::get(){
  return this->content;
}