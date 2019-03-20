#ifndef DEFINE_TYPE_H
#define DEFINE_TYPE_H

/*
 * GlFW
 **/
#define LMN_GLFW_OPENGL_MAJOR 3
#define LMN_GLFW_OPENGL_MINOR 3

/*
 * define func
 */
#ifndef SAFE_FREE
#define SAFE_FREE(x) \
	if (x != NULL) { \
		delete(x);   \
		x = NULL;    \
	}
#endif

//should always inline no matter what
#ifndef _ALWAYS_INLINE_

#if defined(__GNUC__) && (__GNUC__ >= 4)
#define _ALWAYS_INLINE_ __attribute__((always_inline)) inline
#elif defined(__llvm__)
#define _ALWAYS_INLINE_ __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
#define _ALWAYS_INLINE_ __forceinline
#else
#define _ALWAYS_INLINE_ inline
#endif

#endif

//should always inline, except in some cases because it makes debugging harder
#ifndef _FORCE_INLINE_

#ifdef DISABLE_FORCED_INLINE
#define _FORCE_INLINE_ inline
#else
#define _FORCE_INLINE_ _ALWAYS_INLINE_
#endif

#endif

#define TEST_ENGINE

#ifdef TEST_ENGINE
#define PROJ_PATH = "/run/media/vker/041D86B62B1168C1/github/LMN/OpenGL/Engine/"
#else
#define PROJ_PATH = ""
#endif


#endif
