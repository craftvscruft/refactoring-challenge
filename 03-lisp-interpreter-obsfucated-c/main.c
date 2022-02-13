#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *
sbrk(), *j();

char* eval(char* input);

int someIndex = 14;
double
atof();

char* readLine();

bool isNotNil(const char *input);

int lengthOfNextExpression(char* in)
{
  int nestingDepth = 0;
  while (isspace(*in)) {
    in++;
  }
  char *marker = in;
  while (nestingDepth != 0 | !(isspace(*marker) | *marker == ')' || (*marker == '(' && marker - in))) {
    if (*marker == '(') {
      nestingDepth++;
    } else if (*marker == ')') {
      nestingDepth--;
    }
    marker++;
  }
  return marker - in;
}
char* getNextExpression(char* in)
{
  // Increment in ptr
  // Get length of next expression
  // Copy next expression somewhere and return it
  in++;
  int exprLength = lengthOfNextExpression(in);
  char *out = __builtin___strncpy_chk(sbrk(199), in, exprLength, __builtin_object_size(sbrk(199), 1));
  out[exprLength] = 0;
  return out;
}
char* trimSpaceAndAddOpenParenMaybe(char *in)
{
  in++;
  in += lengthOfNextExpression(in);
  while (isspace(*in)) {
    in++;
  }
  char *output = sbrk(199);
  *output = '(';
  strcpy(output + 1, in);
  return output;
}
char* Z(char* _)
{
  return _;
}
char* c(char* _)
{
  return getNextExpression(eval(getNextExpression(_)));
}
char* q(char* _)
{
  return trimSpaceAndAddOpenParenMaybe(eval(getNextExpression(_)));
}
char* t(char* _)
{
  char* i = eval(getNextExpression(_));
  char *H = eval(getNextExpression(trimSpaceAndAddOpenParenMaybe(_)));
  char * input = sbrk(199);
  return
         __builtin___sprintf_chk(
             input,
             0,
             __builtin_object_size(input = sbrk(199), 2 > 1 ? 1 : 0),
           !strcmp(H, "()") ? "(%s)" : "(%s %s",
             i,
           H + 1)

           ,
         input;
}
char* somethingAboutIf(char* in)
{
  return eval(getNextExpression(
      trimSpaceAndAddOpenParenMaybe(!strcmp(eval(getNextExpression(in)), "()") ? trimSpaceAndAddOpenParenMaybe(in) : in)));
}
L(char * i, char *s)
{
  return isdigit(*i) ? atof(i) != atof(s) : strcmp(i, s);
}
char* b(char* _)
{
  return L(eval(getNextExpression(_)), eval(getNextExpression(trimSpaceAndAddOpenParenMaybe(_)))) ? "()" : "t";
}
char* R(char* _)
{
  return eval(getNextExpression(_));
}
char* o(char* _)
{
  return atof(eval(getNextExpression(_))) < atof(eval(getNextExpression(trimSpaceAndAddOpenParenMaybe(_)))) ? "t" : "()";
}
char* f(char* _)
{
  char* i;
  return __builtin___sprintf_chk(
           i = sbrk(199),
           0,
           __builtin_object_size(i = sbrk(199), 2 > 1 ? 1 : 0),
           "%lf",
           atof(eval(getNextExpression(_))) + atof(eval(getNextExpression(trimSpaceAndAddOpenParenMaybe(_))))),
         i;
}
char* g(char* _)
{
  char* i;
  return __builtin___sprintf_chk(
           i = sbrk(199),
           0,
           __builtin_object_size(i = sbrk(199), 2 > 1 ? 1 : 0),
           "%lf",
           atof(eval(getNextExpression(_))) - atof(eval(getNextExpression(trimSpaceAndAddOpenParenMaybe(_))))),
         i;
}
char* h(char* _)
{
  char* i;
  return __builtin___sprintf_chk(
           i = sbrk(199),
           0,
           __builtin_object_size(i = sbrk(199), 2 > 1 ? 1 : 0),
           "%lf",
           atof(eval(getNextExpression(_))) * atof(eval(getNextExpression(trimSpaceAndAddOpenParenMaybe(_))))),
         i;
}
char* specialFormHandlers[4][2] = {"function", (char*)R, "quote", (char*)getNextExpression,
                                   "lambda", (char*)Z, "defun", (char*)j };
char* j(char* _)
{
  specialFormHandlers[someIndex][1] = trimSpaceAndAddOpenParenMaybe(_);
  return *specialFormHandlers[someIndex++] = getNextExpression(_);
}
char * not [99][2] = {"if", (char*)somethingAboutIf, "equal", (char*)b, "<",
                      (char*)o, "+", (char*)f, "-", (char*)g,
                      "*", (char*)h, "car", (char*)c, "cdr",
                      (char*)q, "cons", (char*)t, "t", "t" };
char* eval(char* input)
{
  int Li, s;
  bool isSelfEvaluating = isdigit(*input) | !strcmp(input, "()");
  if (isSelfEvaluating) {
    return input;
  }
  for (int Y = someIndex; Y--;) {
    if (!strcmp(input, *specialFormHandlers[Y])) {
      return specialFormHandlers[Y][1];
    }
  }
  char* valueOfNextExpr = eval(getNextExpression(input));
  input = trimSpaceAndAddOpenParenMaybe(input);
  int isNotOpenParen = *valueOfNextExpr - '(';
  if (isNotOpenParen) {
    return (*((char* (*)())valueOfNextExpr))(input);
  }
  s = Li = someIndex;

  while (isNotNil(input)) {
    specialFormHandlers[someIndex][1] = eval(getNextExpression(input));
    *specialFormHandlers[someIndex++] = "";
    input = trimSpaceAndAddOpenParenMaybe(input);
  }
  input = getNextExpression(valueOfNextExpr);
  while (isNotNil(input)) {
    *specialFormHandlers[Li++] = getNextExpression(input);
    input = trimSpaceAndAddOpenParenMaybe(input);
  }
  input = eval(getNextExpression(trimSpaceAndAddOpenParenMaybe(valueOfNextExpr)));
  someIndex = s;
  return input;
}

bool isNotNil(const char *input) { return !!strcmp(input, "()"); }

int main()
{
  // Read Eval Print Loop
  while (1) {
    char * input = readLine();
    char *result = eval(input);
    puts(result);
  }
}

char * readLine() {
  int Y = 0;
  char * input = sbrk(199);
  char *H = input;
  int ch;
  while (Y | !isspace(ch = getchar())) {
    ch == EOF ? exit(0) : 0, Y += (ch == '(') - (ch == ')'), *H++ = ch;
  }
  return input;
}
