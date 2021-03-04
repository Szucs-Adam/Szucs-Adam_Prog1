#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector> 

using namespace Graph_lib;

int main()
try {
	//01
	Point t1(100 , 100);
	Simple_window win (t1,800,800,"My window");
	win.wait_for_button();

	//02


	Axis xa{Axis::x,Point{20,150},560,20,"x axis"};
	win.attach(xa);

	Axis ya {Axis::y, Point{310,300}, 560, 20, "y axis"};
	ya.set_color(Color::red); 
	ya.label.set_color(Color::dark_red); 
	win.attach(ya);
	
	Function sine {sin,0,100,Point{20,150},280,25,25}; 
	win.attach(sine);
	sine.set_color(Color::white);
	sine.set_style(Line_style{Line_style::solid,5}); 
	
	Polygon poly;
		poly.add(Point{310,150}); 
	poly.add(Point{410,150});
	poly.add(Point{360,50});
	poly.set_color(Color::black);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	
	Rectangle r {Point{310,150}, 100, 100}; 
	r.set_fill_color(Color::yellow);
	win.attach(r);
	
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,500});
	poly_rect.add(Point{300,500});
	poly_rect.add(Point{300,550});
	poly_rect.add(Point{100,550});
	poly_rect.add(Point{50,525});
	poly_rect.set_style(Line_style(Line_style::dash,5)); 
	poly_rect.set_fill_color(Color::green);
	win.attach(poly_rect);
	
	Text t {Point{10,30}, "Szia, Grafikus Vilag!"};
	t.set_font(Font::times_bold);
	t.set_font_size(30);
	win.attach(t);
	win.set_label("Drill 2.Feladat");
	win.wait_for_button();
	
	Image ii {Point{100,50},"h.jpg"}; 
	win.attach(ii);
	win.set_label("Drill 2.Feladat_Picture");
	win.wait_for_button();
	ii.move(294,339);
	win.set_label("Drill 2.Feladat_Picture");
	win.wait_for_button();
	
	Circle c {Point{100,200},50};
	

	
	c.set_color(Color::dark_red);
	
	Mark m {Point{100,200},'x'};


	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	 << "; window size: " << win.x_max() << "*" <<win.y_max();
	Text sizes {Point{0,700},oss.str()};

	win.attach(c);
	win.attach(m);
	
	win.attach(sizes);

	win.set_label("Drill 2.Feladat_Circle");
	win.wait_for_button();


}
catch(exception& e){
	cerr <<"exception"<< e.what() <<'\n';
	return 1;
}
catch(...)
{
	cerr<<"error\n";
	return 2;
}
