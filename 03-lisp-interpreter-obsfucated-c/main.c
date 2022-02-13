#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *
sbrk(), *j(), *input, *H;

char* eval(char* input);

K, Y, M = 14;
double
atof();

void readLine();

Q(_)
char* _;
{
  int V = 0;
  while (isspace(*_)) {
    _++;
  }
  H = _;
  while (V | !(isspace(*H) | *H == ')' || (*H == '(' && H - _))) {
    V += (*H == '(') - (*H == ')');
    H++;
  }
  return H - _;
}
char* C(char* _)
{
  return _++,
         Y = Q(_),
         _ = __builtin___strncpy_chk(
           sbrk(199), _, Y, __builtin_object_size(sbrk(199), 2 > 1 ? 1 : 0)),
         _[Y] = 0, _;
}
char* A(char *_)
{
  _++, _ += Q(_);
  while (isspace(*_)) {
    _++;
  }
  input = sbrk(199);
  *input = '(', strcpy(input + 1, _);
  return input;
}
char* Z(char* _)
{
  return _;
}
char* c(char* _)
{
  return C(eval(C(_)));
}
char* q(char* _)
{
  return A(eval(C(_)));
}
char* t(char* _)
{
  char* i = eval(C(_));
  return H = eval(C(A(_))),
         __builtin___sprintf_chk(
             input = sbrk(199),
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
  return eval(C(A(!strcmp(eval(C(in)), "()") ? A(in) : in)));
}
L(char * i, char *s)
{
  return isdigit(*i) ? atof(i) != atof(s) : strcmp(i, s);
}
char* b(char* _)
{
  return L(eval(C(_)), eval(C(A(_)))) ? "()" : "t";
}
char* R(char* _)
{
  return eval(C(_));
}
char* o(char* _)
{
  return atof(eval(C(_))) < atof(eval(C(A(_)))) ? "t" : "()";
}
char* f(char* _)
{
  char* i;
  return __builtin___sprintf_chk(
           i = sbrk(199),
           0,
           __builtin_object_size(i = sbrk(199), 2 > 1 ? 1 : 0),
           "%lf",
           atof(eval(C(_))) + atof(eval(C(A(_))))),
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
           atof(eval(C(_))) - atof(eval(C(A(_))))),
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
           atof(eval(C(_))) * atof(eval(C(A(_))))),
         i;
}
char* r[4][2] = { "function", (char*)R, "quote", (char*)C,
                  "lambda",   (char*)Z, "defun", (char*)j };
char* j(char* _)
{
  r[M][1] = A(_);
  return *r[M++] = C(_);
}
char * not [99][2] = {"if", (char*)somethingAboutIf, "equal", (char*)b, "<",
                      (char*)o, "+", (char*)f, "-", (char*)g,
                      "*", (char*)h, "car", (char*)c, "cdr",
                      (char*)q, "cons", (char*)t, "t", "t" };
char* eval(char* input)
{
  int Li, s;
  char* u;
  bool isSelfEvaluating = isdigit(*input) | !strcmp(input, "()");
  if (isSelfEvaluating) {
    return input;
  }
  for (Y = M; Y--;) {
    if (!strcmp(input, *r[Y])) {
      return r[Y][1];
    }
  }
  u = eval(C(input)), input = A(input);
  if (*u - '(') {
    return (*((char* (*)())u))(input);
  }
  s = Li = M;
  while (!!strcmp(input, "()")) {
    r[M][1] = eval(C(input));
    *r[M++] = "";
    input = A(input);
  }
  input = C(u);
  while (!!strcmp(input, "()")) {
    *r[Li++] = C(input), input = A(input);
  }
  input = eval(C(A(u)));
  M = s;
  return input;
}
int main()
{
  // Read Eval Print Loop
  while (1) {
    readLine();
    char *result = eval(input);
    *H = 0;
    puts(result);
  }
}

void readLine() {
  H = input = sbrk(199), Y = 0;
  while (Y | !isspace(K = getchar())) {
    K == EOF ? exit(0) : 0, Y += (K == '(') - (K == ')'), *H++ = K;
  }
}
