#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

void draw(char *rgb_out, int w, int h)
{
        int i = 0;
        for (i = 0;i < w*h;i += 4) {
                rgb_out[i] = i%255;
                rgb_out[i + 1] = i%255;
                rgb_out[i + 2] = i%255;
                rgb_out[i + 3] = i%255;
        }
        return;
}

XImage *create_ximage(Display *display, Visual *visual, int width, int height)
{
        char *image32 = (char *)malloc(width * height * 4);
        draw(image32, width, height);
        return XCreateImage(display, visual, 24,
                            ZPixmap, 0, image32,
                            width, height, 32, 0);
}
int main(int argc, char **argv)
{
        int win_b_color;
        int win_w_color;
        XEvent xev;
        Window window;
        GC gc;
        Display *display = XOpenDisplay(NULL);
        Visual *visual;
        XImage *ximage;
        win_b_color = BlackPixel(display, DefaultScreen(display));
        win_w_color = BlackPixel(display, DefaultScreen(display));
		window = XCreateSimpleWindow(display,
										DefaultRootWindow(display),
										0, 0, 600, 600, 0,
										win_b_color, win_w_color);
				visual = DefaultVisual(display, 0);
				XSelectInput(display, window, ExposureMask | KeyPressMask);
				XMapWindow(display, window);
				XFlush(display);
				gc = XCreateGC(display, window, 0, NULL);
				ximage = create_ximage(display, visual, 600, 800);
				XEvent event;
				bool exit = false;
				while (!exit)
				{
						int r;
						XNextEvent(display, &event);
						if (event.type == Expose)
						{
							r = XPutImage(display, window, gc, ximage, 0, 0, 0, 0,600, 600);
							printf("RES: %i\n", r);
						}
						else if (event.type == KeyPress)
							exit = true;
				}
				return 0;
}


