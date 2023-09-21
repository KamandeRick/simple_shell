#ifndef MAIN_H
#define MAIN_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct builtin_command - takes builtin functions
 * @name: argument 1
 * @function: argument 2
 * Description: Longer description
 */
struct builtin_command
{
	char *name;
	int (*function)(char **tokArray);
};

char *_itoa(size_t cmdNum);
int digCounter(size_t cmdNum);
int error_not_found(char **arvs, char **tokArray, size_t cmdNum);
int yesBuiltin(char **tokArray);
int handleBuiltinFunc(char **tokArray);
int exitFunc(char **tokArray);
int displayEnv(char **tokArray);
int arrayCopy(char **destination, char **source);
int envNameExists(const char *name);
int envLength(void);
void whichFree(char **pathVariable, char **tokArray);
void mainFree(char **tokArray, char *input);
void stringRev(char *str);
int _setenv(const char *name, const char *value, int overwrite);
int unsetEnv(const char *name);
char *charMalloc(char **string, size_t mallocSize, char *error_message);
char **arrayMalloc(char **array, size_t mallocSize, char *error_message);
void prompt(void);
void handleSignalFunc(int signal);
ssize_t lineGet(char **input,
				size_t *mallocBytesAlloc, int status);
char **makeTokArray(char *input, char *delimiter);
int forkFunc(char *command, char **tokArray);
int printEnvFunc(void);
char *envFunc(const char *name);
char *_which(char *filename);
#endif
