/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` --> 
*/
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

 // functionok 

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x) + slope(x);}

int main()
{
	using namespace Graph_lib;
	Simple_window win {Point{100,100},600,600, "Function Graphs"};

	
	//koordináta rendszer

	Axis x_tg {Axis::x, Point{100,300}, 400, 20, "x axis"};
	x_tg.set_color(Color::red);
	win.attach(x_tg);
	Axis y_tg {Axis::y, Point{300, 500}, 400, 20, "y axis"};
	y_tg.set_color(Color::red);
	win.attach(y_tg);

	constexpr int intervallum_min = -10;
	constexpr int intervallum_max = 11;
	constexpr int num_points = 400;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	const Point orig {300,300};

	// Konstans függvény

	Function fct_one {one, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	win.attach(fct_one);

	//lineáris függvény

	Function fct_slope {slope, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	win.attach(fct_slope);
	Text slope_label {Point{100,385}, "x/2"};
	win.attach(slope_label); 

	// Parabola

	Function fct_square {square, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	win.attach(fct_square);

	// cosinus függvény

	Function fct_cos {cos, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	fct_cos.set_color(Color::blue);
	win.attach(fct_cos);

	//cosinus függvény a "lineáris függvényen"

	Function fct_sloping_cos {sloping_cos, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	win.attach(fct_sloping_cos);
	win.wait_for_button();
}