### GH File Get

A basic C program script that takes in 3 arguments, repo owner, repo name, and path to file, all of which are *required*.

The output is the raw contents of the file

You can make an equivalent program in any scripting language like bash or python but I thought this would be a fun little program that uses the system() wrapper
to call the `gh` command to make the api request.

The source code is very simple so a proper build system has be omitted in this repository.

**Examples**

```sh
ghfget Carter907 iolib src/iolib.h
```
This is equivalent to the follow `gh` command: 
```sh
gh api repos/Carter907/iolib/contents/src/iolib.h -H "Accept: application/vnd.github.raw"
```
output:
```
#ifndef IOLIB_H
#define IOLIB_H

char* read_line();
double read_double();
int read_int();

#endif
```

**Building**

Simply use any C compiler and move the binary to your directory of choice that is accessible to your shell.
