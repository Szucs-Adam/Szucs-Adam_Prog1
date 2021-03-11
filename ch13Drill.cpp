#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;


int main()
try
{
	Simple_window win{ Point{100,0}, 800, 1000, "Chapter 13 Drills 1-2" };

	const int grid_size= 100;
	const int grid_max= 800;
	Lines grid;
	for (int i = grid_size; i < grid_max; i += grid_size)
	{
		grid.add(Point{ i, 0 }, { Point(i, grid_max) });
		grid.add(Point{ 0, i }, { Point(grid_max, i) });
	}


	win.attach(grid);
	
	// Piros négyzetek

	Vector_ref<Rectangle> red_squares;
	for (int i = 0; i < 8; ++i) // 8*8 sor vége

	{
		red_squares.push_back(new Rectangle(Point{i*grid_size,i*grid_size},grid_size,grid_size));
		red_squares[red_squares.size()-1].set_fill_color(Color::red);
		win.attach(red_squares[red_squares.size()-1]);
	}

	//Képek elhelyezése

	Image h{Point{200,0},"h2.jpg"};
	h.set_mask(Point{500,200},200,200);
	Image h1{Point{0,200},"h2.jpg"};
	h1.set_mask(Point{500,200},200,200);
	Image h2{Point{600,100},"h2.jpg"};
	h2.set_mask(Point{500,200},200,200);
	win.attach(h);
	win.attach(h1);
	win.attach(h2);

	// mozgatás

	Image m{Point{0,0},"h3.jpg"};
	win.attach(m);
	int db = 64;	
	int szamlalo = 1; // a 1 mert már megvan jelenítve a kép a "0. helyen"
	int x_lepes =100;
	int y_lepes=0;
	for(int i =0; i < db; i++)
	{
		if(szamlalo == 8) // ha számláló eléri a nyolcat akkor a sor végére ée
		   {
		   	y_lepes+=100; // egy sorral lejebb ugrik
			szamlalo=0;
			x_lepes=-700; // visszaugris a sok elejére 
			}
		win.wait_for_button();
		m.move(x_lepes,y_lepes);
		szamlalo++;
		y_lepes = 0;
		x_lepes = 100;


	}

}


catch (exception& e)

{
	cerr <<"exception:"<< e.what() << endl;
	keep_window_open();

}

catch(...)

{
	cerr<<"exception\n";
	keep_window_open();
}