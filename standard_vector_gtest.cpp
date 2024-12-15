#include <standard_vector.h>
#include <string>

#include <gtest/gtest.h>

class standard_vector_test : public testing::Test
{
  standard::standard_vector<std::string> strContainer;

public:
  standard_vector_test () {}

  void
  SetUp () override
  {
  }

  void
  TearDown () override
  {
  }
};

// Verify that the empty standard container has zero size.
TEST_F (standard_vector_test, empty_vector_has_size_zero)
{
  standard::standard_vector<std::string> strContainer;
  ASSERT_EQ (0, strContainer.size ());
}
