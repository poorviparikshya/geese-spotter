#include "geesespotter_lib.h"
#include <iostream>


char *createBoard(std::size_t xdim, std::size_t ydim){ //done
        std::size_t capacity {xdim * ydim};
        char *board{new char[capacity]};
        for (std::size_t i{0}; i < capacity; i++){
             board[i] = 0x00;
        }

        return board;
}

void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim){
        /*
      int counter{};
      char *copyOfBoard = board;
      char inBoard [4]{0x00,0x00,0x00,0x00};
                for(int y{-1}; y <= 1; y++ ){ //iterate our y dim
                        for (int x{-1}; x <= 1; x++ ){//iterate xdim
       if (inBoard(x+1, y-1, xdim, ydim)){
               if ((board[(x+1) * xdim * (y-1)] & 0b00001111)==9) {counter++;}
       }
       if (inBoard(x+1, y, xdim, ydim)){
               if ((board[(x+1) * xdim * (y)] & 0b00001111)==9) {counter++;}
       }
       if (inBoard(x+1, y+1, xdim, ydim)){
               if ((board[(x+1) * xdim * (y+1)] & 0b00001111)==9) {counter++;}
       }
       if ((board[x+xdim*y] & 0b11110000) != 9){
               copyOfBoard [x+xdim*y] |= counter;
       }
       else{
               copyOfBoard[x+xdim*y] |= 9;
       }

       counter = 0;
       board[x+xdim+y] |= copyOfBoard[x+xdim*y];
                                //i = i + ((xdim*y)+x);
                                //board[i]++;
                
        }
       }
       */
       
}

void hideBoard(char *board, std::size_t xdim, std::size_t ydim){ //done
        for (int i{0}; i < (xdim*ydim); i++){
                board[i]|= hiddenBit();
        }
}

void cleanBoard(char *board){ //done
       delete[] board;
       board = nullptr;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim){
       
        
        for (std::size_t i{}; i < (xdim*ydim); i++){
                if (board[i] == 0x10 && board[i] == 0x12 ){
                         std::cout << ('M') << std::endl; //hidden and marked
                }else if (board[i] == 0x10){ //hidden
                        std::cout << ('*') << std::endl;
                }else {
                        std::cout << char(board[i] + 48) << std::endl;  
                }
        }


}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,
std::size_t yloc){
        std::size_t num;
        num = yloc*xdim + xloc;
        if (board[num] == 0x29 || board[num] == 0x39){ //look over conditions
                return 9;
        }else if (hiddenBit() == 0 || board[num] == 0x00){
                return 2;
        }else if ((board[num] & hiddenBit()) == hiddenBit() || board[num] == 0x10){
                return 1;
        }else{
                board[num] -= hiddenBit();
        }
        //use xloc, yloc and xdim to get to the index
        
        // return 1 id field is marked (your values will have flags on them now)
        // return 2 if the field is revealed ( aka the hidden bit is == 0)
        // if filed is a goose (AKA, look at the value of your board, and if the value ==9 , its a goose)
        //reveal the goose
        // return 9


        //if all of those are false ^^ then, remove the hiddenBit, XOR to take it off
        return 0;

}

int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,
std::size_t yloc){//done
        std::size_t num;
        num = (yloc*xdim) + xloc;
        if(board[num] <= 9){
                return 2;
        }else if (board [num] & markedBit()){
                board[num] -= markedBit();
        }else{
                board[num] += markedBit();
        }
        return 0;

}

bool isGameWon(char *board, std::size_t xdim, std::size_t ydim){
       for (int i{}; i < (xdim*ydim); i++){
               if ((board[i]) & 0b00010011 != hiddenBit()){
                       return true;
               }else{
                       return false;
               }
       }
       
      return false;
}
