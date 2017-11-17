#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "uuid.h"
#include <string>

constexpr int MAX_ITERS = 100;

TEST_CASE("Uuid") {
  for (int i = 0;  i < MAX_ITERS; i++) {
    ids::Uuid uuid;
    std::string uuid_str {uuid.to_str()};
    MESSAGE(uuid_str);
    CHECK(uuid.most > 0);
    CHECK(uuid.least > 0);
    CHECK(uuid_str.size() == 36);
  }
}
SCENARIO("UUID creation") {
  GIVEN("A random UUID ") {
    ids::Uuid uuid;
    std::string uuid_str {uuid.to_str()};
    CHECK(uuid_str.size() == 36);
    WHEN("get the most and least" ) {
      THEN("should be more than 0" ) {
        CHECK(uuid.most > 0);
        CHECK(uuid.least > 0);
      }
    }
  }
}
