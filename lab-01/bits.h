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
int binNOU(int, int);
int test_binNOU(int, int);
int bitsPares();
int test_bitsPares();
int mascaraBit(int, int);
int test_mascaraBit(int, int);
int binParidade(int);
int test_binParidade(int);
int maiorPosicaoBit(int);
int test_maiorPosicaoBit(int);
int cabeShort(int);
int test_cabeShort(int);
int sinal(int);
int test_sinal(int);
int diferente(int, int);
int test_diferente(int, int);
int negativo(int);
int test_negativo(int);
int respot2(int, int);
int test_respot2(int, int);
int menor(int, int);
int test_menor(int, int);
int cd2ms(int);
int test_cd2ms(int);
unsigned mod_float(unsigned);
unsigned test_mod_float(unsigned);
unsigned meio_float(unsigned);
unsigned test_meio_float(unsigned);
int floatInteiro_float(unsigned);
int test_floatInteiro_float(unsigned);
