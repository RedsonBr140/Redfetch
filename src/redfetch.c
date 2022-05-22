#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	// needed vars
	struct utsname os; 
	uname(&os); 
	char *user = getlogin();
	if(!user) {user = "uknown";}
	char *shell = getusershell(); 
	char *p = strrchr(shell, '/'); 
	// Getting the OS
	char line[60];
	FILE* osfile = fopen("/etc/os-release", "r"); 
	fgets(line, 60, osfile); 
	if(strstr(line, "PRETTY_NAME")) {
		strcpy(line, line + 13);
		strtok(line, "\"");
	} else {
		strcpy(line, line + 6); // Removing NAME="
		strtok(line, "\""); // Removing the last quote
	}
	fclose(osfile); 

	// Getting the WM
	FILE *fp;
	char path[25];

	fp = popen("wmctrl -m | awk ' /Name/ {print $2}'", "r");
	if (fp == NULL) {
		printf("Failed to run command\n" );
		exit(1);
	}
	fgets(path, sizeof(path), fp);
	pclose(fp);
	// Printing.
	printf("            %s@%s\n", user, os.nodename);
	printf("  (\\_/)     os ~ %s\n", line);
	if(p && *(p++)) { printf("__(. .)__   sh ~ %s\n", p++); } else 
		printf("__(. .)__   \n");
	printf("\\__|_|__/   wm ~ %s", path);
	printf("   / \\ ");
	printf("     \033[31m● \033[33m● \033[36m● \033[34m●\033[0m\n\n");
	}
