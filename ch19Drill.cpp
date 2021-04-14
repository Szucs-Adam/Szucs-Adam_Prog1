#include "std_lib_facilities.h"

template<typename T> 
	struct S {
		S(T d) : val(d) {}
	
		T& get();
		const T& get() const;

		void set(const T& d);
		T& operator=(const T&);
private:
	T val; 
};

// Nem konstans a "val"

template<typename T> 
	T& S<T>::get() 
		{ return val; }

// Konstans a "val"

template<class T> 
	const T& S<T>::get() 
	const { return val; }

//set()

template<typename T> 
	void S<T>::set(const T& d) { val = d; }

//'=' operator a set helyett >>> tehát az operator 
//gyakorlatilag definiál egy műveletet mint egy funct

template<class T> T& S<T>::operator=(const T& d)
{
	val = d;
	return val;
}

// bonus de kell hogy a read:val működjön

template<class T> istream& operator>>(istream& is, S<T>& ss)
{
	T v;
	cin >> v;
	if (!is) 
		return is;
	ss = v;
	return is;
}


//read_val()

template<class T> 
	void read_val(T& v)
		{
			cin >> v;
		}

int main()
{
	
	//-------------------------------
	S<int> s_int(1234);
	S<char> s_char('a');
	S<double> s_double(9.8);
	S<string> s_string("Ez_egy_string");
	vector<int> vi;
	vi.push_back(12);
	vi.push_back(13);
	vi.push_back(14);
	vi.push_back(15);
	S<vector<int>> svi(vi);
	//-------------------------------
	
	/* public val mivel publik ezért nem működik mert a vasl privat

	cout << "Elso kiiratas:" << endl; cout << endl;
	cout << "s_int = " << s_int.val << endl;
	cout << "s_char = " << s_char.val << endl;
	cout << "s_double = " << s_double.val << endl;
	cout << "s_string = " << s_string.val << endl;
	for (int i = 0; i < svi.val.size(); i++)
	{
		cout << "svi[" << i << "] = " << svi.val[i] << endl;
	}
	
*/

	cout << "Masodik kiiratas:" << endl; cout << endl;
	cout << "s_int = " << s_int.get() << endl;
	cout << "s_char = " << s_char.get() << endl;
	cout << "s_double = " << s_double.get() << endl;
	cout << "s_string = " << s_string.get() << endl;
	for (int i = 0; i < svi.get().size(); i++)
	{
		cout << "svi[" << i << "] = " << svi.get()[i] << endl;
	} cout << endl;


	// set() felülirashoz

	s_int.set(4321);
	s_char.set('c');
	s_double.set(4.20);
	s_string.set("Benzin");
	vi[0] = 21; // csak kettőt irok felül a o adik illetve a 2 edik lemet
	vi[2] = 22;
	svi.set(vi);

	cout << "Kiiratas a set() utan:" << endl; cout << endl;
	cout << "s_int = " << s_int.get() << endl;
	cout << "s_char = " << s_char.get() << endl;
	cout << "s_double = " << s_double.get() << endl;
	cout << "s_string = " << s_string.get() << endl;
	for (int i = 0; i < svi.get().size(); i++)
	{
		cout << "svi[" << i << "] = " << svi.get()[i] << endl;
	} cout << endl;

	
	//'=' operator használata új adatok felvételéhez

	s_int = 4231;
	s_char = 't';
	s_double = 742.2;
	s_string = "Mákosguba";
	vi[0] = 20;
	vi[1] = 23;
	svi = vi;

	cout << "Elemek kiiratasa az '=' operator hasznalata utan:" << endl; cout << endl;

	cout << "s_int = " << s_int.get() << endl;
	cout << "s_char = " << s_char.get() << endl;
	cout << "s_double = " << s_double.get() << endl;
	cout << "s_string = " << s_string.get() << endl;
	for (int i = 0; i < svi.get().size(); i++)
	{
		cout << "svi[" << i << "] = " << svi.get()[i] << endl;
	} cout << endl;

	// Beolvasás a felhasználótól a read_val segítségével .. 

	cout << "FElhasznalo adatainak beolvasasa" << endl; cout << endl;
	cout << "s_int = ";
	read_val(s_int);
	cout << "s_char = ";
	read_val(s_char);
	cout << "s_double = ";
	read_val(s_double);
	cout << "s_string = ";
	read_val(s_string);

	// egyszerű kiiratás

	cout << endl;
	cout << "Outputting..." << endl;
	cout << "s_int = " << s_int.get() << endl;
	cout << "s_char = " << s_char.get() << endl;
	cout << "s_double = " << s_double.get() << endl;
	cout << "s_string = " << s_string.get() << endl;
}