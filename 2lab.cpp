#include <iostream>
#include <fstream>

using namespace std;

class Vector {
    int* p = nullptr; // ��������� �� ������ �� ���
    int n = 0; // ������ ���

public:
    Vector(int* p, int n) { // ����������� ��� �������� ��� �� ������� ��
        this->n = n;
        this->p = new int[n];
        for (int i = 0; i < n; i++) this->p[i] = p[i];
    }

    Vector(int n) : n(n) { // ����������� ��� �������� ������� ��� ��������� �������
        p = new int[n]();
    }

    Vector(const Vector& V) {
        n = V.n;
        p = new int[n];
        for (int i = 0; i < n; i++)
            p[i] = V.p[i];
    }

    Vector(Vector&& V) {
        std::swap(p, V.p);
        std::swap(n, V.n);
    }

    void print() const { // ����� ��� ������ �������� ���
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << endl;
    }

    int& operator[](int index) { // ������������� �������� ����������
        return p[index];
    }

    Vector& operator =(const Vector& v2) { // ������������� �������� ������������ � ������������
        if (this != &v2) { // ��������, ����� �� ���� ����������
            n = v2.n;
            if (p != nullptr) delete[] p;
            p = new int[n];
            for (int i = 0; i < n; i++)
                p[i] = v2.p[i];
        }
        return *this;
    }

    Vector& operator =(Vector&& v2) { // ������������� �������� ������������ � ������������
        if (this != &v2) { // ��������, ����� ��������� ��� ����������
            std::swap(p, v2.p);
            std::swap(n, v2.n);
        }
        return *this;
    }

    bool operator<(const Vector& v2) const {
        if (n != v2.n) {
            return false;
        }

        for (int i = 0; i < n; ++i) {
            if (p[i] >= v2.p[i]) {
                return false;
            }
        }
        return true;
    }

    friend ostream& operator<<(ostream& os, const Vector& v) { // ������������� �������� ������ � �����
        for (int i = 0; i < v.n; i++) // ����� �������� ������� ����� ����� ������
            os << v.p[i] << " ";
        return os;
    }

    friend istream& operator>>(istream& is, Vector& v) { // ������������� �������� ����� �� ������
        for (int i = 0; i < v.n; i++) // ���������� �������� ������� �� ������ �����
            is >> v.p[i];
        return is;
    }

    ~Vector() { // ���������� ������
        delete[] p;
    }
};

int main() {
    ifstream input("input.txt");
    int size = 0;
    int size1 = 0;
    input >> size;
    input >> size1;
    int* values = new int[size];
    for (int i = 0; i < size; ++i) {
        input >> values[i];
    }
    int* values1 = new int[size1];
    for (int i = 0; i < size1; ++i) {
        input >> values1[i];
    }
    Vector v1(values, size);
    Vector v2(values1, size1);
    bool res = v1 < v2;
    cout << res;
    delete[] values;
    delete[] values1;
}