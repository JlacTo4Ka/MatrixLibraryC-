#include "s21_matrix_oop.h"

int main() {
    // S21Matrix first;
    // S21Matrix second(-1, 4);
    // S21Matrix third(first);
    // S21Matrix fourth(second);

    // S21Matrix forDeterminant_1(4, 4);
    // forDeterminant_1.SetIJ(0, 0, 1);
    // forDeterminant_1.SetIJ(0, 1, 2);
    // forDeterminant_1.SetIJ(0, 2, 3);
    // forDeterminant_1.SetIJ(0, 3, 4);
    // forDeterminant_1.SetIJ(1, 0, 5);
    // forDeterminant_1.SetIJ(1, 1, 6);
    // forDeterminant_1.SetIJ(1, 2, 7);
    // forDeterminant_1.SetIJ(1, 3, 8);
    // forDeterminant_1.SetIJ(2, 0, 9);
    // forDeterminant_1.SetIJ(2, 1, 10);
    // forDeterminant_1.SetIJ(2, 2, 11);
    // forDeterminant_1.SetIJ(2, 3, 12);
    // forDeterminant_1.SetIJ(3, 0, 13);
    // forDeterminant_1.SetIJ(3, 1, 14);
    // forDeterminant_1.SetIJ(3, 2, 15);
    // forDeterminant_1.SetIJ(3, 3, 16);

    // S21Matrix forDeterminant_2(4, 4);
    // forDeterminant_2.SetIJ(0, 0, -5);
    // forDeterminant_2.SetIJ(0, 1, 2);
    // forDeterminant_2.SetIJ(0, 2, 3);
    // forDeterminant_2.SetIJ(0, 3, 4);
    // forDeterminant_2.SetIJ(1, 0, 5);
    // forDeterminant_2.SetIJ(1, 1, 6);
    // forDeterminant_2.SetIJ(1, 2, 7);
    // forDeterminant_2.SetIJ(1, 3, 8);
    // forDeterminant_2.SetIJ(2, 0, 9);
    // forDeterminant_2.SetIJ(2, 1, 10);
    // forDeterminant_2.SetIJ(2, 2, -11);
    // forDeterminant_2.SetIJ(2, 3, 12);
    // forDeterminant_2.SetIJ(3, 0, 13);
    // forDeterminant_2.SetIJ(3, 1, 14);
    // forDeterminant_2.SetIJ(3, 2, 15);
    // forDeterminant_2.SetIJ(3, 3, 16);

    // S21Matrix c(4, 4);
    // c = forDeterminant_1 + forDeterminant_2;
    // std::cout << '\n';
    // c = forDeterminant_1 - forDeterminant_2;
    // std::cout << '\n';
    // c = forDeterminant_1 * forDeterminant_2;
    // std::cout << '\n';
    // c = forDeterminant_1 * 2;
    // std::cout << '\n';
    // c.Print();
    
    // forDeterminant_2.Print();
    // std::cout << '\n';

    // std::cout << "детерминант = " << forDeterminant_2.Determinant() << '\n';

    // S21Matrix Calc_test(4, 4);

    // Calc_test.SetIJ(0, 0, 1);
    // Calc_test.SetIJ(0, 1, 2);
    // Calc_test.SetIJ(0, 2, 3);
    // Calc_test.SetIJ(0, 3, 4);
    // Calc_test.SetIJ(1, 0, 5);
    // Calc_test.SetIJ(1, 1, 6);
    // Calc_test.SetIJ(1, 2, 7);
    // Calc_test.SetIJ(1, 3, 8);
    // Calc_test.SetIJ(2, 0, 9);
    // Calc_test.SetIJ(2, 1, 10);
    // Calc_test.SetIJ(2, 2, 111);
    // Calc_test.SetIJ(2, 3, 12);
    // Calc_test.SetIJ(3, 0, 13);
    // Calc_test.SetIJ(3, 1, 14);
    // Calc_test.SetIJ(3, 2, 15);
    // Calc_test.SetIJ(3, 3, 16);

    // Calc_test.Print();
    // std::cout << '\n';

    // Calc_test.CalcComplements().Print();

    // S21Matrix tranpose(3 , 3);
    // tranpose.SetIJ(0, 0, 0);
    // tranpose.SetIJ(0, 1, 5);
    // tranpose.SetIJ(0, 2, 7);
    // tranpose.SetIJ(1, 0, 6);
    // tranpose.SetIJ(1, 1, 3);
    // tranpose.SetIJ(1, 2, 4);
    // tranpose.SetIJ(2, 0, 5);
    // tranpose.SetIJ(2, 1, -2);
    // tranpose.SetIJ(2, 2, -3);

    // tranpose.Transpose().Print();
    // std::cout << '\n';

    // S21Matrix invers(3 , 3);
    // invers.SetIJ(0, 0, 0);
    // invers.SetIJ(0, 1, 5);
    // invers.SetIJ(0, 2, 7);
    // invers.SetIJ(1, 0, 6);
    // invers.SetIJ(1, 1, 3);
    // invers.SetIJ(1, 2, 4);
    // invers.SetIJ(2, 0, 5);
    // invers.SetIJ(2, 1, -2);
    // invers.SetIJ(2, 2, -3);

    // invers.Print();
    // std::cout << '\n';

    // invers.InverseMatrix().Print();

    // first.Print();
    // std::cout << '\n';

    // second.SetRows(1);
    // second.SetCols(1);
    // second.Print();
    // std::cout << '\n';

    // third.Print();
    // std::cout << '\n';

    // fourth.Print();
    // std::cout << '\n';
    
    S21Matrix A = S21Matrix(1, 1);
    A(0, 0) = 2;

    A.Print();
    std::cout << '\n';

    S21Matrix Q = A.InverseMatrix();

    Q.Print();
    std::cout << '\n';

    S21Matrix B = S21Matrix(2, 2);
    B(0, 0) = 1;
    B(0, 1) = 2;
    B(1, 0) = 3;
    B(1, 1) = 4;

    B.Print();
    std::cout << '\n';

    S21Matrix R = B.InverseMatrix();

    R.Print();



    return 0;
}