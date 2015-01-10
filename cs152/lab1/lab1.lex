%{
#include <unistd.h>

int num_ints = 0, num_plus = 0, num_minus = 0, num_mult = 0, num_div = 0,
    num_decimals = 0, num_exponents = 0, num_lparen = 0, num_rparen = 0, num_equal = 0,
    num_whitespace = 0;
%}

DIGIT [0-9]
INTEGER {DIGIT}+
DECIMAL {INTEGER}*\.{INTEGER}
EXPONENTIAL ({DECIMAL}|{INTEGER})[Ee][+-]?{INTEGER}

PLUS "+"
MINUS "-"
MULTIPLY "*"
DIVIDE "/"
L_PAREN "("
R_PAREN ")"
EQUAL "="

WHITESPACE [ \n\t]

%%
{EXPONENTIAL} ++num_exponents; printf("Exponential found: "); ECHO; printf("\n");
{DECIMAL} ++num_decimals; printf("Decimal found: "); ECHO; printf("\n");
{INTEGER} ++num_ints; printf("Integer found: "); ECHO; printf("\n");

{PLUS} ++num_plus; printf("Operator found: "); ECHO; printf("\n");
{MINUS} ++num_minus; printf("Operator found: "); ECHO; printf("\n");
{MULTIPLY} ++num_mult; printf("Operator found: "); ECHO; printf("\n");
{DIVIDE} ++num_div; printf("Operator found: "); ECHO; printf("\n");

{L_PAREN} ++num_lparen; printf("Left Parenthesis found: "); ECHO; printf("\n");
{R_PAREN} ++num_rparen; printf("Right Parenthesis found: "); ECHO; printf("\n");

{EQUAL} ++num_equal; printf("Operator found: "); ECHO; printf("\n");
{WHITESPACE} ++num_whitespace;

. printf("Unrecognized token: "); ECHO; printf("\nExiting..\n"); exit(1);
%%

main(int argc, char * argv[])
{

  if(argc != 2)
  {
    printf("Incorrect number of args\n");
    return 1;
  }
  else
  {
    yyin = fopen(argv[1], "r");
  }

  printf("-----------------------------------------------------------------\n");
  printf("Input file: \'%s'\n", argv[1]);
  printf("-----------------------------------------------------------------\n");
  printf("Tokens identified\n");
  printf("-----------------------------------------------------------------\n");
  yylex();
  printf("-----------------------------------------------------------------\n");
  printf("Summary of results\n");
  printf("-----------------------------------------------------------------\n");
  printf("# of ints = %d\n", num_ints);

  printf("Number of + operators = %d\n", num_plus);
  printf("Number of - operators = %d\n", num_minus);
  printf("Number of * operators = %d\n", num_mult);
  printf("Number of / operators = %d\n", num_div);

  printf("Number of Left Parenthesis = %d\n", num_lparen);
  printf("Number of Right Parenthesis = %d\n", num_rparen);

  printf("Number of = operators = %d\n", num_equal);

  printf("Number of whitespace = %d\n", num_whitespace);
}
