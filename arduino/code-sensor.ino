// Conexión de los pines del sensor y el relé
const int pinSensor = A0; // El sensor está conectado al pin analógico A0
const int rele = 4; // El relé está conectado al pin digital 4

// Variables para realizar las lecturas del sensor
double Vs = 5.0; // Voltaje de alimentación del sensor --> 5V
double Vout; //Voltaje de salida
double P;
double P1;
double P2;
double Tol = 0.48; // Ajuste para calibrar la medida del sensor

// Datos solicitados
String nombreCompleto = "";
int anoNacimiento = 0;
String usuario = "";
String contrasena = "";
bool datosCompletos = false; //Variable booleana para controlar si los datos han sido completados y así poder empezar a realizar las lecturas


bool bombaActivada = false; //Variable booleana para controlar si la minibomba se ha activado

void setup() {
  Serial.begin(9600);

  pinMode(rele, OUTPUT); //Configuración del relé como salida
  digitalWrite(rele, LOW); //Inicialmente el relé está apagado
  
  Serial.println("Por favor, introduce tu nombre completo:"); // Solicita los datos al usuario
}

void loop() {
  if (!datosCompletos) {
    //Entrada de datos por pantalla
    if (Serial.available() > 0) {
      if (nombreCompleto == "") {
        nombreCompleto= Serial.readStringUntil('\n');
        Serial.print("Nombre completo: ");
        Serial.println(nombreCompleto);
        Serial.println("Introduce tu año de nacimiento:");
      } else if (anoNacimiento == 0) {
        anoNacimiento= Serial.readStringUntil('\n').toInt();
        if (anoNacimiento > 2006) {
          Serial.println("Error: Debe ser mayor de edad. Introduce nuevamente:");
          anoNacimiento=0; //Reinicio del año para volver a introducirlo
        } else {
          Serial.print("Año de nacimiento: ");
          Serial.println(anoNacimiento);
          Serial.println("Introduce tu usuario (DNI sin letras):");
        }
      } else if (usuario == "") {
        usuario = Serial.readStringUntil('\n');
        if (usuario.length() != 8) { //El DNI tiene 8 cifras
          Serial.println("Error: El usuario debe contener exactamente 8 caracteres. Introduce nuevamente:");
          usuario = ""; // Reinicia el usuario para volver a introducirlo
        } else {
          Serial.print("Usuario: ");
          Serial.println(usuario);
          Serial.println("Introduce tu contraseña (exactamente 8 caracteres):");
        }
      } else if (contrasena == "") {
        contrasena = Serial.readStringUntil('\n');
        if (contrasena.length() != 8) {
          Serial.println("Error: La contraseña debe tener 8 caracteres. Introduce nuevamente:");
          contrasena = ""; // Reinicia la contraseña para volver a introducirlo
        } else {
          Serial.print("Contraseña: ");
          for (int i = 0; i < contrasena.length(); i++) { //Bucle for para contar los caracteres introducimos y ponerlos con *
            Serial.print('*');
          }
          Serial.println();
          datosCompletos = true; //Variable booleana a true cuando los datos estén completos y correctos
          Serial.println("Datos completados. El sensor comenzará a realizar las lecturas.");
        }
      }
    }
  } else if (!bombaActivada) {
    Vout = float(analogRead(pinSensor)) * 5.0 / 1023.; // Lectura del voltaje con analogRead() --> Leemos lo que hay en el pin A0 (V)
    P = (Vout - 0.04 * Vs) / (0.09 * Vs); // Calculamos la presión (Figura 4 datasheet) kPa
    P1 = P * 7.50062; // P1 es la presión en mmHg 1kPa = 7.50062mmHg 
    P2= P1 + Tol; 

   
    Serial.print("\n\nVoltaje:");
    Serial.print(Vout);
    Serial.println(" V");
    Serial.print("Presión:");
    Serial.print(P2);
    Serial.println(" mmHg");

    if (P2 > 4.0 && !bombaActivada) { //Cuando se detecten valores superiores a 4 mmHg --> abrir mini bomba
      Serial.println("Se han detectado valores altos de presión, activando mini bomba...");
      digitalWrite(rele, HIGH); //Activa el relé para encender la minibomba
      delay(3000); 
      digitalWrite(rele, LOW); //Desactiva el relé para apagar la minibomba
      Serial.println("Mini bomba desactivada.");
      bombaActivada = true; 
      Serial.println("Prueba completada.");
    }

    delay(1000);
  }
}
