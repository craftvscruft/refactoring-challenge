#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
sbrk(),
  *S(), *j(), *O, *H;
K, Y, M = 14;
double
atof();
Q(_)
char* _;
{
  int V = 0;
  while (isspace(*_))
    _++;
  H = _;
  while (V | !(isspace(*H) | *H == ')' || (*H == '(' && H - _)))
    V += (*H == '(') - (*H == ')'), H++;
  return H - _;
}
char* C(_) char* _;
{
  return _++,
         Y = Q(_),
         _ = __builtin___strncpy_chk(
           sbrk(199), _, Y, __builtin_object_size(sbrk(199), 2 > 1 ? 1 : 0)),
         _[Y] = 0, _;
}
char* A(_) char* _;
{
  _++, _ += Q(_);
  while (isspace(*_))
    _++;
  return O = sbrk(199), *O = '(', strcpy(O + 1, _), O;
}
char* Z(_) char* _;
{
  return _;
}
char* c(_) char* _;
{
  return C(S(C(_)));
}
char* q(_) char* _;
{
  return A(S(C(_)));
}
char* t(_) char* _;
{
  char* i = S(C(_));
  return H = S(C(A(_))),
         __builtin___sprintf_chk(
           O = sbrk(199),
           0,
           __builtin_object_size(O = sbrk(199), 2 > 1 ? 1 : 0),
           !strcmp(H, "()") ? "(%s)" : "(%s %s",
           i,
           H + 1)

           ,
         O;
}
char* F(_) char* _;
{
  return S(C(A(!strcmp(S(C(_)), "()") ? A(_) : _)));
}
L(i, s)
char *

  i,
  *s;
{
  return isdigit(*i) ? atof(i) != atof(s) : strcmp(i, s);
}
char* b(_) char* _;
{
  return L(S(C(_)), S(C(A(_)))) ? "()" : "t";
}
char* R(_) char* _;
{
  return S(C(_));
}
char* o(_) char* _;
{
  return atof(S(C(_))) < atof(S(C(A(_)))) ? "t" : "()";
}
char* f(_) char* _;
{
  char* i;
  return __builtin___sprintf_chk(
           i = sbrk(199),
           0,
           __builtin_object_size(i = sbrk(199), 2 > 1 ? 1 : 0),
           "%lf",
           atof(S(C(_))) + atof(S(C(A(_))))),
         i;
}
char* g(_) char* _;
{
  char* i;
  return __builtin___sprintf_chk(
           i = sbrk(199),
           0,
           __builtin_object_size(i = sbrk(199), 2 > 1 ? 1 : 0),
           "%lf",
           atof(S(C(_))) - atof(S(C(A(_))))),
         i;
}
char* h(_) char* _;
{
  char* i;
  return __builtin___sprintf_chk(
           i = sbrk(199),
           0,
           __builtin_object_size(i = sbrk(199), 2 > 1 ? 1 : 0),
           "%lf",
           atof(S(C(_))) * atof(S(C(A(_))))),
         i;
}
char* r[4][2] = { "function", (char*)R, "quote", (char*)C,
                  "lambda",   (char*)Z, "defun", (char*)j };
char* j(_) char* _;
{
  return r[M][1] = A(_), *r[M++] = C(_);
}
char * not [99][2] = { "if",     (char*)F, "equal",  (char*)b, "<",
                       (char*)o, "+",      (char*)f, "-",      (char*)g,
                       "*",      (char*)h, "car",    (char*)c, "cdr",
                       (char*)q, "cons",   (char*)t, "t",      "t" };
char* S(_) char* _;
{
  int Li, s;
  char* u;
  if (isdigit(*_) | !strcmp(_, "()"))
    return _;
  for (Y = M; Y--;)
    if (!strcmp(_, *r[Y]))
      return r[Y][1];
  u = S(C(_)), _ = A(_);
  if (*u - '(')
    return (*((char* (*)())u))(_);
  s = Li = M;
  while (!!strcmp(_, "()"))
    r[M][1] = S(C(_)), *r[M++] = "", _ = A(_);
  O = C(u);
  while (!!strcmp(O, "()")) {
    *r[Li++] = C(O), O = A(O);
  }
  return O = S(C(A(u))), M = s, O;
}
main()
{
  H = O = sbrk(199), Y = 0;
  while (Y | !isspace(K = getchar()))
    K == EOF ? exit(0) : 0, Y += (K == '(') - (K == ')'), *H++ = K;
  *H = 0, puts(S(O)), main();
  {
    printf("XLISP 4.0\n");
  }
}
