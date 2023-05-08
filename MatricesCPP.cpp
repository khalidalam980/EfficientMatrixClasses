#include <iostream>
using namespace std;

/*This class is only for the diagonal matrix.*/
class Diagonal
{
private:
	int *A;
	int n;
public:
	Diagonal()
	{
		n = 2;
		A = new int[2];
	} 
	Diagonal(int n)
	{
		this->n = n;
		A = new int[n];
	}
	~Diagonal()
	{
		delete[]A;
	}
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
};

void Diagonal::Set(int i, int j, int x)
{
	if (i == j)
		A[i - 1] = x;
}
int Diagonal::Get(int i, int j)
{
	if (i == j)
		return A[i - 1];
	else
		return 0;
}
void Diagonal::Display()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				cout << A[i] << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
}

/*This class is only for Lower Triangular matrix.*/
class LTMatrix
{
private:
	int* A;
	int n;
public:
	LTMatrix()
	{
		n = 2;
		A = new int[3];
	}
	LTMatrix(int n)
	{
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	~LTMatrix()
	{
		delete[]A;
	}
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
};



//tex:
// This is using Row Major Formula.
// $$\text{Index}(A[i][j])=\frac{i(i-j)}{2}+j-1$$
// The formula for column major is:
// $$\text{Index}(A[i][j])=n(j-1)-\frac{(j-2)\times(j-1)}{2}+i-j$$
//Now I'm using Row major. We can also use Column major the changes is just in the formulas



void LTMatrix::Set(int i, int j, int x)
{
	if (i >= j)
		A[i * (i - 1) / 2 + (j - 1)]=x;
}
int LTMatrix::Get(int i, int j)
{
	if (i >= j)
		return A[i * (i - 1) / 2 + (j - 1)];
	else
		return 0;
}
void LTMatrix::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= j)
				cout << A[i * (i - 1) / 2 + (j - 1)] << " ";
			else
				cout << "0 ";
		}
		cout << endl;

	}
}

/*This class is only for upper triangular matrix.*/
class UTMatrix
{
private:
	int* A;
	int n;
public:
	UTMatrix()
	{
		n = 2;
		A = new int[3];
	}
	UTMatrix(int n)
	{
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	~UTMatrix()
	{
		delete[]A;
	}
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
};


//tex:
//Formula for Row Major.
//$$\text{Index}(A[i][j])=n(i-1)-\frac{(i-2)(i-1)}{2}+j-1$$
//Formula for Column Major.
//$$\text{Index}(A[i][j])=\frac{j(j-1)}{2}+i-1$$
//Now I'm using column major. We can also use row major the changes is just in the formulas.


void UTMatrix::Set(int i, int j, int x)
{
	if (i <= j)
		A[j * (j - 1) / 2 + i - 1] = x;
}
int UTMatrix::Get(int i, int j)
{
	if (i <= j)
		return A[j * (j - 1) / 2 + i - 1];
	else
		return 0;
}
void UTMatrix::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i <= j)
				cout << A[j * (j - 1) / 2 + i - 1] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

/*This calss is for symmetric matrix and also use the
  row major formula of the lower triangular matrix.
  If A[i][j]==A[j][i] then the matrix is symmetric.*/
class SymMatrix
{
private:
	int* A;
	int n;
public:
	SymMatrix() //Non-Parametrize constructor.
	{
		n = 2;
		A = new int[3];
	}
	SymMatrix(int n)  //Parametrize constructor.
	{
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	~SymMatrix()       //Destructor
	{
		delete[]A;
	}
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	void Array();
};
void SymMatrix::Set(int i, int j,int x)
{
	if (i >= j)
		A[i * (i - 1) / 2 + j - 1] = x;  // Here the elements will be only stored in the lower triangular part of the symmetric matrix.
}
int SymMatrix::Get(int i, int j)
{
	if (i >= j)
		return A[i * (i - 1) / 2 + j - 1];
	else
		return A[j * (j - 1) / 2 + i - 1];  // The elements from the lower part is shown in the uppert by just changing i and j in the formula.
}
void SymMatrix::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i>=j)
				cout << A[i * (i - 1) / 2 + j - 1] << " ";
			else
				cout << A[j * (j - 1) / 2 + i - 1] << " ";
		}
		cout << endl;
	}
}
void SymMatrix::Array()
{
	for (int i = 0; i < n * (n + 1) / 2; i++)
	{
		cout << A[i] << " ";
	}
}

/*This class is for Tridiagonal matrix.
A tridiagonal matrix has nonzero elements only on the main diagonal,
the diagonal above the main diagonal, and the diagonal below the main diagonal.*/
class TrMatrix
{
private:
	int* A;
	int n;
public:
	TrMatrix()    //Non-Parametrize constructor.
	{
		n = 3;
		A = new int[7];
	}
	TrMatrix(int n)    //Parametrize constructor.
	{
		this->n = n;
		A = new int[3 * n - 2];
	}
	~TrMatrix()
	{
		delete[]A;
	}
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	void Array();
};
void TrMatrix::Set(int i, int j, int x)
{
	if (i - j == 1)
		A[i - 2] = x;
	else if (i - j == 0)
		A[n + i - 2] = x;
	else if (i - j == -1)
		A[2 * n + i - 2] = x;
}
int TrMatrix::Get(int i, int j)
{
	if (i - j == 1)
		return A[i - 2];
	else if (i - j == 0)
		return A[n + i - 2];
	else if (i - j == -1)
		return A[2 * n + i - 2];
	else
		return 0;
}
void TrMatrix::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i - j == 1)
				cout<<A[i - 2]<<" ";
			else if (i - j == 0)
				cout<<A[n + i - 2]<<" ";
			else if (i - j == -1)
				cout<<A[2 * n + i - 2]<<" ";
			else
				cout<<"0 ";
		}
		cout << endl;
	}
	cout << endl;
}
void TrMatrix::Array()
{
	for (int i = 0; i < 3*n-2; i++)
		cout << A[i] << " ";
	cout << endl;
}

/*This class is for Toeplitz Matrix.
Toeplitz, is a matrix in which each descending diagonal from left to right is constant.*/
//tex:
//Example is:
//$$\begin{bmatrix}a&b&d&e&f\\c&a&b&d&e\\g&c&a&b&d\\h&g&c&a&b\\i&h&g&c&a\end{bmatrix}$$
class ToeplitzMatrix
{
private:
	int* A;
	int n;
public:
	ToeplitzMatrix()
	{
		n = 3;
		A = new int[2 * 3 - 1];
	}
	ToeplitzMatrix(int n)
	{
		this->n = n;
		A = new int[2 * n - 1];
	}
	~ToeplitzMatrix()
	{
		delete[]A;
	}
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
};
void ToeplitzMatrix::Set(int i, int j, int x)
{
	if (i <= j)
		A[j - i] = x;
	else
		A[n + i - j - 1] = x;
}
int ToeplitzMatrix::Get(int i, int j)
{
	if (i <= j)
		return A[j - i];
	else
		return A[n + i - j - 1];
}
void ToeplitzMatrix::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i <= j)
				cout << A[j - i] << " ";
			else
				cout << A[n + i - j - 1] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int d;
	cout << "Enter the Dimensions:";
	cin >> d;

	ToeplitzMatrix Tpm(d);

	int x;
	cout << "Enter All the Elements:"<<endl;
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			Tpm.Set(i, j, x);
		}
	}
	cout << endl;
	Tpm.Display();
	cout << Tpm.Get(2, 3) << endl;

	return 0;
}