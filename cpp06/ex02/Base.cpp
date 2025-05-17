#include "Base.hpp"


Base::Base() {}

Base::Base(const Base &other) { 
  (void)other; 
}

Base &Base::operator=(const Base &other) {
  (void)other;
  return *this;
}

Base::~Base() {}

Base *generate(void) {
	std::srand(static_cast<unsigned int>(std::time(0)));
	int r = std::rand() % 3;
  if (r == 0)
    return new A();
  else if (r == 1)
    return new B();
  else
    return new C();
}

// if else
void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
}

// catch
void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
    return;
  } catch (std::exception &e) {}
  
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;
    return;
  } catch (std::exception &e) {}
  
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;
    return;
  } catch (std::exception &e) {}
}


