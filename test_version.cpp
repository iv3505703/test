#define BOOST_TEST_MODULE helloworld_test_module

#include "lib.h"

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/old/interface.hpp>

BOOST_AUTO_TEST_SUITE(helloworld_test_suite)

BOOST_AUTO_TEST_CASE(helloworld_test_version)
{
    BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_SUITE(helloworld_test_suite)

BOOST_AUTO_TEST_CASE(Equal) {
  const float
      d = 0.0001, dd = 0.00001,
      a = 3, b = a + d - dd;
  BOOST_REQUIRE(compare_nsp::is_close(a, b, d));
}

BOOST_AUTO_TEST_CASE(NotEqual) {
  const float
      d = 0.0001, dd = 0.00001,
      a = 3, b = a + d + dd;
  BOOST_REQUIRE_EQUAL(compare_nsp::is_close(a, b, d), false);
}

BOOST_AUTO_TEST_SUITE_END()
