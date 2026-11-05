%{
#include "y.tab.h"
%}

%%

[0-9]+                  { return DIGIT; }

[a-zA-Z_][a-zA-Z0-9_]*  { return ID; }

\n                      { return NL; }

[ \t]                   ;

.                       { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}