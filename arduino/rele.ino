const int rele = 4; // El relé está conectado al pin digital 4
int contador = 0; // Contador para limitar el número de veces que el relé se activa para encender la mini bomba
bool pruebaCompletada = false; // Variable booleana inicializada a false para controlar cuando la prueba ha finalizado

void setup() {
  Serial.begin(9600);
  pinMode(rele, OUTPUT); // Configuración del relé como salida
  digitalWrite(rele, LOW); // Inicialmente el relé está apagado
}

void loop() {
  if (!pruebaCompletada && contador < 2) { 

    // ACTIVAR MINI BOMBA
    Serial.println("Activando la mini bomba...");
    digitalWrite(rele, HIGH); // Activa el relé para encender la bomba durante 1,5 seg
    delay(1500); 
    
    // DESACTIVAR MINI BOMBA
    Serial.println("Bomba desactivada");
    digitalWrite(rele, LOW); // Desactiva el relé para apagar la bomba
    delay(3000);
    
    contador++;
     
  } else if (!pruebaCompletada) {
    Serial.println("Prueba completada"); 
    pruebaCompletada = true; // La prueba ha sido completada
    delay(1000); 
    return; 
  }
}
