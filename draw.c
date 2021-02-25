#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

    int xi, yi, xf, yf, xt, yt;
    if(x0 == x1){
        if(y0 < y1){
            yi = y0; yf = y1;
        }
        else{
            yi = y1; yf = y0;
        }
        xt = x0; yt = yi;

        while(yt != yf){
            plot(s, c, xt, yt);
            yt++;
        }
        return;
    }
    else if(x0 < x1){
        xi = x0; yi = y0;
        xf = x1; yf = y1;
    }
    else{
        xi = x1; yi = y1;
        xf = x0; yf = y0;
    }
    xt = xi, yt = yi;

    int dx = xf - xi, dy = yf - yi;
    int A = dy, B = -dx;
    int d;

    float m = (double) dy / (double) dx;
    if(m > 0 && m < 1){
        //printf("(0,1): %f\n", m);
        d = 2*A + B;

        while(xt != xf){
            plot(s, c, xt, yt);
            if(d > 0){
                d += 2*B;
                yt++;
            }
            d += 2*A;
            xt++;
        }
    }
    else if(m > 1){
        //printf("(1, +inf): %f\n", m);
        d = A + 2*B;

        while(yt != yf){
            plot(s, c, xt, yt);
            if(d < 0){
                d += 2*A;
                xt++;
            }
            d += 2*B;
            yt++;
        }
    }
    else if(m < 0 && m > -1){
        //printf("(-1, 0): %f\n", m);
        d = 2*A - B;

        while(xt != xf){
            plot(s, c, xt, yt);
            if(d < 0){
                d -= 2*B;
                yt--;
            }
            d += 2*A;
            xt++;
        }

    }
    else if(m < -1){
        //printf("(-inf, -1): %f\n", m);
        d = A - 2*B;

        while(yt != yf){
            plot(s, c, xt, yt);
            if(d > 0){
                d += 2*A;
                xt++;
            }
            d -= 2*B;
            yt--;
        }
    }
    else if(m == 0){
        //printf("{0}: %f\n", m);
        while(xt != xf){
            plot(s, c, xt, yt);
            xt++;
        }
    }
    else if(m == 1){
        //printf("{1}: %f\n", m);
        while(xt != xf){
            plot(s, c, xt, yt);
            xt++;
            yt++;
        }
    }
    else if(m == -1){
        printf("{-1}: %f\n", m);
        while(xt != xf){
            plot(s, c, xt, yt);
            xt++;
            yt--;
        }
    }

}
