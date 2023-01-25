/*******************************************************************************
* Ola, este codigo foi gerado por Livia Katzaroff e Danilo Katzaroff
*
* Tentamos resumir e comentar o máximo possível para que você possa observar
* cada pedaço do código com o melhor entendimento possível
*
*
* abaixo as considerações originais da placa robocore:
*
* RoboCore - Sweep (v1.0)
* 
* Sweep two servos simultaneously but in opposite directions.
* 
* Copyright 2021 RoboCore.
* Written by Francois (22/10/21).
* 
* 
* This file is part of the Vespa library by RoboCore ("RoboCore-Vespa-lib").
* 
* "RoboCore-Vespa-lib" is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* "RoboCore-Vespa-lib" is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public License
* along with "RoboCore-Vespa-lib". If not, see <https://www.gnu.org/licenses/>
*******************************************************************************/

// --------------------------------------------------
// Libraries

#include "RoboCore_Vespa.h"

// --------------------------------------------------
// Variables

VespaServo servo1; // atente à montagem dos servos, no nosso caso marcamos os motores para poder testar e retestar, na placa tem SV1 a SV4
VespaServo servo2;
VespaServo servo3;
VespaServo servo4;

// --------------------------------------------------

void setup(){

  // Note: some servos might require different MIN and MAX pulses (in [ms])
  //       * the default values are {1000,2000}, the maximum values are {500,2500}
  // ainda não identificamos os valores minimos e maximos dos pulsos

  servo1.attach(VESPA_SERVO_S1); // servo on pin 26, with default min and max
  servo2.attach(VESPA_SERVO_S2, 1000, 2000); // servo on pin 25, with min=1000 and max=2000
  servo3.attach(VESPA_SERVO_S3, 1000, 2000); // servo on pin 25, with min=1000 and max=2000
  servo4.attach(VESPA_SERVO_S4, 1000, 2000); // servo on pin 25, with min=1000 and max=2000
  
  delay(1500); // mantenha este delay, é importante para poder dar tempo de processamento para a placa
}




// movimento contínuo, loop, é recomendável usar ângulos de 0 a 170 para não forçar os servos

void loop(){
 
    servo1.write(20); // vira o braço para a direita
    delay(1500);
    servo4.write(100); // abre a garra
    delay(900);
    servo3.write(130); // extende o braço
    delay(1500);
    servo2.write(30); // desce o braço
    delay(900);
    servo4.write(165); // fecha a garra
    delay(1500); 
    servo2.write(160); // sobe o braço
    delay(1500);
    servo1.write(150); //vira o braço para a esquerda
    delay(1500);
    servo2.write(30); // desce o braço
    delay(1500);
    servo4.write(100); // abre a garra
    delay(1500);
    servo2.write(160); // sobe o braço
    delay(1500);
    
  }


// o código permanecerá repetindo indefinidamente, copie e cole (lembre-se de remover as barras) essa lista abaixo antes de desligar sua placa

//     servo1.write(90); // ombro para a posicao normal
//     servo2.write(90); // elevador para a posicao normal
//     servo3.write(90); // extensor para a posicao normal
//     servo4.write(90); // garra para a posicao normal
