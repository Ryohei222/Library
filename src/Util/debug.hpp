#pragma once

/**
 * @brief Debug
 */

#ifdef LOCAL
#define debug_assert(exp) assert(exp)
#else
#define debug_assert(exp) true
#endif

#ifdef LOCAL
#define dbg(x) std::cerr << __LINE__ << " : " << #x << " = " << (x) << std::endl
#else
#define dbg(x) true
#endif