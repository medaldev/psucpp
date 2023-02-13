
#include <iostream>
#include <cstdio>
using namespace std;




double fRand(double fMin, double fMax) {
    double f = (double) rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
void print_matrix(T *matrix, int rows, int cols){
    cout << endl;
    for(int i=0; i < rows; ++i){
        for (int j=0; j < cols; ++j){
            cout << matrix[i*cols + j] << " ";
        }
        cout << endl;
    }
}

template <class T>
void cinMatrix(T *A, int rows, int cols, char label) {
    printf("Matrix input started \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c[%d][%d] = ", label, i, j);
            cin >> A[i*cols + j];
        }
    }
    printf("Matrix input ended. \n");

}




int main() {
    std::cout << "Hello, World!\n" << std::endl;

    //int n;
    //cin >> n;

    //double A[n][n], b[n], x[n];
    static int n = 3;
    double x[n];
    static double A[3][3] = {{2, 4, 1}, {5, 2, 1}, {2, 3, 4}};
    static double b[3] = {36, 47, 37};
    //A = {{2, 4, 1, 36}, {5, 2, 1, 47}, {2, 3, 4, 37}};

    //cinMatrix((double *)&A, n, n, 'A');
    //cinMatrix((double *)&b, 1, n, 'b');

    print_matrix((double *)&A, n, n);
    print_matrix((double *)&b, 1, n);

    for (int k = 0; k < n; k++) {
        for (int j = k + 1; j < n; j++) {
            double d = A[j][k] / A[k][k];
            for (int i = k; i < n; i++) {
                A[j][i] -= d * A[k][i];
            }
            b[j] -= d * b[k];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int j = k + 1; j < n; j++) {
            double d = A[n-j-1][n-k-1] / A[n-k-1][n-k-1];
            for (int i = k; i < n; i++) {
                A[n-j-1][n-i-1] -= d * A[n-k-1][n-i-1];
            }
            b[n-j-1] -= d * b[n-k-1];
        }
    }

    for (int i = 0; i < n; i++) x[i] = b[i] / A[i][i];


    print_matrix((double *)&A, n, n);
    print_matrix((double *)&b, 1, n);

    cout << "\nSolution: " << endl;
    print_matrix((double *)&x, 1, n);


    return 0;
}




