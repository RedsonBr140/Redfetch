#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  // needed vars
  struct utsname os;
  uname(&os);
  char *user;
  if(getlogin()) {
    user = getlogin();
  } else if(getenv("USER")) {
    user = getenv("USER");
  } else { user = "unknown"; }
  
  char *shell = getenv("SHELL");

  #ifdef __unix__
    char osname[60];
    char wm[25];
    #ifdef __linux__
      
      // Getting the OS
      char line[100];
      int scanned_count = 0;
      FILE* osfile = fopen("/etc/os-release", "r");

      while(!feof(osfile)) {
        fgets(line, 100, osfile);
        scanned_count = sscanf(line,"NAME=\"%[^\"]\"", osname);
        if(scanned_count == 0)
          scanned_count = sscanf(line,"NAME=%s",osname);
        if(scanned_count != 0) 
          break;
  }
  fclose(osfile);
  
  // Getting the WM
  FILE *fp;
  fp = popen("wmctrl -m", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }
 
  fgets(wm, sizeof(wm), fp);
  sscanf(wm, "Name: %s", wm);
  strcat(wm, "\n");
  if(WEXITSTATUS(pclose(fp)) != 0){ strcpy(wm, "unknown\n"); }

    #else
      strcpy(wm, "unknown\n");
      sprintf(osname, "%s %s %s", os.sysname, os.release, os.machine);
    #endif
  #endif

  // Printing.
  printf("            %s@%s\n", user, os.nodename);
  printf("  (\\_/)     os ~ %s\n", osname);
  if(shell !=NULL){
    char *p = strrchr(shell, '/');
    printf("__(. .)__   sh ~ %s\n", p + 1);
  } else { // Fallback
    shell = getusershell();
    char *p = strrchr(shell, '/');
    printf("__(. .)__   sh ~ %s\n", p + 1);
  }
  printf("\\__|_|__/   wm ~ %s", wm);
  printf("   / \\ ");
  printf("     \033[31m● \033[33m● \033[36m● \033[34m●\033[0m\n\n");
}
