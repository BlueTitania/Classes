#include <iostream>

using namespace std;

//определить абстрактный базовый класс с чисто виртуальным методом
//вывода на экран и викт. деструктором (возможно чисто вирт)
//определить согластно варинту производные классы с полями
//предусмотреть аксессоры и мутаторы для полей, и конструкторы
//Продемонстрировать полиморфизм на примере указателей, и ссылок н абстрактный базовый класс
//(конкретные класс для создаваемого объекта должен выбираться пользователем через простейшее меню)

//вариант 6
//определить Soild(тело) с виртуальными методами вычисления площади поверхности
//и объема. Определить производные классы: RightPrism и RightPyramid
//с переопределенными методами вычисления площади и поверхности объема

//полиморфный класс
class Soild{

public:

    virtual double square(){return 0;}

    virtual double volume(){return 0;}

    virtual void print() =0;//чисто вируалный вывод на экран
    virtual ~Soild() {
        cout << "Soild::dtor()" << endl;
        //delete Soild;
    }
};

class RightPrism : public Soild{
private:
    double h_, so_, sb_;
public:
    RightPrism(double h, double so, double sb)
        :h_(h),
         so_(so),
         sb_(sb)
    {}

    RightPrism()//"конструктор по умолчанию"
        :h_(0),
         so_(0),
         sb_(0)
    {}
    void print(){
        cout<<"RightPrism\n";
    }

    double square(){
        return 2*so_+sb_;
    }

    double volume(){
        return so_*h_;
    }

    //аксессоры(get) и мутаторы(set)

    int get_h() const{ return h_;}
    int get_so() const{ return so_;}
    int get_sb() const{ return sb_;}

    void set_h(double h){h_=h;}
    void set_so(double so){so_=so;}
    void set_sb(double sb){sb_=sb;}

};

class RightPyramid : public Soild{
private:
    double h_, so_, sb_;
public:
    RightPyramid(double h, double so, double sb)
        :h_(h),
         so_(so),
         sb_(sb)
    {}

    RightPyramid()//"конструктор по умолчанию"
        :h_(0),
         so_(0),
         sb_(0)
    {}

    double square(){
        return so_+sb_;
    }

    double volume(){
        return so_*h_/3;
    }

    void print(){
        cout<<"RightPyramid\n";
    }

    //аксессоры(get) и мутаторы(set)
    int get_h() const{ return h_;}
    int get_so() const{ return so_;}
    int get_sb() const{ return sb_;}

    void set_h(double h){h_=h;}
    void set_so(double so){so_=so;}
    void set_sb(double sb){sb_=sb;}
};

void show_who (Soild &r) {
    r.print();
}

/*
int square_what (Soild &r) {
    return r.square();
}

int volume_what(Soild &r) {
    return r.volume();
}
*/

int main()
{
    int num,h(0),so(0),sb(0);

    cout<<"Select the figure"<<endl<<"0-RightPyramid\n"<<"1-RightPrism\n";
    cin>>num;
    cout<<"Ented the height, square of base and square of side\n";
    cin>>h;
    cin>>so;
    cin>>sb;

    Soild* shapes[2]={ // Т.к. класс Soild является абстрактным,можно объявить массив указателей, но не массив фигур
        new RightPyramid(h,so,sb),
        new RightPrism(h,so,sb)
    };

    show_who(*shapes[num]);
    cout<<"square= "<<shapes[num]->square();
    //square_what(*shapes[num]);
    cout<<endl;

    cout<<"volume= "<<shapes[num]->volume();
    //volume_what(*shapes[num]);
    cout<<endl;

    delete shapes[num];

    return 0;
}

