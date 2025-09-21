#include <stdio.h>   // ��������� �������� ��� �����/������ (printf, scanf)
#include <stdlib.h>  // ���������� �������� (��������������� ��� exit �� ��.)
#include <math.h>    // �������� ��� ������������ ������� (pow, sqrt, sin � �.�.)

// ������� ��� ���������� f(x) �� �������� ������� 4
double calculate_double(double x) {
    // f(x) = (x^3 / 30) - (4 * x^2) + 50
    return (pow(x, 3) / 30.0) - (4 * pow(x, 2)) + 50;
}

int main() {
    double X1, X2, delta;   // X1 - ������� ������, X2 - �����, delta - ����
    unsigned int N;         // ������� ����� ��� ����������
    int mode;               // ����� �����: 1 (����� N) ��� 2 (����� delta)

    // ���� ������
    printf("Choose input mode:\n");
    printf("1 - X1, X2, N\n");       // ����� 1: ������� �������, ����� � ������� �����
    printf("2 - X1, X2, delta\n");   // ����� 2: ������� �������, ����� � ����
    printf("Your choice: ");
    scanf("%d", &mode);              // ������� ���� �����������

    // --- ����� 1 ---
    if (mode == 1) {
        printf("Enter X1: ");
        scanf("%lf", &X1);           // ������� ��������� ��������
        printf("Enter X2: ");
        scanf("%lf", &X2);           // ������� ������ ��������
        printf("Enter number of points N: ");
        scanf("%u", &N);             // ������� ������� �����

        if (N > 1) {
            // ���������� ���� (delta) ���, ��� ������ �������� �� N-1 ������
            delta = (X2 - X1) / (N - 1);
        } else {
            // ���� N <= 1, �� ������� ���������� ���������
            printf("Error: N must be > 1\n");
            return 1; // ��������� �������� � ��������
        }

    }
    // --- ����� 2 ---
    else if (mode == 2) {
        printf("Enter X1: ");
        scanf("%lf", &X1);           // ������� ��������� ��������
        printf("Enter X2: ");
        scanf("%lf", &X2);           // ������� ������ ��������
        printf("Enter step delta: ");
        scanf("%lf", &delta);        // ������� ����

        if (delta > 0) {
            // ���������� ������� ����� (N)
            N = (unsigned int)((X2 - X1) / delta) + 1;
        } else {
            // ���� ���� <= 0, �� �� �������
            printf("Error: delta must be > 0\n");
            return 1;
        }

    }
    // --- ������������ ����� ---
    else {
        printf("Error: wrong mode.\n");
        return 1; // ��������� �������� � ��������
    }

    // ���� ���������� �����
    printf("X1=%.2lf,  X2=%.2lf,  delta=%.2lf\n\n", X1, X2, delta);

    // ���� ��������� �������
    printf("--------------------------------------------\n");
    printf("*   N   *    X    *    F(X)   *\n");
    printf("--------------------------------------------\n");

    int rowsPerPage = 9; // ������� ����� �� ���� "�������"
    for (unsigned int i = 0; i < N; i++) {
        double x = X1 + i * delta;   // ���������� ������� �������� X
        double y = calculate_double(x);             // ���������� �������� ������� f(x)

        // ���� ������ ����� �������: ����� �����, X, F(X)
        printf("| %3u  | %6.2lf | %8.2lf |\n", i + 1, x, y);

        // ���� ������ 9 ����� � �� ���������� ����� � ������ �����
        if ((i + 1) % rowsPerPage == 0 && (i + 1) < N) {
            printf("--------------------------------------------\n");
            printf("Press Any Key to Continue ...\n");
            getchar(); // ������ ��������� ������ '\n'
            getchar(); // ������, ���� ���������� ������� ������
            printf("--------------------------------------------\n");
        }
    }

    // ����������� ��� �������
    printf("--------------------------------------------\n");

    return 0; // ���������� ��������
}
