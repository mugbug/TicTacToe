#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

// atualiza a matriz do quadro do jogo
void executeMove(char aux_board[][3], int choice, char player_symbol) {
    switch (choice) {
        case 1: aux_board[0][0] = player_symbol; break;
        case 2: aux_board[0][1] = player_symbol; break;
        case 3: aux_board[0][2] = player_symbol; break;
        case 4: aux_board[1][0] = player_symbol; break;
        case 5: aux_board[1][1] = player_symbol; break;
        case 6: aux_board[1][2] = player_symbol; break;
        case 7: aux_board[2][0] = player_symbol; break;
        case 8: aux_board[2][1] = player_symbol; break;
        case 9: aux_board[2][2] = player_symbol; break;
    }
}

int easyMove(char aux_board[][3], string game_board) {
    int position;
    char choice;
    // executa até que seja gerada uma posição válida
    do {
        choice = rand() % 9 + 1 + '0';
        position = game_board.find(choice);
    } while (position < 0);
    executeMove(aux_board, choice - '0', 'O');
    return position;
}

// verifica perigo de vitória/derrota
int * checkDanger(char b[][3], string gb) { // b ~ aux_board; gb ~ game_board

    int * position = new int[2];
    // verificação horizontal
    // linha 1
    if (b[0][1] == b[0][2]) {
        position[0] = 1;
        position[1] = gb.find(1 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][0] == b[0][2]) {
        position[0] = 2;
        position[1] = gb.find(2 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][0] == b[0][1]) {
        position[0] = 3;
        position[1] = gb.find(3 + '0');
        if (position[1] > 0) return position;
    }
    // linha 2
    if (b[1][1] == b[1][2]) {
        position[0] = 4;
        position[1] = gb.find(4 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[1][0] == b[1][2]) {
        position[0] = 5;
        position[1] = gb.find(5 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[1][0] == b[1][1]) {
        position[0] = 6;
        position[1] = gb.find(6 + '0');
        if (position[1] > 0) return position;
    }
    // linha 3
    if (b[2][1] == b[2][2]) {
        position[0] = 7;
        position[1] = gb.find(7 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[2][0] == b[2][2]) {
        position[0] = 8;
        position[1] = gb.find(8 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[2][0] == b[2][1]) {
        position[0] = 9;
        position[1] = gb.find(9 + '0');
        if (position[1] > 0) return position;
    }
    // verificação vertical
    // coluna 1
    if (b[1][0] == b[2][0]) {
        position[0] = 1;
        position[1] = gb.find(1 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][0] == b[2][0]) {
        position[0] = 4;
        position[1] = gb.find(4 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][0] == b[1][0]) {
        position[0] = 7;
        position[1] = gb.find(7 + '0');
        if (position[1] > 0) return position;
    }
    /// coluna 2
    if (b[1][1] == b[2][1]) {
        position[0] = 2;
        position[1] = gb.find(2 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][1] == b[2][1]) {
        position[0] = 5;
        position[1] = gb.find(5 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][1] == b[1][1]) {
        position[0] = 8;
        position[1] = gb.find(8 + '0');
        if (position[1] > 0) return position;
    }
    /// coluna 3
    if (b[1][2] == b[2][2]) {
        position[0] = 3;
        position[1] = gb.find(3 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][2] == b[2][2]) {
        position[0] = 6;
        position[1] = gb.find(6 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][2] == b[1][2]) {
        position[0] = 9;
        position[1] = gb.find(9 + '0');
        if (position[1] > 0) return position;
    }
    // verificação na diagonal
    // principal
    if (b[1][1] == b[2][2]) {
        position[0] = 1;
        position[1] = gb.find(1 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][0] == b[2][2]) {
        position[0] = 5;
        position[1] = gb.find(5 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][0] == b[1][1]) {
        position[0] = 9;
        position[1] = gb.find(9 + '0');
        if (position[1] > 0) return position;
    }
    // secundaria
    if (b[1][1] == b[2][0]) {
        position[0] = 3;
        position[1] = gb.find(3 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][2] == b[2][0]) {
        position[0] = 5;
        position[1] = gb.find(5 + '0');
        if (position[1] > 0) return position;
    }
    else if (b[0][2] == b[1][1]) {
        position[0] = 7;
        position[1] = gb.find(7 + '0');
        if (position[1] > 0) return position;
    }
    position[0] = 0;
    position[1] = 0;
    return position;
}

int averageMove(char b[][3], string game_board) {
    int * position = new int[2];
    position = checkDanger(b, game_board);

    if (position[0] == 0) { // sem perigo de derrota/vitória
        position[1] = easyMove(b, game_board);
    } else { // com perido de derrota/vitória
        executeMove(b, position[0], 'O');
    }
    return position[1];
}

// verifica a situação do jogo
int checkBoard(char b[][3]) {
    char winner;
    // verifica se o quadro está completo
    bool board_full = true;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            // transforma char em int
            int aux = b[i][j] - '0';
            // se houver algum numero ainda no tabuleiro
            // ainda há jogadas disponíveis
            if (aux > 0 && aux < 10)
                board_full = false;
        }
    }

    // verificação horizontal
    if (b[0][0] == b[0][1] && b[0][1] == b[0][2]) {
        winner = b[0][0];
    } else if (b[1][0] == b[1][1] && b[1][1] == b[1][2]) {
        winner = b[1][0];
    } else if (b[2][0] == b[2][1] && b[2][1] == b[2][2]) {
        winner = b[2][0];
    } 
    // verificação vertical
    else if (b[0][0] == b[1][0] && b[1][0] == b[2][0]) {
        winner = b[0][0];
    } else if (b[0][1] == b[1][1] && b[1][1] == b[2][1]) {
        winner = b[0][1];
    } else if (b[0][2] == b[1][2] && b[1][2] == b[2][2]) {
        winner = b[0][2];
    }
    // verificação diagonal
    else if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        winner = b[0][0];
    }
    else if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        winner = b[0][2];
    } 
    // verifica se todos os campos ja foram marcados
    else if (board_full) {
        winner = 'E'; // empate
    }
    // caso chegue aqui, o jogo continua...
    else {
        winner = 'N'; // sem vencedor por enquanto
    }

    return winner;
}

string generateBoard() {
    string game_board = "\t    _________________ \n\t   |     |     |     |\n\t   |  1  |  2  |  3  |\n\t   |_____|_____|_____|\n";
    game_board += "\t   |     |     |     |\n\t   |  4  |  5  |  6  |\n\t   |_____|_____|_____|\n";
    game_board += "\t   |     |     |     |\n\t   |  7  |  8  |  9  |\n\t   |_____|_____|_____|\n\n\n";
    return game_board;
}

void playGame(int level) {
    // inicializa algumas variáveis

    string header; // verifica o tipo de jogo
    if (level == 0) header = "\t   É a vez do Jogador 1\n\n";
    else header = "\t       É a sua vez!\n\n";
    string game_board = generateBoard();
    string question = "\tEscolha um número para marcar: ";

    // variáveis de controle
    int current_player = 1; // para verificar quem está jogando 
    char player_symbol = 'X'; // e qual o simbolo dele
    
    // matriz simbólica do tabuleiro
    char aux_board[3][3];
    aux_board[0][0] = '1';aux_board[0][1] = '2';aux_board[0][2] = '3';
    aux_board[1][0] = '4';aux_board[1][1] = '5';aux_board[1][2] = '6';
    aux_board[2][0] = '7';aux_board[2][1] = '8';aux_board[2][2] = '9';
    bool game_ended = false;
    
    // repita enquanto o jogo não terminou
    do {
        cout<<header;
        cout<<game_board;
        cout<<question;
        char choice;
        cin>>choice;

        // verifica se a posição escolhida está disponível
        // se estiver reproduz a jogada, se não emite um aviso
        int position = game_board.find(choice);
        if (position > 0) {
            game_board[position] = player_symbol;

            // executa a jogada
            executeMove(aux_board, choice-'0', player_symbol);

            // verifica se alguém ganhou ou se acabaram as jogadas
            char winner = checkBoard(aux_board);
            if (winner == 'X') { // player 1 venceu
                game_ended = true;
                system("clear || cls");
                cout<<"\n\t*************************\n\t* VITÓRIA DO JOGADOR 1! *\n\t*************************\n\n";
                cout<<game_board;
                break;
            } else if (winner == 'O') { // player 2 venceu
                game_ended = true;
                system("clear || cls");
                cout<<"\n\t*************************\n\t* VITÓRIA DO JOGADOR 2! *\n\t*************************\n\n";
                cout<<game_board;
                break;
            } else if (winner == 'E') { // empatou
                game_ended = true;
                system("clear || cls");
                cout<<"\n\t*************************\n\t*        EMPATOU!       *\n\t*************************\n\n";
                cout<<game_board;
                break;
            } else {
                // não terminou ainda, simplesmente limpa a tela
                // e prossegue para a próxima rodada
                system("clear || cls");
            }

            // atualiza as variáveis do próximo player
            if (level == 0) { // se for multiplayer troca o jogador
                if (current_player == 1) {
                    current_player = 2;
                    player_symbol = 'O';
                    header[header.find('1')] = '2';
                } else {
                    current_player = 1;
                    player_symbol = 'X';
                    header[header.find('2')] = '1';
                }
            } else {
                switch (level) {
                    case 1: 
                        game_board[easyMove(aux_board, game_board)] = 'O';
                        break;
                    case 2: 
                        game_board[averageMove(aux_board, game_board)] = 'O';
                        break;
                    case 3: 
                        //game_board[perfectMove(aux_board, game_board)] = 'O';
                        break;
                }
            }
        } else {
            system("clear || cls");
            cout<<"\n*** Opção inválida, tente escolher um quadro que ainda não foi marcado! ***\n\n";
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
            playGame(level);
            break;
        case 2:
            playGame(0);
            break;
        default:
            break;
    }
}

int main() {
    showMenu();
    return 0;
}