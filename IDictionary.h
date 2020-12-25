#include "BinaryTree.h"

template <class TKey, class TItem> 
class IDictionary {
private:
	//BinaryTree<TKey, TItem>* Tree;
	int Capacity;
	int Count;

public:
	BinaryTree<TKey, TItem>* Tree;

	IDictionary(int capacity = 100) {
		this->Capacity = capacity;
		this->Count = 0;
		this->Tree = new BinaryTree<TKey, TItem>();
	}

	int GetCapacity() {
		return this->Capacity;
	}
	int GetCount() {
		return this->Count;
	}

	ListSequence<TItem>* Get(TKey key) {
		ListSequence<auto>* List = this->Tree->findNode(key);
		//BinaryTree<TKey, TItem>::Node * node = this->Tree->findNode(key);
		ListSequence<auto>* ListItem = new ListSequence<auto>();
		//BinaryTree<TKey, TItem>::Node* = 
		for (int i = 0; i < List->GetSize(); i++) {

			if (List->Get(i) != nullptr) {
				ListItem->Prepend(List->Get(i)->item);
			}
			else return NULL;
		}
	}

	bool ContainsKey(TKey key) {
		return this->Tree->toCheck(key);
	}

	void Add(TKey key, TItem item) {
		this->Tree->toInsert(key, item);
		++this->Count;
	}

	// Для типов, совместимых с std::cout 
	void Print(string maintag = "", string tag = "") {
		auto list = this->Tree->Chain("LNR");

		cout << "    ";
		cout.width(20);
		cout.setf(ios::left);
		cout << maintag;
		
		cout << "    |     ";
		cout.width(6);
		cout << tag;
		cout << "  " << endl;
		cout << "============================" << "|" << "==========================" << endl;

		for (int i = 0; i < list->GetSize(); ++i) {
			cout << "    ";
			cout.width(20);
			cout.setf(ios::left);
			cout << list->Get(i)->key << "    |     ";
			cout << list->Get(i)->item << endl;
			cout << "----------------------------" << "|" << "--------------------------" << endl;
		}

		/*
		for (int i = 0; i < list->GetSize(); ++i) {
			cout << "    ";
			cout.width(20);
			cout.setf(ios::left);
			cout << list->Get(i)->key << "    |     ";
			auto List = Tree->findNode(list->Get(i)->key);
			if (List->GetSize() > 1) {
				for (int j = 0; j < List->GetSize() - 1; j++) {
					cout << List->Get(j) << ", ";
				}
				cout << List->Get(List->GetSize() - 1) << endl;
			}
			else {
				cout << list->Get(i)->item << endl;
			}
			i += List->GetSize()-1;
			delete List;
			cout << "----------------------------" << "|" << "--------------------------" << endl;
		}
		*/
		delete list;
	}


	void Remove(TKey key) {
		this->Tree->removeNode(key);
		return;
	}
};