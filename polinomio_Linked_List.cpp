#include <iostream>
using namespace std;

class Polinomio {
private:
	struct Node {
		float Coeficiente;
		int Grado;
		Node* siguiente;
	} * head;

public:
	Polinomio(){
        head = NULL;
    }
	void agregarPolinomio(float coef, int grad){
        Node* temp = head;
        if (temp == NULL) {
            temp = new Node;
            head = temp;
        }
        else {
            while (temp->siguiente != NULL)
                temp = temp->siguiente;
            temp->siguiente = new Node;
            temp = temp->siguiente;
        }
        temp->Coeficiente = coef;
        temp->Grado = grad;
        temp->siguiente = NULL;
    }
	void mostrarPolinomio(){
        Node* temp = head;
        int f = 0;
        
        cout << endl; 
        
        
        while (temp != NULL) { if (f != 0) { if (temp->Coeficiente > 0)
            cout << " + ";
        else
            cout << " "; } if (temp->Grado != 0)
                cout << temp->Coeficiente << "x^" << temp->Grado;
            else
                cout << temp->Coeficiente;

        
            temp = temp->siguiente;
            f = 1;
        }
    }
	void sumarPolinomio(Polinomio& l1, Polinomio& l2){
        Node* z;
        if (l1.head == NULL && l2.head == NULL)
            return;
        Node *temp1, *temp2;

        temp1 = l1.head;
        temp2 = l2.head;


        while (temp1 != NULL && temp2 != NULL) {
            if (head == NULL) {
                head = new Node;

                z = head;
            }
            else {
                z->siguiente = new Node;
                z = z->siguiente;
            }
            if (temp1->Grado < temp2->Grado) {
                z->Coeficiente = temp2->Coeficiente;
                z->Grado = temp2->Grado;

                temp2 = temp2->siguiente;
            }
            else {
                if (temp1->Grado > temp2->Grado) {
                    z->Coeficiente = temp1->Coeficiente;
                    z->Grado = temp1->Grado;

                    temp1 = temp1->siguiente;
                }
                else {

                    if (temp1->Grado == temp2->Grado) {

                        z->Coeficiente = temp1->Coeficiente + temp2->Coeficiente;
                        z->Grado = temp1->Grado;

                        temp1 = temp1->siguiente;
                        temp2 = temp2->siguiente;
                    }
                }
            }
        }
        while (temp1 != NULL) {
            if (head == NULL) {
                head = new Node;
                z = head;
            }
            else {
                z->siguiente = new Node;
                z = z->siguiente;
            }
            z->Coeficiente = temp1->Coeficiente;
            z->Grado = temp1->Grado;
            temp1 = temp1->siguiente;
        }
        while (temp2 != NULL) {
            if (head == NULL) {
                head= new Node;
                z = head;
            }
            else {
                z->siguiente = new Node;
                z = z->siguiente;
            }
            z->Coeficiente = temp2->Coeficiente;
            z->Grado = temp2->Grado;
            temp2 = temp2->siguiente;
        }
        z->siguiente = NULL;
    }
	~Polinomio(){
        Node* q;
        while (head != NULL) {
            q = head->siguiente;
            delete head;
            head = q;
        }
    }
};

int main()
{   

    cout << "\nPrimer Polinomio";
	Polinomio p1;
	p1.agregarPolinomio(2, 5);
	p1.agregarPolinomio(3, 1);
	p1.agregarPolinomio(8, 2);
	p1.agregarPolinomio(1, 4);
	p1.agregarPolinomio(4, 0);
	
	p1.mostrarPolinomio();

    cout << "\nSegundo Polinomio";
	Polinomio p2;
	p2.agregarPolinomio(3, 6);
	p2.agregarPolinomio(7, 5);
	p2.agregarPolinomio(2, 4);
	p2.agregarPolinomio(1, 3);
	p2.agregarPolinomio(9, 1);

	p2.mostrarPolinomio();

    cout << "\nPolinomio Resultante ";
	Polinomio p3;
	p3.sumarPolinomio(p1, p2);
	p3.mostrarPolinomio();
	return 0;
}
