#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct game{
 int x, y;
 int wx, wy;
 int points;
 char **arr;
 int a, b;
 int gameover;
 int lev_gov;
}gm;

void init(gm* g){
  g->x = 1;
  g->y = 0;
  g->points = 0;
  g->gameover = 0;
  g->lev_gov = 0;
}

gm g;

void fr_matrix(){
  for(int i = 0; i < g.a; i++){
    free(g.arr[i]);
  }
  free(g.arr);
}
 
void check_point(){
  if(g.arr[g.x][g.y] == '$'){
    g.points += 3;
  }
  else if(g.arr[g.x][g.y] == '!'){
    if(g.points < 0){
      g.points = g.points * 2;
    }
    else{
      g.points = g.points / 2;
    }
  }
  else{
    g.points -= 1;
  }
}

void move(){
  switch (getchar())
  {
  case 'w':
    if (g.arr[g.x - 1][g.y] != '#' && g.arr[g.x - 1][g.y] != '-'){
      g.x--;
      check_point();
      g.arr[g.x][g.y] = '-';
      if(g.x == g.wx && g.y == g.wy){
        g.gameover = 1;
        break;
      }
      break;
    }
    else if(g.arr[g.x][g.y] == '-' && g.arr[g.x - 1][g.y] != '#'){
      check_point();
      g.arr[g.x][g.y] = ' ';
      g.x--;
      break;
    }
    break;
  case 's':
    if (g.arr[g.x + 1][g.y] != '#' && g.arr[g.x + 1][g.y] != '-'){
      g.x++;
      check_point();
      g.arr[g.x][g.y] = '-';
      if(g.x == g.wx && g.y == g.wy){
        g.gameover = 1;
      }
      break;
    }
    else if(g.arr[g.x][g.y] == '-' && g.arr[g.x + 1][g.y] != '#'){
      check_point();
      g.arr[g.x][g.y] = ' ';
      g.x++;
      break;
    }
    break;
  case 'a':
    if (g.arr[g.x][g.y - 1] != '#' && g.arr[g.x][g.y - 1] != '-'){
      g.y--;
      check_point();
      g.arr[g.x][g.y] = '-';
      if(g.x == g.wx && g.y == g.wy){
        g.gameover = 1;
      }
      break;
    }
    else if(g.arr[g.x][g.y] == '-' && g.arr[g.x][g.y - 1] != '#'){
      check_point();
      g.arr[g.x][g.y] = ' ';
      g.y--;
      break;
    }
    break;
  case 'd':
    if (g.arr[g.x][g.y + 1] != '#' && g.arr[g.x][g.y + 1] != '-'){
      g.y++;
      check_point();
      g.arr[g.x][g.y] = '-';
      if(g.x == g.wx && g.y == g.wy){
        g.gameover = 1;
      }
      break;
    }
    else if(g.arr[g.x][g.y] == '-' && g.arr[g.x][g.y + 1] != '#'){
      check_point();
      g.arr[g.x][g.y] = ' ';
      g.y++;
      break;
    }
    break;
  }
}



void printfield(){
  for(int i = 0; i < g.a; i++){
    for(int j = 0; j < g.b; j++){
      if(g.arr[i][j] == '#'){
        printf("■ ");
      }
      else if(g.arr[i][j] == ' '){
        printf("  ");
      }
      else if(g.arr[i][j] == '-'){
        printf("≡ ");
      }
      else if(g.arr[i][j] == '!'){
        printf("! ");
      }
      else if(g.arr[i][j] == '$'){
        printf("$ ");
      }
    }
    printf("\n");
  }
  printf("\n\nscore: %d", g.points);
}


void labirinto(int n){

  char arr1[10][10] =  {{'#','#','#','#','#','#','#','#','#','#'},
                        {'-',' ',' ','$','$',' ','#','#',' ','#'},
                        {'#','#','#','$','#',' ','!','#',' ','#'},
                        {'#',' ','#','!','#','#',' ','#',' ','#'},
                        {'#',' ',' ',' ',' ','#','$','#',' ','#'},
                        {'#','#','#','#','#','#',' ','$',' ','#'},
                        {'#','!',' ',' ','$',' ','$','#',' ','#'},
                        {' ','$','#','#','#','#','#','#',' ','#'},
                        {'#',' ','#',' ',' ',' ',' ',' ',' ','#'},
                        {'#','#','#','#','#','#','#','#','#','#'}};
  
  char arr2[15][15] =  {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                        {'-',' ','$',' ','!','#',' ','$','$','$','!',' ',' ',' ','#'},
                        {'#','#','#','#',' ','#',' ','#','#','#','#',' ','#',' ','#'},
                        {'#','$',' ','$',' ','#',' ','#',' ',' ','#','$','#',' ','#'},
                        {'#',' ','#','#','#','#',' ','#','#',' ','#',' ','#','#','#'},
                        {'#',' ','$',' ','!',' ','$','!','#','!','#','$','#',' ','#'},
                        {'#','#','#','#','#','#','#',' ','#','$','#',' ','#',' ','#'},
                        {'#',' ','$',' ',' ','$','#','$','#','$','#','$','#',' ',' '},
                        {'#','#','#','#','#',' ','#',' ','#','!',' ','$',' ','$','#'},
                        {'#',' ',' ',' ',' ',' ','#',' ','#','#','#','#','#','#','#'},
                        {'#',' ','#','#','#','$','!','$',' ',' ','!',' ',' ',' ','#'},
                        {'#',' ',' ',' ','#',' ','#',' ','#','#',' ','#','#',' ','#'},
                        {'#',' ','#','#','#','#','#',' ','#',' ',' ','#',' ',' ','#'},
                        {'#',' ',' ',' ','#',' ',' ',' ','#','#',' ','#','#',' ','#'},
                        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};

  char arr3[20][20] =  {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                        {'-',' ',' ',' ','$',' ',' ','$',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                        {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},
                        {'#',' ','#','$',' ','$',' ','$',' ',' ',' ',' ','#','$',' ',' ',' ','#',' ','#'},
                        {'#','$','#',' ','#','#','#','#','#','$','#',' ','#','$','#','#','!','#',' ','#'},
                        {'#',' ','#',' ','#',' ',' ','$','#','$','#','#','#','$','#','$',' ','#',' ','#'},
                        {'#',' ','#','$','#','$','#',' ','#',' ','!',' ',' ',' ','#','$','#','#','#','#'},
                        {'#','!','#',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
                        {'#','$','#','$','#',' ','#','$',' ','!',' ',' ',' ',' ','#','#','$','#','#','#'},
                        {'#','$','#','$','#',' ','#','#','#','#','#','#','#',' ',' ','#',' ','#',' ','#'},
                        {'#','!','#','$','#',' ','#',' ','#','$',' ',' ','#','#','#','#','$','#',' ','#'},
                        {'#',' ','#',' ','#','$','#',' ','#',' ','#','$','$',' ','#','#',' ','#',' ','#'},
                        {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','!',' ','#','$','#',' ','#'},
                        {'#','$','#','$','#',' ','#','$','#',' ','#','#','#','#','$','!','$','#',' ','#'},
                        {'#',' ','$',' ',' ',' ','#',' ','#','!',' ','#','$',' ',' ','#',' ','#',' ',' '},
                        {'#','#','#',' ','#','#','#',' ','#','#',' ','#','#','#','#','#',' ','#','$','#'},
                        {'#','$','#',' ',' ',' ','#','$',' ','$',' ',' ',' ',' ','#',' ',' ','#',' ','#'},
                        {'#',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#',' ','#'},
                        {'#',' ','$',' ','$',' ',' ','$',' ','!',' ',' ','$','$',' ','$',' ',' ','$','#'},
                        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};

  if(n == 1){
    g.wx = 7;
    g.wy = 0;
    g.a = 10;
    g.b = 10;
    g.arr = (char**)malloc(g.a*sizeof(char*));
    for(int i = 0; i < g.a; i++){
      g.arr[i] = (char*)malloc(g.b * sizeof(char));
      for(int j = 0; j < g.b; j++){
        g.arr[i][j] = arr1[i][j];
      }
    }
  }
  else if(n == 2){
    g.wx = 7;
    g.wy = 14;
    g.a = 15;
    g.b = 15;
    g.arr = (char**)malloc(g.a*sizeof(char*));
    for(int i = 0; i < g.a; i++){
      g.arr[i] = (char*)malloc(g.b * sizeof(char));
      for(int j = 0; j < g.b; j++){
        g.arr[i][j] = arr2[i][j];
      }
    }
  }
  else if(n == 3){
    g.wx = 14;
    g.wy = 19;
    g.a = 20;
    g.b = 20;
    g.arr = (char**)malloc(g.a*sizeof(char*));
    for(int i = 0; i < g.a; i++){
      g.arr[i] = (char*)malloc(g.b * sizeof(char));
      for(int j = 0; j < g.b; j++){
        g.arr[i][j] = arr3[i][j];
      }
    }
  }
}

void print_level(){
  printf("SELEZIONARE MODALITA DI GIOCO\n");
  printf("  1. MODALITA SELEZIONE LIVELLO SINGOLO\n");
  printf("  2. MODALITA LIVELLI CONSECUTIVI\n");
  printf("  3. MODALITA AUTOMATICA\n");
}

int main(){
  init(&g);
  int n; //selezione labirinto
  int l; //selezione modalità di gioco
  int i = 1;
  char sel;
  print_level();
  scanf("%d", &l);
  if(l == 1){
    printf("SELEZIONARE LABIRINTO\n");
    printf("  1. LABIRINTO 10X10\n");
    printf("  2. LABIRINTO 15X15\n");
    printf("  3. LABIRINTO 20X20\n");
    scanf("%d", &n);
    system("clear");
    labirinto(n);
    if(n < 4 && n > 0){
      system("stty -echo");
      system("stty -icanon");  
      while (g.gameover == 0)
      {
        printfield();
        move();
        system("clear");
      }
      printf("\nSSSSIIIIUUUUUUUUUMMMMMMMMMMMMM\n");
      fr_matrix();
      g.gameover = 0;
      printf("VUOI RIGIOCARE PORCODIO?\n Y = si \n N = no\n");
      if(getchar() == 'y'){
        return main();
      }
      else if(getchar() == 'n'){
        return 0;
      }
      else{
        printf("HAI SBAGLIATO A DIGITARE, LO PRENDO PER UN NO\n");
      }
    }
    else{
      printf("\nLIVELLO INESISTENTE\n");
      return main();
    }
  } 
  else if(l == 2){
    system("stty -echo");
    system("stty -icanon");
    while(g.lev_gov < 3){
      labirinto(i);
      while (g.gameover == 0){
        printfield();
        move();
        system("clear");
      }
      printf("\nSSSSIIIIUUUUUUUUUMMMMMMMMMMMMM\n");
      fr_matrix();
      g.x = 1;
      g.y = 0;
      system("clear");
      g.gameover = 0;
      g.lev_gov++;
      i++;
    }
    printf("HAI SUPERATO TUTTI I LIVELLI\n\n\n\n\n");
    printf("VUOI RIGIOCARE PORCODIO?\n Y = si \n N = no\n");
    if(getchar() == 'y'){
      return main();
    }
    else if(getchar() == 'n'){
      return 0;
    }
    else{
      printf("HAI SBAGLIATO A DIGITARE, LO PRENDO PER UN NO\n");
    }
  } 
  else if(l == 3){
      printf("devo ancora metterla\n\n\n");
      return 0;
  }
  else{
    printf("\nRITENTA, HAI SBAGLIATO\n");
    return main();
  }
  return 0;
}


