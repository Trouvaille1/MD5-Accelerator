/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int md5_test(void);
signed int md5_wrap(signed int ,  char *,  char *);
signed int main(void);


/* Global Variable Definitions and Initialization */
static  char aesl_internal_md5_test_OC_text2[4] = "abc";
static  char aesl_internal__OC_str2[7] = "FAILED";
static  char aesl_internal_md5_test_OC_hash1[16] = { ((unsigned char )-44), ((unsigned char )29), ((unsigned char )-116), ((unsigned char )-39), ((unsigned char )-113), ((unsigned char )0), ((unsigned char )-78), ((unsigned char )4), ((unsigned char )-23), ((unsigned char )128u), ((unsigned char )9), ((unsigned char )-104), ((unsigned char )-20), ((unsigned char )-8), ((unsigned char )66), ((unsigned char )126) };
static  char aesl_internal_md5_test_OC_hash2[16] = { ((unsigned char )-112), ((unsigned char )1), ((unsigned char )80), ((unsigned char )-104), ((unsigned char )60), ((unsigned char )-46), ((unsigned char )79), ((unsigned char )-80), ((unsigned char )-42), ((unsigned char )-106), ((unsigned char )63), ((unsigned char )125), ((unsigned char )40), ((unsigned char )-31), ((unsigned char )127), ((unsigned char )114) };
static  char aesl_internal_md5_test_OC_hash3[16] = { ((unsigned char )-47), ((unsigned char )116), ((unsigned char )-85), ((unsigned char )-104), ((unsigned char )-46), ((unsigned char )119), ((unsigned char )-39), ((unsigned char )-11), ((unsigned char )-91), ((unsigned char )97), ((unsigned char )28), ((unsigned char )44), ((unsigned char )-97), ((unsigned char )65), ((unsigned char )-99), ((unsigned char )-97) };
static  char aesl_internal_md5_test_OC_text3[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
static  char aesl_internal__OC_str[15] = "MD5 tests: %s\n";
static  char aesl_internal__OC_str1[10] = "SUCCEEDED";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

signed int md5_test(void) {
  static  unsigned long long aesl_llvm_cbe_text1_count = 0;
   char llvm_cbe_text1[1];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_text2_count = 0;
   char llvm_cbe_text2[4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_text3_count = 0;
   char llvm_cbe_text3[63];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_buf_count = 0;
   char llvm_cbe_buf[16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  bool llvm_cbe_tmp__23;
  bool llvm_cbe_tmp__23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @md5_test\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [1 x i8]* %%text1, i64 0, i64 0, !dbg !2 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_2_count);
  llvm_cbe_tmp__1 = ( char *)(&llvm_cbe_text1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memset(i8* %%1, i32 0, i64 1 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_3_count);
  ( char *)memset(( char *)llvm_cbe_tmp__1, 0u, 1ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [4 x i8]* %%text2, i64 0, i64 0, !dbg !3 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_5_count);
  llvm_cbe_tmp__3 = ( char *)(&llvm_cbe_text2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i8* @memcpy(i8* %%3, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_md5_test.text2, i64 0, i64 0), i64 4 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_6_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__3, ( char *)((&aesl_internal_md5_test_OC_text2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), 4ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [63 x i8]* %%text3, i64 0, i64 0, !dbg !4 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__5 = ( char *)(&llvm_cbe_text3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 63
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i8* @memcpy(i8* %%5, i8* getelementptr inbounds ([63 x i8]* @aesl_internal_md5_test.text3, i64 0, i64 0), i64 63 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_9_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__5, ( char *)((&aesl_internal_md5_test_OC_text3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 63
#endif
])), 63ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",63ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call i64 @strlen(i8* %%1) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__7 = (unsigned long long )strlen(( char *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = trunc i64 %%7 to i32, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )llvm_cbe_tmp__7&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [16 x i8]* %%buf, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__9 = ( char *)(&llvm_cbe_buf[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i32 @md5_wrap(i32 %%8, i8* %%1, i8* %%9) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_22_count);
  md5_wrap(llvm_cbe_tmp__8, ( char *)llvm_cbe_tmp__1, ( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__8);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i32 @memcmp(i8* getelementptr inbounds ([16 x i8]* @aesl_internal_md5_test.hash1, i64 0, i64 0), i8* %%9, i64 16) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__11 = (unsigned int )memcmp(( char *)((&aesl_internal_md5_test_OC_hash1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), ( char *)llvm_cbe_tmp__9, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = call i64 @strlen(i8* %%3) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__12 = (unsigned long long )strlen(( char *)llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = trunc i64 %%13 to i32, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )llvm_cbe_tmp__12&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i32 @md5_wrap(i32 %%14, i8* %%3, i8* %%9) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_27_count);
  md5_wrap(llvm_cbe_tmp__13, ( char *)llvm_cbe_tmp__3, ( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__13);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__14);
}
  if (((llvm_cbe_tmp__11&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__25;
  } else {
    goto llvm_cbe__2e_critedge;
  }

llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = call i32 @memcmp(i8* getelementptr inbounds ([16 x i8]* @aesl_internal_md5_test.hash2, i64 0, i64 0), i8* %%9, i64 16) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__15 = (unsigned int )memcmp(( char *)((&aesl_internal_md5_test_OC_hash2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), ( char *)llvm_cbe_tmp__9, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i64 @strlen(i8* %%5) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__16 = (unsigned long long )strlen(( char *)llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__16);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = trunc i64 %%19 to i32, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )llvm_cbe_tmp__16&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call i32 @md5_wrap(i32 %%20, i8* %%5, i8* %%9) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_33_count);
  md5_wrap(llvm_cbe_tmp__17, ( char *)llvm_cbe_tmp__5, ( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__17);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__18);
}
  if (((llvm_cbe_tmp__15&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__26;
  } else {
    llvm_cbe_tmp__23__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe_tmp__27;
  }

llvm_cbe_tmp__26:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call i32 @memcmp(i8* getelementptr inbounds ([16 x i8]* @aesl_internal_md5_test.hash3, i64 0, i64 0), i8* %%9, i64 16) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__19 = (unsigned int )memcmp(( char *)((&aesl_internal_md5_test_OC_hash3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), ( char *)llvm_cbe_tmp__9, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__19);
}
  llvm_cbe_tmp__23__PHI_TEMPORARY = (bool )((llvm_cbe_tmp__19&4294967295U) == (0u&4294967295U));   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe__2e_critedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = call i64 @strlen(i8* %%5) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__20 = (unsigned long long )strlen(( char *)llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = trunc i64 %%25 to i32, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )llvm_cbe_tmp__20&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = call i32 @md5_wrap(i32 %%26, i8* %%5, i8* %%9) nounwind, !dbg !6 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_40_count);
  md5_wrap(llvm_cbe_tmp__21, ( char *)llvm_cbe_tmp__5, ( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__21);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__22);
}
  llvm_cbe_tmp__23__PHI_TEMPORARY = (bool )0;   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__27:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = phi i1 [ false, %%16 ], [ %%24, %%22 ], [ false, %%.critedge  for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__23 = (bool )((llvm_cbe_tmp__23__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__23);
printf("\n = 0x%X",0);
printf("\n = 0x%X",0);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i1 %%29 to i3 for 0x%I64xth hint within @md5_test  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(bool )llvm_cbe_tmp__23&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @md5_test}\n");
  return llvm_cbe_tmp__24;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
   char *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 @md5_test(), !dbg !2 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__28 = (unsigned int ) /*tail*/ md5_test();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = select i1 %%2, i8* getelementptr inbounds ([10 x i8]* @aesl_internal_.str1, i64 0, i64 0), i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str2, i64 0, i64 0), !dbg !2 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__29 = ( char *)((((llvm_cbe_tmp__28&4294967295U) != (0u&4294967295U))) ? (( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]))) : (( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
]))));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([15 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* %%3) nounwind, !dbg !2 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_53_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 15
#endif
])), ( char *)llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

