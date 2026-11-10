
%{
#include "y.tab.h"
#include <stdlib.h>

extern int yylval;
%}

%%

[0-9]+                  {
                         yylval = atoi(yytext);
                         return DIGIT;
                        }

[a-zA-Z_][a-zA-Z0-9_]*  { return ID; }

\n                      { return NL; }

[ \t]                    ;

.                       { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}
