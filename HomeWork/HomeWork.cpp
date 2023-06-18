// HomeWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>




void Initial_Array(std::ifstream& file, int s_arr, int* arr) {
	for (int i = 0; i < s_arr; ++i) {
		file >> arr[i];
	}
}

int* New_Array(int size) {
	int* arr = new int [size]();
	return arr;
}

void Shifting_Array_Left(int* arr, int size) {
	int* CopyArr = new int[size]();
	for (int i = 0; i < size; ++i) {
		if (i == 0) {
			CopyArr[size - 1] = arr[i];
		}
		else {
			CopyArr[i - 1] = arr[i];
		}
	}
	for (int i = 0; i < size; ++i) {
		arr[i] = CopyArr[i];
	}
	delete[] CopyArr;
}

void Shifting_Array_Right(int* arr, int size) {
	int* CopyArr = new int[size]();
	for (int i = 0; i < size; ++i) {
		if (i == 0) {
			CopyArr[i] = arr[size - 1];
		}
		else {
			CopyArr[i] = arr[i - 1];
		}
	}
	for (int i = 0; i < size; ++i) {
		arr[i] = CopyArr[i];
	}
	delete[] CopyArr;
}

void Delete_Arrey(int *arr1, int *arr2) {
	delete[] arr1;
	delete[] arr2;
}



int main()
{
	int x = 0, y = 0;

	std::ifstream IN("in.txt");
	if (IN.is_open() == 0) {
		std::cout << "File not found!" << std::endl;
	}

	IN >> x;
	int *Arr1 = New_Array(x);
	Initial_Array(IN, x, Arr1);
	Shifting_Array_Left(Arr1,x);


	IN >> y;
	int* Arr2 = New_Array(y);
	Initial_Array(IN, y, Arr2);
	Shifting_Array_Right(Arr2,y);

	std::ofstream OUT("out.txt");


	OUT << y << std::endl;
	for (int i = 0; i < y; ++i) {
		OUT << Arr2[i] << " ";
	}

	OUT << std::endl;

	OUT << x << std::endl;
	for (int i = 0; i < x; ++i) {
		OUT << Arr1[i] << " ";
	}

	Delete_Arrey(Arr1,Arr2);

}
