#include <stdlib.h>

int main(int /* argc */, char** /* argv */)
{
    const char* command = "./audiowaveform -i ../test/data/test_file_stereo.mp3 -o temp.json -b 8 1>stdout.txt 2>stderr.txt";
    system(command);

    system("hexdump -C stderr.txt");

    return 0;
}
