#Checkers in C++ using OOP\
created by Jakub Binkowski

##Description\
It is a program to play checkers for to people
Program has 5 classes: piece, white_piece, black_piece, player and game.
Piece is an abstract class, when white_piece and black_piece inherit from class piece. They store information about pawns and kings.
Player stores information whether someone has won or not. Game is the class which has information about board and number of pawns.
Program uses encapsulation to make variables safe from being changed in improper way. Polymorphizm was used to store all pieces in one vector and make some operations on them. 

##How to compile and run game?\
To run game in visual studio code configure task in cppbuild. You can just copy given json file. Then all .cpp files will be compiled. The last thing is to run main.exe file using command: ./main.exe in terminal

I hope you enjoy playing my checkers!
