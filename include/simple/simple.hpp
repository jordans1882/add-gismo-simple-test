#ifndef _SIMPLE_HPP_
#define _SIMPLE_HPP_

#include <iostream>
#include <vector>

namespace simple {

class Simple {
   public:
      void hello_world( void );
      Simple();
   private:
      double secret_number;
};

Simple::Simple() { }

void Simple::hello_world() {
       	secret_number = 1.23;
       	std::cout << "Hello World!" << std::endl;
       	std::cout << "The secret number is " << secret_number << '\n';
}

};
#endif
