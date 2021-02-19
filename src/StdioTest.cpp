#include <iostream>
#include <sstream>
#include <string>

std::ostringstream error_stream;

int main(int /* argc */, char** /* argv */)
{
    const std::string message = "Test 1\rTest 2\rTest 3\r\n";
    error_stream << "Test 1\rTest 2\rTest 3\r\n";
    bool same = error_stream.str() == message;

    std::cout << message << '\n';
    std::cout << same << '\n';

    return 0;
}
