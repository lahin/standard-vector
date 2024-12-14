#include "standard_vector.h"
#include <iostream>

int
main ()
{
  standard::standard_vector<int> intContainer (10, 99);
  std::cout << "Container size: " << intContainer.size () << "\n";
#if 0
  for (unsigned i = 0; i < intContainer.size (); ++i)
    {
      std::cout << "Value at i: " << i << " is: " << intContainer.at (i)
                << "\n";
    }
#endif

  // Change even containers to have a value of '98'.
  for (unsigned j = 0; j <= intContainer.size (); ++j)
    {
      if (j % 2 == 0)
        {
          intContainer.at (j) = 98;
        }

      std::cout << "Value at j: " << j << " is: " << intContainer.at (j)
                << "\n";
    }

  return 0;
}
