#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<bool> sieve;
vector<int> primes;

void buildSieve(int n){
  sieve.resize(n + 1, true);
  sieve[0] = false, sieve[1] = false;
  for(int i = 2; i <= n; ++i){
    if(sieve[i]){
      primes.push_back(i);
      for(int j = i * 2; j <= n;  j += i)
        sieve[j] = false;
    }
  }
}

bool isPrime(int n){
  if(n < sieve.size() - 1)
    buildSieve(n);
  return sieve[n];
}

void displayPrimes(int range){
  if(range < sieve.size() - 1)
    buildSieve(range);
  int i = 0;
  if (sieve[i] <= range)
    cout << sieve[i++];
  while (sieve[i] <= range){
    cout << ", " << sieve[i++] << endl;
  }
}

void info() {
  cout << "# Prime Identifier #" << endl 
       << "-h                      : display help" << endl
       << "-i [number]             : identify if the number is prime" << endl
       << "-r [range]              : display primes in range [0..r]" << endl
       << "-l [list = {a1, a2 ..}] : find primes in the provided list" << endl;
}

bool isdigit(char c){
  return '0' <= c && c <= '9';
}

bool isValidList(string &txt){
  int state = 0, i = 0;
  char c;
  while (i < txt.size() && state != -1){
    c = txt[i++];
    cout << state << endl;
    switch (state){
      case 0:
        if (c == '{') state = 1;
        else if (c != ' ') state = -1;
        break;

      case 1:
        if (c == '}') state = 4;
        else if (isdigit(c)) state = 2;
        else if (c != ' ') state = -1;
        break;
      
      case 2:
        if (c == '}') state = 4;
        else if (c == ',') state = 1;
        else if (c == ' ') state = 3;
        else if (!isdigit(c)) state = -1;
        break;

      case 3:
        if (c == '}') state = 4;
        else if(c == ',') state = 1;
        else if (c != ' ') state = -1;
        break;
      
      case 4:
        if (c != ' ') state = -1;
    }
  }
  return state == 4;
}

vector<int> txtToList(string &txt){
  vector<int> ans;
  string aux;
  char c;
  int i = 0;
  while (txt[i++] != '{'){}
  while (txt[i] != '}'){
    c = txt[i++];
    if(isdigit(c)){
      aux += c;
    }else if(!aux.empty()){
      ans.push_back(stoi(aux));
      aux = "";
    }
  }  
}

int main() {
  string op;
  while (true) {
    info();
    cout << ">> ";
    cin >> op;
    if (op == "-h") {
      info();
    } else if (op == "-i") {
      int number;
      cin >> number;
      cout << (isPrime(number) ? "Prime" : "Not prime") << endl;
    } else if (op == "-r") {
      int range;
      cin >> range;
      displayPrimes(range);
    } else if (op == "-l") {
      int n, temp;
      string listTxt;
      vector<int> list;
      getline(cin, listTxt);
      if (isValidList(listTxt)){
        list = txtToList(listTxt);
        cout << "Valid" << endl;
      }else {
        cout << "Invalid list : \"" <<  listTxt << "\"" << endl;
      }
      for (int num : list) {
        if (isPrime(num)) {
          cout << num << " is prime" << endl;
        } else {
          cout << num << " is not prime" << endl;
        }
      }
    } else {
      cout << "Invalid option. Use -h for help.\n";
    }
  }

  return 0;
}
