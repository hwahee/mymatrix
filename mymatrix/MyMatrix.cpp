#include "MyMatrix.h"

void MyMatrix::setMatrix()
{
	//table head
	std::cout << "\t ";
	for (int i = 1; i <= row; i++)
		std::cout << i << "\t";
	std::cout << "\n";

	//table body
	for (int c = 0; c < col; c++) {
		std::cout << c << "\t|";
		for (int r = 0; r < row; r++) {
			std::cin >> (*matrix)[c][r];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

MyMatrix MyMatrix::operator+(const MyMatrix& other)
{
	if (row != other.row || col != other.col) {
		return MyMatrix(-1, -1, true);
	}

	MyMatrix ret(other);
	for (int c = 0; c < ret.col; c++) {
		for (int r = 0; r < ret.row; r++) {
			ret.matrix->at(c).at(r) = this->matrix->at(c).at(r) + other.matrix->at(c).at(r);
		}
	}

	return ret;
}

MyMatrix MyMatrix::operator*(const MyMatrix& other)
{
	if (this->col!=other.row) {
		return MyMatrix(-1, -1, true);
	}

	MyMatrix ret(this->col,other.row);
	for (int c = 0; c < this->col; c++) {
		for (int r = 0; r < ret.row; r++) {
			double sum = 0;
			for (int mid = 0; mid < ret.col; mid++) {
				sum += this->matrix->at(c).at(mid) * other.matrix->at(mid).at(r);
			}
			ret.matrix->at(c).at(r) = sum; 
		}
	}

	return ret;
}


