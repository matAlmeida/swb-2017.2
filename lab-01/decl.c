#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "bits.h"

test_rec test_set[] = {
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
 {"binNOU", (funct_t) binNOU, (funct_t) test_binNOU, 2, "& ~", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"bitsPares", (funct_t) bitsPares, (funct_t) test_bitsPares, 1,
    "! ~ & ^ | + << >>", 12, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"mascaraBit", (funct_t) mascaraBit, (funct_t) test_mascaraBit, 2,
    "! ~ & ^ | + << >>", 16, 3,
  {{0, 31},{0,31},{TMin,TMax}}},
 {"binParidade", (funct_t) binParidade, (funct_t) test_binParidade, 1, "! ~ & ^ | + << >>", 20, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"maiorPosicaoBit", (funct_t) maiorPosicaoBit, (funct_t) test_maiorPosicaoBit, 1, "! ~ & ^ | + << >>", 70, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"cabeShort", (funct_t) cabeShort, (funct_t) test_cabeShort, 1,
    "! ~ & ^ | + << >>", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"sinal", (funct_t) sinal, (funct_t) test_sinal, 1, "! ~ & ^ | + << >>", 10, 2,
     {{-TMax, TMax},{TMin,TMax},{TMin,TMax}}},
 {"diferente", (funct_t) diferente, (funct_t) test_diferente, 2,
    "! ~ & ^ | + << >>", 6, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"negativo", (funct_t) negativo, (funct_t) test_negativo, 1,
    "! ~ & ^ | + << >>", 6, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"respot2", (funct_t) respot2, (funct_t) test_respot2, 2,
    "! ~ & ^ | + << >>", 20, 3,
  {{TMin, TMax},{0,30},{TMin,TMax}}},
 {"menor", (funct_t) menor, (funct_t) test_menor, 2,
    "! ~ & ^ | + << >>", 24, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"cd2ms", (funct_t) cd2ms, (funct_t) test_cd2ms, 1, "! ~ & ^ | + << >>", 15, 4,
  {{TMin+1, TMax},{TMin+1,TMax},{TMin+1,TMax}}},
 {"mod_float", (funct_t) mod_float, (funct_t) test_mod_float, 1,
    "$", 10, 2,
     {{1, 1},{1,1},{1,1}}},
 {"meio_float", (funct_t) meio_float, (funct_t) test_meio_float, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
 {"floatInteiro_float", (funct_t) floatInteiro_float, (funct_t) test_floatInteiro_float, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
  {"", NULL, NULL, 0, "", 0, 0,
   {{0, 0},{0,0},{0,0}}}
};
