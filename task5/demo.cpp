#include <iostream>
#include<fstream>
//using namespace std;
int some();


class complex{
    private:
    float real;
    float img;

    public:
    void getvalue(){
        std::cin >> real;
        std::cin >> img;
    }
};
class somethinng{
    public:
    int num1,num2;
    float fl1,fl2;
    std::string s1,s2;
    public:
    somethinng(){
        num1 = 10;
        num2 = 12;
    }
    int operator ++ (){
        return num1 + 10;
    }
    public:
    void function(){
        std::cout << "enter int: ";
        std::cin >> num1 >> num2;
        std::cout << "enter float: ";
        std::cin >> fl1 >> fl2;
        std::cout << "enter string: ";
        std::cin >> s1 >> s2;
    }
    void calculation(){
        int sum = num1 + num2;
        std::cout << "sum of int: " << sum;
        float div = fl1 / fl2;
        std::cout << "division of float :  "<< div;       
    }


};
int main(){
    
    std::ofstream file("somefile.txt");
    file.binary;
    std::string str;
    std::getline(std::cin,str);
    std::cout << "string using string object is : " << str << std::endl;
    // somethinng s;
    // int n = ++s;
    // std::cout << n;

    // std::cout << "number is : " << num << std :: endl;
    // std::cout << "string using char is : " << ch << std :: endl;

    return 0;
}


