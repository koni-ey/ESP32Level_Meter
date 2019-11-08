#include <Webserver/HTML/HTML.h>
#include <WiFi.h>
#include <Webserver/Webserver.h>

const char* ssid  = "DEV-Wlan";       // Festlegung unserer SSID (Name des WLAN-Netzwerks)
const char* password = "[PASSWORT]";  // Festlegung unseres WLAN-Passworts
WiFiServer myserver(80);               // WLAN Verbindung wird über den Port80 hergestellt




void myServer::init()
{
     Serial.println();
     Serial.print("Verbinde zu ");
     Serial.print(ssid);           // Kontrollelement im seriellen Monitor
     

     WiFi.begin(ssid,password);      // Die WLAN Verbindung wird, mit der oben definierten SSID und dem zugehörigen Passwort hergestellt

   
     while (WiFi.status() != WL_CONNECTED)  // Solange noch keine WLAN-Verbindung besteht....
     {
      delay(500);
      Serial.print(".");                    // ... sollen Punkte ausgegeben werden. Die Punkte dienen als Kontrollelement.
     }

     Serial.println(" ");
     Serial.println("WiFi verbunden");   // Kontrollelement im seriellen Monitor

     myserver.begin();                     // Das NodeMCU dient nun als Mini-Webserver, auf welchem wir Daten temporär speichern können
     
     Serial.println ("Webserver laeuft, warte auf ESP..."); // Kontrollelement im seriellen Monitor

     delay(1000);                       // An dieser Stelle geben wir dem ESP-Modul 10 Sekunden Zeit für die Initialisierung
     Serial.println();
     Serial.println("Die IP-Adresse des Webservers lautet ");
     Serial.println(WiFi.localIP());     // Nun wird die sogenannte localIP ausgegeben. Diese können wir später im Webbrowser aufrufen und die Temperaturwerte ablesen.
}


void myServer::handleClient(String distance, String level)
{
    WiFiClient client = myserver.available();

    if (client) 
    {
        Serial.println("Neuer Client"); 

        while (client.connected()) 
        {
            String myString = index_html;
            myString.replace("%DISTANCE%", distance);
            myString.replace("%LEVEL%", level);
            
            client.print(myString);

            break; 
        }
    }
    delay(1000); 
    client.stop();
}

String myServer::getIp()
{
    return WiFi.localIP().toString();
}

