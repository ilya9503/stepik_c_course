#include <iostream>
#include <typeinfo>

int main()
{
    auto var_1 {0.5f};	
    auto var_2 {0};	
    auto var_3 {245u};	
    auto var_4 (486L);	
    auto var_5 {4.86L};	
    auto var_6 ('d');
    auto var_7 = (short)-5;

    std::cout << typeid(var_7).name() << std::endl;
    return 0;
}
/*
  <builtin-type> ::= v	# void
		 ::= w	# wchar_t
		 ::= b	# bool
		 ::= c	# char
		 ::= a	# signed char
		 ::= h	# unsigned char
		 ::= s	# short
		 ::= t	# unsigned short
		 ::= i	# int
		 ::= j	# unsigned int
		 ::= l	# long
		 ::= m	# unsigned long
		 ::= x	# long long, __int64
		 ::= y	# unsigned long long, __int64
		 ::= n	# __int128
		 ::= o	# unsigned __int128
		 ::= f	# float
		 ::= d	# double
		 ::= e	# long double, __float80
		 ::= g	# __float128
		 ::= z	# ellipsis
                 ::= Dd # IEEE 754r decimal floating point (64 bits)
                 ::= De # IEEE 754r decimal floating point (128 bits)
                 ::= Df # IEEE 754r decimal floating point (32 bits)
                 ::= Dh # IEEE 754r half-precision floating point (16 bits)
                 ::= DF <number> _ # ISO/IEC TS 18661 binary floating point type _FloatN (N bits), C++23 std::floatN_t
                 ::= DF <number> x # IEEE extended precision formats, C23 _FloatNx (N bits)
                 ::= DF16b # C++23 std::bfloat16_t
                 ::= DB <number> _        # C23 signed _BitInt(N)
                 ::= DB <instantiation-dependent expression> _ # C23 signed _BitInt(N)
                 ::= DU <number> _        # C23 unsigned _BitInt(N)
                 ::= DU <instantiation-dependent expression> _ # C23 unsigned _BitInt(N)
                 ::= Di # char32_t
                 ::= Ds # char16_t
                 ::= Du # char8_t
                 ::= Da # auto
                 ::= Dc # decltype(auto)
                 ::= Dn # std::nullptr_t (i.e., decltype(nullptr))
                 ::= [DS] DA  # N1169 fixed-point [_Sat] T _Accum
                 ::= [DS] DR  # N1169 fixed-point [_Sat] T _Fract
		 ::= u <source-name> [<template-args>] # vendor extended type

  <fixed-point-size>
                 ::= s # short
                 ::= t # unsigned short
                 ::= i # plain
                 ::= j # unsigned
                 ::= l # long
                 ::= m # unsigned long
*/