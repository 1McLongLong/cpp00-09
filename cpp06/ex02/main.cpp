#include "Base.hpp"


int	main()
{
  B *b = new B;
  Base *base = dynamic_cast<Base*>(b);
  identify(base);

  Base *base2 = generate();
  identify(base2);

  Base *base3 = generate();
  identify(*base3);

  delete b;
  delete base2;
  delete base3;
  return 0;
}
