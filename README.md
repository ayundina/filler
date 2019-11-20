# filler

Filler is an algorithmic game which consists in filling a grid of a known size in advance with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid. If one of these conditions is not met, the game stops.</br></br>
Each successfully placed piece yields a number of points. The goal of the game to get the best score possible. However, it is with two players that the filler takes all his interest. Each player has for the purpose of placing as many pieces as possible while attempting to prevent his opponent from doing the same. At the end of the game, the one with the most points wins the match.</br></br>
When the game starts each player receives its starting position on the board. First player is represented by 'o' and 'O', second player is represented by 'x' and 'X'
# Usage

To download, biuld and launch the game:
```
$ git clone https://github.com/ayundina/filler.git
$ cd filler/
$ make
$ cp ayundina.filler filler_test/resources/players
$ ./filler_test/resources/filler_vm -f ./filler_test/resources/maps/map01 -p1 ./filler_test/resources/players/ayundina.filler -p2 ./filler_test/resources/players/fblom.filler
```
# Test

Fillertest launches games on 3 maps: map00 (small), map01 (medium), map02 (big). Each map launched 10 times when first player starts from position 'O' and second player from position 'X'. After that each map launched 10 times again, but starting positins of the players are now switched: first player starts from position 'X' and second player from position 'O'.</br></br>
To launch the test:
```
$ cd filler_test/
$ make
$ fillertest full/path/to/filler_test_folder player_1.filler player_2.filler
```
