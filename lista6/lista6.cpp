// lista6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "TreeDynamic.h"

using namespace std;

void treeTestDynamic() {
	TreeDynamic<string> tree;

	tree.getRoot()->addNewChild();
	tree.getRoot()->addNewChild();

	tree.getRoot()->getChild(0)->setValue("a");
	tree.getRoot()->getChild(1)->setValue("b");

	tree.getRoot()->getChild(0)->addNewChild();
	tree.getRoot()->getChild(0)->addNewChild();

	tree.getRoot()->getChild(0)->getChild(0)->setValue("aa");
	tree.getRoot()->getChild(0)->getChild(1)->setValue("ab");

	tree.getRoot()->getChild(1)->addNewChild();
	tree.getRoot()->getChild(1)->addNewChild();

	tree.getRoot()->getChild(1)->getChild(0)->setValue("ba");
	tree.getRoot()->getChild(1)->getChild(1)->setValue("bb");

	tree.printTree();
}

void moveSubtreeTestDynamic() {
	TreeDynamic<int> tree1;

	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();

	tree1.getRoot()->getChild(0)->setValue(1);
	tree1.getRoot()->getChild(1)->setValue(2);
	tree1.getRoot()->getChild(2)->setValue(3);

	tree1.getRoot()->getChild(2)->addNewChild();

	tree1.getRoot()->getChild(2)->getChild(0)->setValue(4);

	TreeDynamic<int> tree2;

	tree2.getRoot()->setValue(50);

	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();

	tree2.getRoot()->getChild(0)->setValue(54);
	tree2.getRoot()->getChild(1)->setValue(55);

	tree2.getRoot()->getChild(0)->addNewChild();
	tree2.getRoot()->getChild(0)->addNewChild();

	tree2.getRoot()->getChild(0)->getChild(0)->setValue(56);
	tree2.getRoot()->getChild(0)->getChild(1)->setValue(57);

	tree2.getRoot()->getChild(0)->getChild(0)->addNewChild();

	tree2.getRoot()->getChild(0)->getChild(0)->getChild(0)->setValue(58);

	tree1.printTree();
	cout << endl;
	tree2.printTree();
	cout << endl;
	if (tree1.moveSubtree(tree1.getRoot()->getChild(2), tree2.getRoot()->getChild(0))) {
		tree1.printTree();
		cout << endl;
		tree2.printTree();
		cout << endl;
	}
}

void treeTestDynamicCount() {
	double valToSearch = 2.2;
	TreeDynamic<double> tree;

	tree.getRoot()->addNewChild();
	tree.getRoot()->addNewChild();

	tree.getRoot()->getChild(0)->setValue(12.4);
	tree.getRoot()->getChild(1)->setValue(2.2);

	tree.getRoot()->getChild(0)->addNewChild();
	tree.getRoot()->getChild(0)->addNewChild();

	tree.getRoot()->getChild(0)->getChild(0)->setValue(2.1);
	tree.getRoot()->getChild(0)->getChild(1)->setValue(2.2);

	tree.getRoot()->getChild(1)->addNewChild();
	tree.getRoot()->getChild(1)->addNewChild();

	tree.getRoot()->getChild(1)->getChild(0)->setValue(1.9);
	tree.getRoot()->getChild(1)->getChild(1)->setValue(22.12);

	tree.printTree();
	cout << endl;
	cout << "Szukana wartosc: " << valToSearch << ", wystepuje: " << tree.count(valToSearch) << " razy" << endl;
}

int main() {
	treeTestDynamic();
	cout << endl << endl;
	moveSubtreeTestDynamic();
	cout << endl << endl;
	treeTestDynamicCount();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
