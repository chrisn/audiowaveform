#include <iostream>
#include <sstream>
#include <string>

#include "gmock/gmock.h"

using testing::StrEq;

std::ostringstream error;
std::ostream& error_stream = error;

TEST(Test, test)
{
    const char* message = "Test 1\rTest 2\rTest 3\r\n";
    error_stream << message;
    bool same = error.str() == std::string(message);

    std::cout << message << '\n';
    std::cout << same << '\n';

    ASSERT_THAT(error.str(), StrEq(message));
}

#if 0

int main(int /* argc */, char** /* argv */)
{
    return 0;
}

#endif
