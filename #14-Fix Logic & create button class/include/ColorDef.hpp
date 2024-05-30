#define Red_COLOR 255,0,0,255
#define Green_COLOR 0,100,0,255
#define DarkGreen_COLOR 1,50,32,255
#define Blue_COLOR 0,0,255,255
#define White_COLOR 255,255,255,255
#define Black_COLOR 0,0,0,255
#define Board_COlOR1 120,120,120,200
#define Board_COlOR2 50,50,50,255

class Color {
public:
	Color(int _r,int _g ,int _b , int _a):r(_r), g(_g), b(_b),a(_a){}
	int r,g,b,a;
};