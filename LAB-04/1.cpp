#include <iostream>
using namespace std;

class Matrix{
	private:
		int Rows;
		int Coloumns;
		int **MatrixArray; 
	public:
		Matrix(){ 
			Rows = 0;
			Coloumns = 0;
			MatrixArray = new int*[Rows];
			for (int i = 0; i < Rows; i++){
				MatrixArray[i] = new int[Coloumns];
			}
			for (int i = 0; i < Rows; i++){
				for (int j = 0; j < Coloumns; j++){
					MatrixArray[i][j] = 0;
				}
			}
		}
		
		Matrix(int Rows, int Coloumns){ 
			this -> Rows = Rows;
			this -> Coloumns = Coloumns;
			MatrixArray = new int*[Rows];
			for (int i = 0; i < Rows; i++){
				MatrixArray[i] = new int[Coloumns];
			}
			for (int i = 0; i < Rows; i++){
				for (int j = 0; j < Coloumns; j++){
					MatrixArray[i][j] = 0;
				}
			}
		}
		
		Matrix(const Matrix& other){ 
			this -> Rows = other.Rows;
			this -> Coloumns = other.Coloumns;
			MatrixArray = new int*[Rows];
			for (int i = 0; i < Rows; i++){
				MatrixArray[i] = new int[Coloumns];
			}
			for (int i = 0; i < Rows; i++){
				for (int j = 0; j < Coloumns; j++){
					MatrixArray[i][j] = other.MatrixArray[i][j];
				}
			}
		}
		
		Matrix(Matrix&& other) noexcept : MatrixArray(other.MatrixArray), Rows(other.Rows), Coloumns(other.Coloumns){ // Move Constructor
			other.MatrixArray = nullptr;
			other.Rows = 0;
			other.Coloumns = 0;

		}
		
		~Matrix(){ 
			for (int i = 0; i < Rows; i++){
				delete[] MatrixArray[i]; 
			}
			delete[] MatrixArray; 
		}
		
		int GetRows(){
			return Rows;
		}
		int GetColoumns(){
			return Coloumns;
		}
		int AtLocation (int r, int c){
			return MatrixArray[r][c];
		}
		void Fill (double Value){
			for (int i = 0; i < Rows; i++){
				for (int j = 0; j < Coloumns; j++){
					MatrixArray[i][j] = Value;
				}
			}
		}
		void Transpose() {
	        int** Transposition = new int*[Coloumns];
	        for (int i = 0; i < Coloumns; i++) {
	            Transposition[i] = new int[Rows];
	        }
	        for (int i = 0; i < Rows; i++) {
	            for (int j = 0; j < Coloumns; j++) {
	                Transposition[j][i] = MatrixArray[i][j];
	            }
	        }
	        for (int i = 0; i < Coloumns; i++) {
	            for (int j = 0; j < Rows; j++) {
	                cout << Transposition[i][j] << " ";
	            }
	            cout << endl;
	        }
	        for (int i = 0; i < Coloumns; i++) {
	            delete[] Transposition[i];
	        }
	        delete[] Transposition;
	    }
	    
		void PrintMatrix() const {
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Coloumns; j++) {
					cout << MatrixArray[i][j] << " ";
				}
				cout << endl;
			}
		}
};

int main(){
	cout << "Initialising Matrix1" <<endl;
	Matrix m1(2,3);	
	m1.PrintMatrix();
	cout << endl << endl;
	
	cout << "Filling Matrix1" <<endl;
	m1.Fill(12);
	m1.PrintMatrix();
	cout << endl << endl;
	
	cout << "Copying Matrix1 to Matrix 2" <<endl;
	Matrix m2 = m1;	
	m2.PrintMatrix();
	cout << endl << endl;
	
	cout << "Transposing Matrix2" <<endl;
	m2.Transpose();
	cout << endl << endl;
	
	cout << "Moving Matrix1 to Matrix 3" <<endl;
	Matrix m3 = move(m1);
	m3.PrintMatrix();
	cout << endl << endl;
	
	cout << "Get Rows of Matrix 1: " << m1.GetRows() << endl;
	cout << "Get Colounms of Matrix 1: " << m1.GetColoumns() << endl;
	cout << "Getting value of Matrix 1 at location (1,2): " << m2.AtLocation(1,2);
	
	return 0;
}
