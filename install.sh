#!/bin/bash

g++ -o helper main.cpp helper.cpp
sudo cp helper /usr/bin/
echo "alias helper='/usr/bin/./helper'" >> ~/.bashrc
source ~/.bashrc
