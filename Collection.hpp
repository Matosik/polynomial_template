#include "polynomial_template.hpp"
class Collection {
private:
	Polynominal* coll;
	int size;
public:
	Collection();
	int get_size_coll();

	void add_collection(Polynominal poly);

	void delete_collection();
	void delete_index(int& index);
	Polynominal& operator[](int id);
};