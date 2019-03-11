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

#endif
