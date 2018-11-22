//打印二叉树叶子节点
#include<iostream>
using namespace std;

template<class DataType>
struct BiNode {
	DataType data;
	BiNode<DataType> *lchild, *rchild;
};

template<class DataType>
class BiTree {
public:
	BiTree() { root = Creat(root); }
	~BiTree() { Release(root); }
	void leaf() { leaf(root); }
	BiNode<DataType> *rtnRoot() { return root; }
private:
	BiNode<DataType> *root;
	BiNode<DataType> *Creat(BiNode<DataType> *bt);
	void Release(BiNode<DataType> *bt);
	void leaf(BiNode<DataType> *bt);
};

template<class DataType>
BiNode<DataType> * BiTree<DataType>::Creat(BiNode<DataType> * bt) {
	DataType ch; cin >> ch;
	if (ch == '#') bt = NULL;
	else {
		bt = new BiNode<DataType>;
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}

template<class DataType>
void BiTree<DataType>::Release(BiNode<DataType> * bt) {
	if (bt != NULL) {
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

template<class DataType>
void BiTree<DataType>::leaf(BiNode<DataType> * bt) {
	if (bt == NULL) {
		cout << "NULL";
		return;
	}
	if (bt->lchild == NULL && bt->rchild == NULL)
		cout << bt->data << " ";
	if(bt->lchild!=NULL)
		leaf(bt->lchild);
	if(bt->rchild!=NULL)
		leaf(bt->rchild);
}

int main() {
	while (1) {
		BiTree<char> tree;
		tree.leaf();
		cout << endl;
		if (tree.rtnRoot() == NULL)
			break;
	}
	return 0;
}
