const int pinSensor = A0; // El sensor está conectado al pin analógico A0

double Vs=5.0; //Voltaje de alimentación del sensor --> 5V
double Vout;
double P; 
double P1;
double P2;
double Tol=0.48; // Ajusta necesario para calibrar la medida


void setup()
{
  Serial.begin(9600);
  
}
void loop() {
    
    Vout = float(analogRead(pinSensor))*5.0/1023.; //Lectura del voltaje con analogRead() --> Leemos lo que hay en el pin A0 (V)
  
    P = (Vout-0.04*Vs) / (0.09*Vs); //Calculamos la presión (Figura 4 datasheet)kPa
    P1 = P*7.50062; //P1 es la presión en mmHg 1kPa = 7.50062mmHg 
    P2 = P1 + Tol;
    
    Serial.print("\n\nVoltaje:");
    Serial.print(Vout);
    Serial.println(" V");
    Serial.print("Presión:");
    Serial.print(P2);
    Serial.println(" mmHg");
  
    delay(5000);
    
  }
  
