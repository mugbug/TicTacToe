#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int checkBoard(string b) {
    char winner;

    // verificação horizontal
    if (b[0] == b[1] && b[1] == b[2]) {
        winner = b[0];
    } else if (b[3] == b[4] && b[4] == b[5]) {
        winner = b[3];
    } else if (b[6] == b[7] && b[7] == b[8]) {
        winner = b[6];
    } 
    // verificação vertical
    else if (b[0] == b[3] && b[3] == b[6]) {
        winner = b[0];
    } else if (b[1] == b[4] && b[4] == b[7]) {
        winner = b[1];
    } else if (b[2] == b[5] && b[5] == b[8]) {
        winner = b[2];
    }
    // verificação diagonal
    else if (b[0] == b[4] && b[4] == b[8]) {
        winner = b[0];
    }
    else if (b[2] == b[4] && b[4] == b[6]) {
        winner = b[2];
    } 
    // verifica se todos os campos ja foram marcados
    else if (b.find('0') > 8) {
        winner = 'E'; // empate
    }
    // caso chegue aqui, o jogo continua...
    else {
        winner = 'N'; // sem vencedor por enquanto
    }

    return winner;
}

void playSoloGame(int level) {

}

void playMultiplayerGame() {
    // inicializa algumas variáveis
    string header = "\tÉ a vez do Jogador 1\n\n";
    string game_board = "\t _________________ \n\t|     |     |     |\n\t|  1  |  2  |  3  |\n\t|_____|_____|_____|\n";
    game_board += "\t|     |     |     |\n\t|  4  |  5  |  6  |\n\t|_____|_____|_____|\n";
    game_board += "\t|     |     |     |\n\t|  7  |  8  |  9  |\n\t|_____|_____|_____|\n\n\n";
    string question = "\tEscolha um numero para marcar: ";
    // variáveis de controle
    int current_player = 1; // para verificar quem está jogando 
    char player_symbol = 'X'; // e qual o simbolo dele
    string aux_board = "000000000";
    bool game_ended = false;
    char choice;
    // repita enquanto o jogo não terminou
    do {
        cout<<header;
        cout<<game_board;
        cout<<question;
        cin>>choice;
        int position = game_board.find(choice);
        if (position > 0) {
            game_board[position] = player_symbol;
            // quadro auxiliar para facilitar a checkagem
            aux_board[choice-'0'-1] = player_symbol; // choice-'0' faz um cast de char pra int.
            if (checkBoard(aux_board) == 'X') { // player 1 venceu
                game_ended = true;
                cout<<"\n\t*************************\n\t* VITÓRIA DO JOGADOR 1! *\n\t*************************\n\n";
            } else if (checkBoard(aux_board) == 'O') { // player 2 venceu
                game_ended = true;
                cout<<"\n\t*************************\n\t* VITÓRIA DO JOGADOR 2! *\n\t*************************\n\n";
            } else if (checkBoard(aux_board) == 'E') { // empatou
                game_ended = true;
                cout<<"\n\t*************************\n\t*        EMPATOU!       *\n\t*************************\n\n";
            } else {
                system("clear || cls");// else não terminou ainda, não há o que fazer
            }
        } else {
            cout<<"*** Opção inválida, tente escolher um quadro que ainda não foi marcado! ***\n";
        }
        // atualiza as variáveis do próximo player
        if (current_player == 1) {
            current_player = 2;
            player_symbol = 'O';
            header[header.find('1')] = '2';
        } else {
            current_player = 1;
            player_symbol = 'X';
            header[header.find('2')] = '1';
        }
    } while(!game_ended);
}

void showMenu() {
    // inicializa variaveis
    system("clear || cls");
    string main_menu = "\tEscolha o tipo de jogo:\n1. Solo\n2. Multiplayer\n0. Cancelar\n>> ";
    string solo_menu = "\tEscolha o nível de dificuldade:\n1. Fácil\n2. Médio\n3. Impossível\n>> ";
    int game_type, level;

    // apresenta o menu principal
    do {
        cout<<main_menu;
        cin>>game_type;
        // limpa a tela
        system("clear || cls"); // clear para linux e cls para windows
    } while(game_type < 0 || game_type > 2);

    // age de acordo com a escolha do jogador
    switch(game_type) {
        case 1:
            // apresenta o menu de jogo solo
            do {
                cout<<solo_menu;
                cin>>level;
                system("clear || cls");
            } while(level < 1 || level > 3);
            playSoloGame(level);
            break;
        case 2:
            playMultiplayerGame();
            break;
        default:
            break;
    }
}

int main() {
    showMenu();
    return 0;
}