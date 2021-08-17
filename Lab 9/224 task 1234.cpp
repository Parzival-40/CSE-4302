#include <iostream>
#include <string>
using namespace std;

enum class Material { Wood,
					  Board,
					  Steel,
					  foam };
enum class BedSize { Single,
					 SemiDouble,
					 Double };
enum class SofaSize { One,
					  Two,
					  Three,
					  Four,
					  Five };
enum class ChairCount { Two,
						Four,
						Six };
class Furniture {
protected:
	string name;
	double price;
	double discount;
	Material madeof;

public:
	Furniture(string n, double p, double d, Material m)
	  : name(""),
		price(0),
		discount(0),
		madeof(Material::Wood) {
		setName(n);
		setPrice(p);
		setDiscount(d);
		setMadeof(m);
	}
	void setName(string n) {
		name = n;
	}
	void setPrice(double val) {
		if (val > 0)
			price = val;
	}
	void setDiscount(double val) {
		if (val <= price)
			discount = val;
	}
	void setMadeof(Material val) {
		madeof = val;
	}
	string getMadeof() {
		if (madeof == Material::Wood)
			return "Wood";
		if (madeof == Material::Board)
			return "Board";
		if (madeof == Material::Steel)
			return "Steel";
		return "";
	}
	virtual void productDetails() {
		cout << "-----------------------" << endl
			 << "Product name: " << name << endl
			 << "Regular price: " << price << endl
			 << "Discounted price: " << discount << endl
			 << "Material: " << getMadeof() << endl;
	}
	friend void sort_furniture_discount(Furniture* furnitures[], int no_of_furnitures);
};

class Bed : public Furniture {
protected:
	BedSize size;

public:
	Bed(string n, double p, double d, Material m, BedSize s)
	  : Furniture(n, p, d, m), size(s) {}

	string getSize() {
		if (size == BedSize::Single)
			return "Single";
		if (size == BedSize::SemiDouble)
			return "SemiDouble";
		if (size == BedSize::Double)
			return "Double";
		return "";
	}
	void productDetails() {
		Furniture::productDetails();
		cout << "BedSize: " << getSize() << endl
			 << "####################################" << endl;
	}
};
class Sofa : public Furniture {
protected:
	SofaSize size;

public:
	Sofa(string n, double p, double d, Material m, SofaSize s)
	  : Furniture(n, p, d, m), size(s) {}

	string getSize() {
		if (size == SofaSize::One)
			return "One";
		if (size == SofaSize::Two)
			return "Two";
		if (size == SofaSize::Three)
			return "Three";
		if (size == SofaSize::Four)
			return "Four";
		if (size == SofaSize::Five)
			return "Five";
		return "";
	}
	void productDetails() {
		Furniture::productDetails();
		cout << "Sofa size: " << getSize() << endl
			 << "####################################" << endl;
	}
};
class DiningTable : public Furniture {
protected:
	ChairCount chairs;

public:
	DiningTable(string n, double p, double d, Material m, ChairCount s)
	  : Furniture(n, p, d, m), chairs(s) {}

	string getSize() {
		if (chairs == ChairCount::Two)
			return "Two";
		if (chairs == ChairCount::Four)
			return "Four";
		if (chairs == ChairCount::Six)
			return "Six";
		return "";
	}
	void productDetails() {
		Furniture::productDetails();
		cout << "Table Size: " << getSize() << endl
			 << "####################################" << endl;
	}
};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
void sort_furniture_discount(Furniture* furnitures[], int no_of_furnitures) {
	for (int i = 0; i < no_of_furnitures; i++) {
		for (int j = 0; j < no_of_furnitures; j++) {
			if ((*furnitures[i]).discount > (*furnitures[j]).discount) {
				swap(*furnitures[i], *furnitures[j]);
			}
		}
	}
}

int main() {
	Furniture* f_list[100];

	/**
        task 1
        So that following lines can be executed without error
    */
	f_list[0] = new Bed("", 10000, 123, Material::Wood, BedSize::Single);
	f_list[1] = new Sofa("", 11000, 234, Material::Steel, SofaSize::Five);
	f_list[2] = new DiningTable("", 13000, 345, Material::Wood, ChairCount::Two);
	f_list[3] = new Bed("", 10090, 123, Material::Wood, BedSize::Single);

	/**task 1 ends here*/

	/**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
	f_list[2]->setName("Product name");
	for (int i = 0; i < 4; i++) {
		f_list[i]->productDetails();
	}

	/**task 2 ends here*/
	/**task 3 ends here*/

	/**task 4
    So that following lines can be executed without error
    */
	sort_furniture_discount(f_list, 4);
	for (int i = 0; i < 4; i++) {
		f_list[i]->productDetails();
	}
	/**task 4 ends here*/
}
