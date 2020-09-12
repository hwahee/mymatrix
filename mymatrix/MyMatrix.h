#pragma once
#include <iostream>
#include <vector>
class MyMatrix
{
	std::vector<std::vector<double>>* matrix;
	int col;
	int row;
	
	bool NaM;
public:
	friend class MyMatrix;

	MyMatrix(int c, int r, bool NaM = false) {
		col = c, row = r;
		this->NaM = NaM;
		std::vector<double> tmp(r);
		matrix = new std::vector<std::vector<double>>(c, tmp);
	}
	MyMatrix(const MyMatrix& other) {
		this->matrix = new std::vector<std::vector<double>>(*(other.matrix));
		this->col = other.col,	this->row = other.row;
		this->NaM = false;
	}
	~MyMatrix() {
		delete matrix;
	}

	void setMatrix();

	MyMatrix operator+(const MyMatrix& other);
	MyMatrix operator*(const MyMatrix& other);

	void show() {
		for (int c = 0; c < col; c++) {
			for (int r = 0; r < row; r++) {
				std::cout << matrix->at(c).at(r) << "\t\t";
			}
			std::cout << "\n\n";
		}
	}
};

