#include <iostream>

using namespace std;

/**
  @ class Node
  */
class Node // Класс узел
{
public:
	int index;
	Node *parent; // Указатель на родитель
	Node *children; // Указатель на ребенка
	Node *nextOneLevel; // указывает на следующего его БРАТА/СЕСТРУ

	Node() // конструктор
	{
		parent = 0;
		children = 0;
		nextOneLevel = 0;
		index = 0;
	}
/** 
  Функция - Добавить ребенка
  /*
	void addChildren(Node *child)
	{
		
		if (children==NULL)
		{
			children=child;
			child->parent = this;
		}
		else
		  {
			  Node *tmp = children;
			  while (tmp->nextOneLevel!=NULL) tmp=tmp->nextOneLevel;
			  tmp->nextOneLevel = child;
			  child->parent = this;
		  }
	}

	Node * nodeByIndex(int ind)
	{
		if (ind==index)
		{
			return this;
		}
		else
		  {
			  Node *tmp = children;
			  Node *res = NULL;
			  while ((tmp!=NULL)&&(res==NULL))
			  {
				res = tmp->nodeByIndex(ind);
				tmp = tmp->nextOneLevel;
			  }
			return res;
		}
	}
};


Node * createTree(int mas[], int cou) 
{
	Node *root;
	for (int i=0; i<cou; i++)
	{
		Node *tmp = new Node();
		tmp->index = i+1;
		if (i==0)
		{ 
			root = tmp;
		}
		else
		  {
			  Node *parent = root->nodeByIndex(mas[i]);
			  parent->addChildren(tmp);
		  }
	}
	return root;
}
/**
  Функция - Прямой порядок
  */
void Pryamoi(Node *node)
{
	cout<<node->index<<" ";
	Node * tmp = node->children;
	while (tmp!=NULL)
	{
		Pryamoi(tmp);
		tmp = tmp->nextOneLevel;
	}
}
/**
  Функция - Обратный порядок
  */
void Obratnyi(Node *node)
{
	Node * tmp = node->children;
	while (tmp!=NULL)
	{
		Obratnyi(tmp);
		tmp = tmp->nextOneLevel;
	}
	cout<<node->index<<" ";
}
/**
  Функция - Симметричный порядок
  */
void Simetrichnyi(Node *node)
{
	if (node->children!=NULL)
	{
		Simetrichnyi(node->children);
		cout<<node->index<<" ";
		Node * tmp = node->children->nextOneLevel;
		while (tmp!=NULL)
		  {
			  Simetrichnyi(tmp);
			  tmp = tmp->nextOneLevel;
		  }
	}
	else
	  {
		  cout<<node->index<<" ";
	  }
}
// главная функция
int main()
{
	int n;
	cin>>n;
	int *tarr = new int[n];
	for (int i=0; i<n; i++) 
	  {
		  cin>>tarr[i];
	  }
	Node *root = createTree(tarr, n);
	Pryamoi(root);	
	cout<<"\n";
	Obratnyi(root);
	cout<<"\n";
	Simetrichnyi(root);
	delete [] tarr;
	system("pause>>void");

	return 0;
}
