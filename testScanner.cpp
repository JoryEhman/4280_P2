//This replaces the Parser for P2
//It should Repeatedly call scanner()
//print one token per line
//stop when EOFTk is returned

#include <stdio>
#include "testScanner.h"
#include "scanner.h"


void testScanner(FILE* file){
    token tk;

    do {
        tk = scanner(file);

        std::cout << tokenNames[tk.id] << " " <<
                           tk.instance << " " <<
                           tk.line << std::endl;
    } while (tk.id != EOF_tk);
}