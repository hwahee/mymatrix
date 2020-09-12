#include <iostream>
#include "MyMatrix.h"

int main()
{
	MyMatrix a(2, 2), b(2, 2);

	a.setMatrix();
	b.setMatrix();

	MyMatrix c = a * b;
	c.show();
}