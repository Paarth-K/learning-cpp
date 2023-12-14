#include <iostream>
#include <string>

using namespace std;

class Complex
{
private:
    int real, img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }

    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.img = real + obj.img;
        return res;
    }
    Complex operator-(Complex const &obj)
    {
        Complex res;
        res.real = real - obj.real;
        res.img = real - obj.img;
        return res;
    }
    Complex operator*(Complex const &obj)
    {
        Complex res;
        // int realtemp1 = real * obj.real;
        // int imgtemp2 = real * obj.img;
        // int imgtemp3 = img * obj.real;
        // int realtemp4 = img * obj.img * -1;

        // res.real = realtemp1 + realtemp4;
        // res.img = imgtemp2 + imgtemp3;

        res.real = (real * obj.real) + (img * obj.img * -1);
        res.img = (real * obj.img) + (img * obj.real);

        return res;
    }

    void print()
    {
        cout << real << " + " << img << "i" << endl;
    }
};

int main()
{
    Complex c1(2, -3);
    Complex c2(1, 2);

    c1.print();
    c2.print();
    cout << endl;

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;

    c3.print();
    cout << endl;

    c4.print();
    cout << endl;

    c5.print();

    return 0;
}
