// Example code ripped from https://stackoverflow.com/q/45202379
// For personal reference only!  Added commentary to try to understand what it's doing.

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

void my_popen(const string &cmd, vector<string> &out)
{
    // fp will contain the unformatted stdout?
    FILE *fp;
    const int sizebuf = 1234;
    // buff contains the commands?
    char buff[sizebuf];
    // out will contain a vector of strings based on stdout of the first command?
    out = vector<string>();
    // If NULL, then failed?  This also fills fp with stdout of command?
    if ((fp = popen(cmd.c_str(), "r")) == NULL)
    {
    }
    string cur_string = "";
    // This presumably loops through the fp buffer containing stdout of the command, turning it into a string.
    while (fgets(buff, sizeof(buff), fp))
    {
        cur_string += buff;
    }
    // This presumably converts the string into a vector string:
    out.push_back(cur_string.substr(0, cur_string.size() - 1));
    pclose(fp);
}

int main()
{
    // Output should contain formatted strings of the stdout of the given command:
    vector<string> output;
    my_popen("which driftnet", output);
    // This presumably converts the string into multiple strings?
    for (vector<string>::iterator itr = output.begin();
         itr != output.end();
         ++itr)
    {
        cout << *itr << endl;
    }
    return 0;
}