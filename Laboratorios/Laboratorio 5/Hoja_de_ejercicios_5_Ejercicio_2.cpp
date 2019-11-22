#include <iostream>
#include<vector>

using namespace std;

vector<int>lista;

struct Node
{
    int data;
    Node *leftT;
    Node *rightT;
};

class Tree
{
    private:

        Node *sTree; //RAIZ 
    
    public:
    
        Tree()
        {
            sTree = NULL;
        }

        Node *createNode(int value)
        {
            Node *t = new Node;
            t->data = value;
            t->leftT = NULL;
            t->rightT = NULL;
            return t;
        }

        void insertNode(int value)
        {
            Node *nTree = createNode(value), *temp = sTree;
            if (!sTree)
            {
                sTree = nTree;
            }else
            {
                while (temp)
                {
                    if (value == temp->data)
                    {
                        cout << value + "already exists" << endl;
                    }else if (value < temp->data)
                    {
                        if (temp->leftT == NULL)
                        {
                            break;
                        }else
                        {
                            temp = temp->leftT;
                        }
                    }else
                    {
                        if (temp->rightT == NULL)
                        {
                            break; 
                        }else
                        {
                            temp = temp->rightT;
                        }
                    }
                }
                if (value < temp->data)
                {
                    temp->leftT = nTree;
                }else
                {
                    temp->rightT = nTree;
                }
            }
        }

        void showTree()
        {
            showTreePO(sTree);
        }

        void showTreePO(Node *t)
        {
            if (t == NULL)
            {
                return;
            }
            cout << t->data << endl;
            showTreePO(t->leftT);
            showTreePO(t->rightT);
        }
void findData(Node *t, int num)
        {
            if (t == NULL)
            {
                return;
            }
            if (t->data == num)
            {
                lista.push_back(t->data);
				return;
            }
            if (t->data < num)
            {
            	lista.push_back(t->data);
                findData(t->rightT, num);
            }else
            {
            	lista.push_back(t->data);
                findData(t->leftT, num);
            }
        }
        
        void showTreeInv()
        {
            showTreePOInv(sTree);
        }

        void showTreePOInv(Node *t)
        {
            if (t == NULL)
            {
                return;
            }
            showTreePO(t->rightT);
			cout << t->data << endl;
            showTreePO(t->leftT);
            
        }
};

void menu(Tree t){
		int num = 0;
		bool continuar = true;
		int opcion = 0;
		do{
		cout << "Elemento a buscar: ";
		cout << "\n\t1. Normal\n\t2. Invertido\n\t3. Salir" << endl;
		cout << "Su opcion: ";
		cin >> opcion;
		switch(opcion){
			case 1: t.showTree(); break; 
			case 2: t.showTreeInv(); break;
			case 3: continuar = false; break;
		}
		}while(continuar);
	}

int main(int argc, char const *argv[])
{
	int num = 0;
    Tree t;
    t.insertNode(8);
    t.insertNode(3);
    t.insertNode(10);
    t.insertNode(1);
    t.insertNode(6);
    t.insertNode(4);
    t.insertNode(7);
    t.insertNode(14);
    t.insertNode(13);
    t.insertNode(5);
    menu(t);
    
	return 0;
}
