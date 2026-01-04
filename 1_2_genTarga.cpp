#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const string parola = "auaaarolopiteco";


//funzione per controllare se la lettera è una vocale
bool contrVoc(char c){
    c = toupper(c);
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    return true;
    else
        return false;

}


//funzione per controllare se è una lettera
bool contrLet(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return true;
    else
        return false;
}


//funzione per controllare se è un numero
bool contrNum(char c){
    if(c >= '0' && c <= '9')
    return true;
    else
        return false;

}


//funzione da usare nel caso sia o una vocale o un numero
//essa scorre la parola fino a quando trova una consonante
char trovaCon(int indice) {
    while (indice < parola.size()) {
        char c = parola[indice];

        if (contrLet(c) && !contrVoc(c)) {
            return toupper(c);
        }
        indice++;
    }
}

//funzione che genera gli elementi della targa
void genera(char &prima, char &seconda, char &terza, char &quarta, int &numero){
   char gen[4];
   int num = 0;

    for(int i = 0; i<4; i++){
        num = rand()%26 + 65;
        gen[i]= char(num);
    }

 prima = parola[3];
   if (contrVoc(prima) || contrNum(prima)) {
        prima = trovaCon(3); // scorrimento parola nel caso non sia una consonante
    }

 seconda = gen[1];
    while(contrVoc(seconda)) {
        seconda = char(rand() % 26 + 65); //riassegnazione della lettera fino a quando essa sia una consonante
    }

 terza = gen[2];
 quarta = gen[3];
 numero = rand()% 900 + 100;


}
//funzione che unisce gli elementi della targa
void genTarga(char prima, char seconda, char terza, char quarta, int numero, string &targa){
targa = " ";

    targa.append(string(1,  prima));
    targa.append(string(1, seconda));
    targa.append(to_string(numero));
    targa.append(string(1, terza));
    targa.append(string(1, quarta));

    cout << "Targa: " << targa << endl;
}
void menu(){
cout << "\n---Menu'---" << endl;
cout << "1: prima funzione" << endl;
cout << "2: seconda funzione" << endl;
cout << "3: terza funzione" << endl;
cout << "4: esci" << endl;



}



void sostituisciNum(string &targa, string &targaNuova){
    targaNuova = targa;

    for(int i=0; i< targa.size(); i++){
      if(targa[i] >= '0' && targa[i] <= '9'){
        targaNuova[i]  = 'X';
      }
    }

}

void invertiTarga(string &targa, string &targaInv){

targaInv = targa;

    for(int i=0; i<targa.size(); i++){
        targaInv.at(i) = targa.at(targa.size()-1-i);
    }


}

void cercaNumero(string &targa){
string n;
cout << "inserisci numero da cercare: " << endl;
cin >> n;
if(targa.find(n) >=0 && targa.find(n) <=9){
     cout << "il numero " << n << " e' presente"<< endl;
    } else {
     cout << "il numero " << n << " non e' presente"<< endl;
    }

}

int main()
{
    char prima, seconda, terza, quarta;
    int numero, scelta;
    string targa, targaNuova, targaInv;

    srand(time(NULL));

genera(prima, seconda, terza, quarta, numero);
genTarga(prima, seconda, terza, quarta, numero, targa);

do{
    menu();
cin >> scelta;
    switch(scelta){
    case 1:
        cout << "sostituzione dei numeri della targa con 'x' " << endl;
        sostituisciNum(targa, targaNuova);
        cout << "targa vecchia: " << targa << endl;
        cout << "targa nuova: " << targaNuova << endl;
    break;
    case 2:
       cout << "inversione della targa" << endl;
       invertiTarga(targa, targaInv);
        cout << "targa vecchia: " << targa << endl;
        cout << "targa invertita: " << targaInv << endl;
    break;
    case 3:
        cout << "ricerca di un numero all'interno della targa" << endl;
        cercaNumero(targa);
    break;
    case 4:
        cout << "\nuscita." << endl;
    break;
    default:
        cout << "scegli una delle opzioni presenti" <<endl;
    break;



    }


}while(scelta !=4);


return 0;
}



