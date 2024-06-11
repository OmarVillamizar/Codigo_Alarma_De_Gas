//ALARMA DE GASES INFLAMABLES OMAR VILLAMIZAR & JORGE MARLES                                                                         
#define BUZZER_PIN 3
#define SENSOR_PIN A0
#define UMBRAL_DE_ALERTA 420 // Umbral para activar el buzzer
#define TIEMPO_DE_CALENTAMIENTO 5000 // Tiempo de calentamiento en milisegundos (5 segundos)
#define DURACION_DEL_BUZZER 8000 // Duración del pitido en milisegundos (8 segundos)

void setup() {
  pinMode(BUZZER_PIN, OUTPUT); // Configura el pin del buzzer como salida
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
  digitalWrite(BUZZER_PIN, LOW); // Asegura que el buzzer esté apagado inicialmente
  delay(TIEMPO_DE_CALENTAMIENTO); // Espera el tiempo de calentamiento del sensor
}

void loop() {
  int valorDelSensor = analogRead(SENSOR_PIN); // Lee el valor analógico del sensor
  Serial.println(valorDelSensor); // Imprime el valor del sensor en la consola serial
  delay(1000); // Espera 1 segundo antes de la siguiente lectura

  if (valorDelSensor >= UMBRAL_DE_ALERTA) { // Si el valor del sensor es mayor o igual al umbral de alerta
    analogWrite(BUZZER_PIN, 240); // Enciende el buzzer con un valor PWM de 240
    delay(DURACION_DEL_BUZZER); // Mantén el buzzer encendido durante la duración especificada
  } else {
    analogWrite(BUZZER_PIN, 0); // Asegura que el buzzer esté apagado si el valor es menor al umbral de alerta
  }
}
