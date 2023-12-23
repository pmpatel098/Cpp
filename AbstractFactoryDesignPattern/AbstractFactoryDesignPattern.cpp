// AbstractFactoryDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class iButton {
    virtual void press() = 0;
};

class MacButton :public iButton {
 public:
    void press() {
        cout << "Mac button pressed" << endl;
    }
};

class WinButton :public iButton {
public:
    void press() {
        cout << "Win button pressed" << endl;
    }
};

class iTextBox {
    virtual void showtext() = 0;
};

class MacTextBox :public iTextBox {
public:
    void showtext() {
        cout << "Mac TextBox pressed" << endl;
    }
};

class WinTextBox :public iTextBox {
public:
    void showtext() {
        cout << "Win TextBox pressed" << endl;
    }
};

class IFactory {
public:
    virtual iButton* CreateButton() = 0;
    virtual iTextBox* CreateTextBox() = 0;
};

class IMacFactory:public IFactory {
public:
    iButton* CreateButton() {
        return new MacButton();
    }
    iTextBox* CreateTextBox() {
        return new MacTextBox();
    }
};

class IWinFactory :public IFactory {
public:
    iButton* CreateButton() {
        return new WinButton();
    }
    iTextBox* CreateTextBox() {
        return new WinTextBox();
    }
};

class GUIAbstractFactory {
public:
    static IFactory* CreateFactory(string str) {
        if (str == "Win")
        {
            return new IWinFactory();
        }
        else if (str == "Mac") {
            return new IMacFactory();
        }
    }
};

int main()
{
    cout << "Enter your machine OS" << endl;
    string osType;
    cin >> osType;

    IFactory *fact = GUIAbstractFactory::CreateFactory(osType);
    iButton* button = fact->CreateButton();
    button->

    iTextBox* textBox = fact->CreateTextBox();
    textBox->showtext();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
