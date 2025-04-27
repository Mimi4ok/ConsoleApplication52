// ConsoleApplication52.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Fraction {
private:
    int num;
    int denum;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        int divisor = gcd(abs(num), abs(denum));
        num /= divisor;
        denum /= divisor;
        if (denum < 0) {
            num = -num;
            denum = -denum;
        }
    }

public:
    Fraction(int n = 0, int denom = 1) {
        num = n;
        if (denom == 0) {
            cout << "Denominator cannot be zero. Set to 1." << endl;
            denum = 1;
        } else {
            denum = denom;
        }
        simplify();
    }

    void input() {
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> denum;
        if (denum == 0) {
            cout << "Denominator cannot be zero. Set to 1." << endl;
            denum = 1;
        }
        simplify();
    }

    void print() const {
        cout << num;
        if (denum != 1) {
            cout << "/" << denum;
        }
    }

    Fraction add(const Fraction& other) const {
        int n = num * other.denum + other.num * denum;
        int denom = denum * other.denum;
        return Fraction(n, denom);
    }

    Fraction subtract(const Fraction& other) const {
        int n = num * other.denum - other.num * denum;
        int denom = denum * other.denum;
        return Fraction(n, denom);
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(num * other.num, denum * other.denum);
    }

    Fraction divide(const Fraction& other) const {
        return Fraction(num * other.denum, denum * other.num);
    }
};

int main() {
    Fraction a, b;
    cout << "Enter the first fraction:\n";
    a.input();

    cout << "Enter the second fraction:\n";
    b.input();

    Fraction sum = a.add(b);
    Fraction diff = a.subtract(b);
    Fraction prod = a.multiply(b);
    Fraction quot = a.divide(b);

    cout << "\nSum: ";
    sum.print();

    cout << "\nDifference: ";
    diff.print();

    cout << "\nProduct: ";
    prod.print();

    cout << "\nQuotient: ";
    quot.print();

    cout << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
