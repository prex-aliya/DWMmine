#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/Xutil.h>

//#define VERSION "1.1"

/* variables */
static Display *dpy;



void die(const char *fmt, ...) {
  va_list arg; // establish a list marker

  va_start(arg, fmt);
  vfprintf(stderr, fmt, arg); // using elemeents in cariable argument
                              // identify by arg
  va_end(arg);

  if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
    fputc(' ', stderr);
    perror(NULL); // gives interpreted value of errno
  } else
    fputc('\n', stderr);

  exit(1);
}

void setup(void) {

}

int main(int argc, char *argv[]) {
	if (argc == 2 && !strcmp("-v", argv[1]))
		die("miwm-"VERSION);
	else if (argc != 1)
		die("usage: miwm [-v]");

  if (!(dpy = XOpendisplay(NULL)))
    die("wiwm: cannot open display");

  setup();

  return EXIT_SUCCESS;
}
