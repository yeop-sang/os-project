#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char* argv[]) {
  if(argc < 3) {
    printf(2, "usage: ssu_trace <mask> <command ...>");
  }

  int pid = fork();
  trace(atoi(argv[1]));
  if (pid > 0) {
    wait();
    exit();
  }
  else if (pid == 0){
    exec(argv[2], argv + 2);
    exit();
  }
  else {
    printf(2, "fork Fail! \n");
    exit();
  }
}
