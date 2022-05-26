#include <iostream>
namespace AS
{
	class Matrix
	{
	public:
		Matrix(int n, int m);
		Matrix(const Matrix& mat);

		Matrix& operator=(const Matrix& mat);

		Matrix operator+(const Matrix& mat);

		Matrix operator+=(const Matrix& mat);

		Matrix operator*(const Matrix& mat);

		~Matrix();

		friend std::istream& operator>>(std::istream& os, Matrix& mat);
		friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);

		int Det();

		Matrix transposition();

		Matrix inv();

	private:
		int m_n, m_m;		
		int n;
		int** m_mat; // Matrix
	};
}