#ifndef KONG_MACRO_H
#define KONG_MACRO_H

#include <string.h>
#include <assert.h>
#include "Log.h"
#include "Util.h"

#if defined __GNUC__ || defined __llvm__
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率成立
#   define KONG_LIKELY(x)       __builtin_expect(!!(x), 1)
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率不成立
#   define KONG_UNLIKELY(x)     __builtin_expect(!!(x), 0)
#else
#   define KONG_LIKELY(x)      (x)
#   define KONG_UNLIKELY(x)      (x)
#endif

/// 断言宏封装
#define KONG_ASSERT(x) \
    if(KONG_UNLIKELY(!(x))) { \
        KONG_LOG_ERROR(KONG_LOG_ROOT()) << "ASSERTION: " #x \
            << "\nbacktrace:\n" \
            << kong::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }

/// 断言宏封装
#define KONG_ASSERT2(x, w) \
    if(KONG_UNLIKELY(!(x))) { \
        KONG_LOG_ERROR(KONG_LOG_ROOT()) << "ASSERTION: " #x \
            << "\n" << w \
            << "\nbacktrace:\n" \
            << kong::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }

#endif