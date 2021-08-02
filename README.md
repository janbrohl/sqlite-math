# SQLite-Math

An extension for [SQLite](https://sqlite.org/) providing most functions from [math.h](https://www.cplusplus.com/reference/cmath/) 

There are 2 versions of this extension:
* math1.c containing all functions 
* mathextra1.c containing all functions minus those that might be [built-in](https://sqlite.org/lang_mathfunc.html)

For compiling the extension you need the amalgamation source code from https://sqlite.org/download.html . See https://sqlite.org/loadext.html#compiling_a_loadable_extension .

Not quite tested yet.



