Project 1 ReadMe.txt
Adrien Abbey (abbey.12@wright.edu)
CEG-4350-01
Oct. 2023

Files:
    total 144
    -rw-r--r-- 1 adrienabbey adrienabbey   754 Oct  1 18:25 Makefile
    -rw-r--r-- 1 adrienabbey adrienabbey  1615 Oct  1 17:58 ReadMe.txt
    -rw-r--r-- 1 adrienabbey adrienabbey  1456 Sep 23 12:28 answers.txt
    -rw-r--r-- 1 adrienabbey adrienabbey  2958 Sep 23 12:28 bitvector.cpp
    -rw-r--r-- 1 adrienabbey adrienabbey 30752 Sep 23 12:28 cmdsTried.txt
    -rw-r--r-- 1 adrienabbey adrienabbey  5436 Sep 23 12:28 directory.cpp
    -rw-r--r-- 1 adrienabbey adrienabbey   174 Sep 23 12:28 diskParams.dat
    -rw-r--r-- 1 adrienabbey adrienabbey  4237 Sep 23 12:28 file.cpp
    -rw-r--r-- 1 adrienabbey adrienabbey     0 Oct  6 13:41 files.txt
    -rw-r--r-- 1 adrienabbey adrienabbey  6975 Sep 23 12:28 fs33types.hpp
    -rw-r--r-- 1 adrienabbey adrienabbey  7228 Oct  6 13:40 gdbSession.txt
    -rw-r--r-- 1 adrienabbey adrienabbey  7595 Sep 23 12:28 inodes.cpp
    -rw-r--r-- 1 adrienabbey adrienabbey  3644 Sep 23 12:28 mount.cpp
    -rw-r--r-- 1 adrienabbey adrienabbey 19516 Oct  6 13:25 shell.cpp
    -rw-r--r-- 1 adrienabbey adrienabbey  3832 Sep 23 12:28 simdisk.cpp
    -rw-r--r-- 1 adrienabbey adrienabbey    97 Sep 23 12:28 stdTestScriptP1.txt
    -rw-r--r-- 1 adrienabbey adrienabbey   280 Oct  1 20:04 testscript.txt
    -rw-r--r-- 1 adrienabbey adrienabbey  2718 Sep 23 12:28 typescript
    -rw-r--r-- 1 adrienabbey adrienabbey   111 Sep 23 12:28 user.cpp
    -rw-r--r-- 1 adrienabbey adrienabbey  6905 Sep 23 12:28 volume.cpp


[ Explanation of Project Implementation ]
In order to implement Project 1, I built ontop of the provided `P0` files.  To 
do this, I wrote several functions (just above `main` in `shell.cpp`), with 
some minor changes to the `main` function required to enable this.

My changes to `main` involve moving the parsing of the given command `buf` to 
a new `parseCommands` function (with additions for the new project 
requirements), and copying the code that executes local commands to the new 
function `doCommand` (enabling reuse of this code).

I then wrote new functions to detect and handle redirects (`checkRedirect`, 
`getRedirectFile` and `doRedirect`), pipes (`checkPipe`, `splitPipeString` and 
`doPipe`), and sleeps (`checkSleep` and `doSleep`).  These are largely self-
descriptive by their function names, and can sometimes call on each other (as 
appropriate).

[ Highlights and Possible Problems ]
While I ran into several problems with my initial efforts, I feel like I've 
largely landed where I needed to be with this code, although I don't doubt 
there will be some edge cases and small bugs I failed to catch.  My primary 
concerns about potential problems stem from possible misinterpretation of the 
instructions (ex: I interpreted piping to always treat the second command as a 
host command), edge cases with how I parse commands (conditions I might have 
missed), and bugs stemming from a lack of understanding (most of my problems 
stem from having very limited understanding of streams), etc.