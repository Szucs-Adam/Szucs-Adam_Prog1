#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector> 

using namespace Graph_lib;

int main()
try {

	Point t1(100 , 100);
	Simple_window win (t1,600,400,"Ch12 Labor");
	win.wait_for_button();

	//01
	Rectangle r{Point{50,50},50,25};
	r.set_color(Color::blue);
	win.attach(r);

	Polygon rect;
	rect.add(Point{125,50});
	rect.add(Point{175,50});
	rect.add(Point{175,75});
	rect.add(Point{125,75});
	rect.set_color(Color::red);
	win.attach(rect);

	win.set_label("Ch12 1.feladat");
	win.wait_for_button();

	//02

	Rectangle rt{Point{200,50},100,30};
	win.attach(rt);
	Text t {Point{200,75},"Howdy!"};
	t.set_font(Font::helvetica_bold);
	t.set_font_size(20);
	win.attach(t);

	win.set_label("2.feladat");
	win.wait_for_button();

	//03
	Text t2 {Point{50,350},"Sz"};
	t2.set_font(Font::courier);
	t2.set_font_size(150);
	Text t3 {Point{250,350},"A"};
	t3.set_font(Font::courier);
	t3.set_font_size(150);

	t2.set_color(Color::black);
	t3.set_color(Color::blue);
	win.attach(t3);
	win.attach(t2);
	win.set_label("3.feladat");
	win.wait_for_button();



	//04

	Vector_ref<Rectangle> vr;
	int w=50;
	for (int row = 0; row < 3; ++row)
	{
	 		for (int col = 0; col < 3; ++col)
	 		{
	 			vr.push_back(new Rectangle{Point{350 + w*col,200+w*row},w,w});
	 			int i = vr.size()-1;
	 			i%2==0
	 				? vr[i].set_fill_color(Color::red)
	 				: vr[i].set_fill_color(Color::white);
	 			win.attach(vr[i]);

	 		}
	}

	win.set_label("4.feladat");
	win.wait_for_button();


	//05

	Rectangle huge{Point{150,150}, x_max()*2/3,y_max()*3/4};
	huge.set_style(Line_style(Line_style::solid,8));
	huge.set_color(Color::red);

	win.attach(huge);
	win.set_label("5.feladat");
	win.wait_for_button();

	//07


	Rectangle Haz_alap{Point{600, 150}, 200, 200};
	win.attach(Haz_alap);
	Haz_alap.set_fill_color(Color::dark_blue);

	Polygon Haz_teto;
	Haz_teto.add(Point{600, 150});
	Haz_teto.add(Point{800, 150});
	Haz_teto.add(Point{700, 0});
	Haz_teto.set_fill_color(Color::red);
	win.attach(Haz_teto);

	Rectangle ajto{Point{675, 275}, 50, 75};
	ajto.set_fill_color(Color::yellow);
	win.attach(ajto);
	Rectangle kilincs{Point{680, 315}, 7,3};
	kilincs.set_fill_color(Color::black);
	win.attach(kilincs);
	Rectangle ablak_1 {Point{625, 200}, 50, 50};
	ablak_1.set_fill_color(Color::white);
	win.attach(ablak_1);
	Rectangle ablak_2 {Point{725, 200}, 50, 50};
	ablak_2.set_fill_color(Color::white);
	win.attach(ablak_2);
	Polygon chimney;
	chimney.add(Point{613,130});
	chimney.add(Point{613,70});
	chimney.add(Point{643,70});
	chimney.add(Point{643,85});
	chimney.set_fill_color(Color::dark_red);
	win.attach(chimney);
	win.set_label("7.feladat");
	win.wait_for_button();


	//08
	Circle c{Point{100,500},50};
	c.set_color(Color::blue);
	c.set_style(Line_style{Line_style::solid,5});
	win.attach(c);
	Circle c2{Point{210,500},50};
	c2.set_color(Color::black);
	c2.set_style(Line_style{Line_style::solid,5});
	win.attach(c2);
	Circle c3{Point{320,500},50};
	c3.set_color(Color::red);
	c3.set_style(Line_style{Line_style::solid,5});
	win.attach(c3);
	Circle c4{Point{155,550},50};
	c4.set_color(Color::yellow);
	c4.set_style(Line_style{Line_style::solid,5});
	win.attach(c4);
	Circle c5{Point{265,550},50};
	c5.set_color(Color::green);
	c5.set_style(Line_style{Line_style::solid,5});
	win.attach(c5);

	win.set_label("8.feladat");
	win.wait_for_button();

	//09 

	
	Image hamster{Point{900,150}, "h.jpg"};
	win.attach(hamster);
	Text h{Point{1020,590},"Picture 1: Hamster"}; // Nem tudom jó értelmeztem e a "Captiont" a 9. feladatban
	h.set_font(Font::courier);
	h.set_font_size(15);
	win.attach(h);
	win.set_label("hamster");
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