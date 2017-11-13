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
#include <clocale>

#include "helper.hpp"

int main() {
  setlocale(LC_ALL, "polish");

  system("clear");

  int tabelSize = possibleChoices();
  int choice = userChoice(tabelSize);

  switchChoice(choice);

  return 0;
}
