#include "BitbloqLiquidCrystal.h"

/***   Global variables   ***/
Bitbloq::LiquidCrystal_I2C lcd(0x27,16,2); //creamos un objeto LCD

void setup()
{
  lcd.begin(); //inicializamos el LCD, 16 columnas, 2 filas
  lcd.clear(); //borramos cualquier contenido residual
  lcd.setCursor(0,0); //ponemos el cursos en la columna 0, fila 0
  lcd.print("Holas"); //imprimos este texto

}


void loop()
{
}
