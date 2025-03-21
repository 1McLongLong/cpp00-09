#include "Base.hpp"


int	main()
{
  B *b = new B;
  Base * base = dynamic_cast<Base*>(b);
  identify(base);

  Base * base2 = dynamic_cast<Base*>(generate());
  identify(base2);

  Base * base3 =dynamic_cast<Base*>(generate());
  identify(*base3);

}
