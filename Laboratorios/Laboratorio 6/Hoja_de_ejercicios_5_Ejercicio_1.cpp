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
	void menu(){
		int num = 0;
		cout << "Elemento a buscar: ";
		cin >> num;
		findData(sTree, num);
		
		for(int i = 0; i < lista.size(); i++){
			cout << lista.at(i) << endl;
		}
	}

};

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
    t.showTree();
    t.menu();
    
	return 0;
}
