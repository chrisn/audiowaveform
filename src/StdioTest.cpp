#include <iostream>
#include <sstream>
#include <string>

#include "gmock/gmock.h"

using testing::StrEq;

std::ostringstream error_stream;

TEST(Test, test)
{
    const char* message = "Test 1\rTest 2\rTest 3\r\n";
    error_stream << "Test 1\rTest 2\rTest 3\r\n";
    bool same = error_stream.str() == std::string(message);

    std::cout << message << '\n';
    std::cout << same << '\n';

    ASSERT_THAT(error_stream.str(), StrEq(message));
}

#if 0

int main(int /* argc */, char** /* argv */)
{
    return 0;
}

#endif
