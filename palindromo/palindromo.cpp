#include <iostream>
#include <string>

using namespace std;

class Palavra {
	char * palavra;
	char * palavraCopy;
	int size = 0;
public:
	Palavra(int sz, const char & plv);
	~Palavra();
	void inversePalavra();

	void comparePalavras();
};

Palavra::Palavra(int sz, const char& plv){
	size = sz;
	palavra = new char[sz]{0};
	palavraCopy = new char[sz]{' '};
	strcpy(palavra, &plv);
	strcpy(palavraCopy, &plv);
}
Palavra::~Palavra(){
	delete[] palavra;
	delete[] palavraCopy;
	delete this;
}
void Palavra::inversePalavra(){
	int sizeInc = 0;
	for (int i = size-1; 0 <= i; i--){
		palavraCopy[sizeInc] = palavra[i];
		sizeInc++;
	}
}

void Palavra::comparePalavras(){
	int contador = 0;
	for (int i = 0; i < size;i++){
		if (palavra[i] == palavraCopy[i])
			contador++;
		else
			break;
	}
	if (contador >= size)
		cout << "Palavra é um palindromo" << endl;
	else
		cout << "Palavra não é um palindromo" << endl;
}

int main(){
	string ch;
	
	cout << "digite uma palavra : ";
	cin >> ch;

	Palavra * pl = new Palavra(ch.size(), *ch.c_str());
	pl->inversePalavra();
	pl->comparePalavras();

	delete[] pl;
	system("pause");

	return 1;
}