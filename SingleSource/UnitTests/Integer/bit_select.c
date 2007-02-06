//===--- bit_select.c --- Test The bit_select builtin ---------------------===//
//
// This file was developed by Reid Spencer and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This test case tests the __builtin_bit_select builtin function llvm-gcc.
// bit_select selects one bit out of a larger 
//
//===----------------------------------------------------------------------===//

#include <stdio.h>

#ifdef ENABLE_LARGE_INTEGERS
typedef int __attribute__((bitwidth(250))) BitType;
const BitType X = 0xAAAAAAAAULL;
int numbits = 250;
#else
typedef int __attribute__((bitwidth(47))) BitType;
const BitType X = 0xAAAAAAAAULL;
int numbits = 47;
#endif

int main(int argc, char** argv)
{

#ifdef ENABLE_LARGE_INTEGERS
  BitType Y = X * X;
#else
  BitType Y = X;
#endif

  int i;

  for (i = numbits-1; i >= 0; --i) {
    if (__builtin_bit_select(Y, i)) 
      printf("1");
    else
      printf("0");
  }

  printf("\n");
  return 0;
}
