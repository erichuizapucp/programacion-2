/* 
 * File:   Menu.h
 * Author: erichuiza
 *
 * Created on November 3, 2024, 3:30 PM
 */

#ifndef MENU_H
#define MENU_H

#include "Servicio.h"

using namespace std;

template<typename T>
class Menu : public Servicio<T> {
private:
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
};

template<typename T>
Menu<T>::Menu() : Servicio<T>() {
}

template<typename T>
Menu<T>::Menu(const Menu& orig) : Servicio<T>(orig) {
    *this = orig;
}

template<typename T>
Menu<T>::~Menu() {
}

#endif /* MENU_H */

