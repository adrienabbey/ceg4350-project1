Project 1 ReadMe.txt
Adrien Abbey (abbey.12@wright.edu)
CEG-4350-01
Oct. 2023

<`ls -l` goes here>

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