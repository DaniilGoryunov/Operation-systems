#include "parent.hpp"

int Parent() {
    std::string filename;
    std::cin >> filename;
    int pipe1_fd[2];
    pipe(pipe1_fd);
    int id = fork();
    if (id < 0){
        perror("fork failed");
        return 1;
    }
    else if(id > 0){
        close(pipe1_fd[0]);

        float num;
        while (std::cin >> num) {
            write(pipe1_fd[1], &num, sizeof(num));
        }

        close(pipe1_fd[1]);
    }
    else{
        close(pipe1_fd[1]);

        if (dup2(pipe1_fd[0], STDIN_FILENO) == -1) {
            perror("dup2 error");
            return 1;
        }

        execl("./child", "./child", filename.c_str(), NULL);

        close(pipe1_fd[0]);
    }
    return 0;
}