#ifndef POJAZD_BIBL_H
#define POJAZD_BIBL_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Pojazd {
protected:
    virtual void drukuj (ostream& os) const{};
public:
    virtual string getType () const =0;
    virtual ~Pojazd(){}
    friend ostream& operator <<(ostream& os, const Pojazd& p ){
        p.drukuj(os);
        return os;
    }
};

class Samochod : public Pojazd {
private:
    void drukuj (ostream& os) const override{
        os << "S ";
    };
public:
    string getType () const override{
        return "Samochod";
    }
    ~Samochod(){
//        cout << "wyjechal "<< getType() << endl;
    }
};

class Bus : public Pojazd {
private:
    void drukuj (ostream& os) const override{
        os << "B ";
    };
public:
    string getType () const override{
        return "Bus";
    }
    ~Bus (){
//            cout << "wyjechal "<< getType() << endl;
        }
};

class Motocykl : public Pojazd {
private:
    void drukuj (ostream& os) const override{
        os << "M ";
    };
public:
    string getType () const override{
        return "Motocykl";
    }
    ~Motocykl (){
//        cout << "wyjechal "<< getType() << endl;
    }
};

class Parking {
private:
    int row;
    int column;
    char **arr;

    void CreatArr (){
         arr=new char* [row];
        for (int i=0; i < row; i++){
            arr[i]=new char [column];
        }
    }

    void DeleteArr (){
        for (int i=0; i < row; i++ ){
            delete [] arr [i];
        }
        delete [] arr;
    }

    void fillArr (){
        for (int i=0; i < row; i++){
            for (int j=0; j< column; j++){
                arr[i][j]='-';
            }
        }
    }

public:
    Parking (int r, int col){
        row=r;
        column=col;
        CreatArr();
        fillArr();
    }

    ~Parking (){
        DeleteArr();
    }

    void zaparkuj (int x, int y, const Pojazd* p){
                arr[x][y]=p->getType()[0];
    }

    friend ostream& operator<<(ostream& os, const Parking& p){
        for (int i=0; i < p.row; i++){
            for (int j=0; j< p.column; j++){
               os << p.arr[i][j];
            }
            os << endl;
        }
        return os;
    }

    Parking& operator -=(char x){
        for (int i=0; i < row; i++){
            for (int j=0; j< column; j++){
                if (arr[i][j]==x){
                    arr[i][j]='-';

                    if (x == 'B') {
                        cout << "wyjechal Bus" << endl;
                    } else if (x == 'S') {
                        cout << "wyjechal Samochod" << endl;
                    } else if (x == 'M') {
                        cout << "wyjechal Motocykl" << endl;
                    }
                }
            }
        }
        return *this;
    }

    operator int () const {
        int counter =0;
        for (int i=0; i < row; i++){
            for (int j=0; j < column; j++){
                if (arr[i][j]=='S'){
                    counter ++;
                }
            }
        }
        return counter;
    }
};

template <typename T>
class MyTP {
private:
    vector <T*> Pojazdy;
public:
    void dodaj (T* pojazd){
        Pojazdy.push_back(pojazd);
    }
    ~MyTP (){
        for (T* pojazd : Pojazdy){
            delete pojazd;
        }
    }

    void drukuj (){
        for (const T* pojazd : Pojazdy){
            cout << *pojazd;
        }
        cout << endl;
    }
};


#endif //POJAZD_BIBL_H
