//This replaces the Parser for P2
//It should Repeatedly call scanner()
//print one token per line
//stop when EOFTk is returned

#include <cstdio>
#include <iostream>
#include "testScanner.h"
#include "scanner.h"


void testScanner(FILE* file)
{
    token tk;

    do
    {
        tk = scanner(file);

        if (tk.id == EOF_tk)
        {
            std::cout << tokenNames[tk.id] << std::endl;
        }
        else
        {
            std::cout << tokenNames[tk.id] << " "
                      << tk.instance << " "
                      << tk.line << std::endl;
        }

    } while (tk.id != EOF_tk);
};