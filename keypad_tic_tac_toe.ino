#include <Keypad.h>

void printGrid();

const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
char grid[ROWS][COLS]={
  {'/','/','/','/'},
  {'/','/','/','/'},
  {'/','/','/','/'},
  {'/','/','/','/'}
};
byte rowPins[ROWS]={9,8,7,6};
byte colPins[COLS]={5,4,3,2};
Keypad teddy=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
int sentinel = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char s;
  int i,j;
  int flag = 0;
  char keypress=teddy.getKey();
  if(keypress != NO_KEY){
    for (i=0; i<4; i++){
      for (j=0; j<4; j++){
        if (teddy.isPressed(keys[i][j]))
       {   flag = 1;
          break;
       }
      }
      if (flag)
        break;
    }
    //Serial.println(keypress);
    Serial.println("next move");

    if(sentinel){
        s = 'x';
      }
      else{
        s = 'o';
        }

    grid[i][j] = s;
    printGrid();
    Serial.println();
    sentinel = !sentinel;
  }
}


void printGrid(){
    int i,j;
    for (i=0; i<4; i++){
      for (j=0; j<4; j++){
        Serial.print(grid[i][j]);
        Serial.print(" ");
      }
      Serial.println();
    }
}
