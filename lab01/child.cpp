#include <fstream>
#include <unistd.h>

int main(int argc, char* argv[]) {
    std::ofstream f(argv[1]);

    float num;
    double sum = 0;
    
    while (read(STDIN_FILENO, &num, sizeof(num)) != 0) {
        sum += num;
    }

    f << sum << '\n';
    f.close();

    return 0;
}