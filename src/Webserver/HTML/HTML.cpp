#include <Arduino.h>


String index_html PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
<link rel="shortcut icon" href="https://i.ya-webdesign.com/images/raindrop-outline-png-6.png" type="image/png" />
<link rel="icon" href="https://i.ya-webdesign.com/images/raindrop-outline-png-6.png" type="image/png" />
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 3.0rem; }
    .units { font-size: 1.2rem; }
    .dht-labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
  </style>
</head>
<body>
  <h2>ESP32 LevelMeter</h2>
  <p>
    <i class="fas fa-arrows-alt-h"></i>
    <span class="dht-labels">Distance</span> 
    <span id="distance">%DISTANCE%</span>
    
  </p>
  <p>
    <i class="fas fa-ruler-vertical" style="color:#00add6;"></i> 
    <span class="dht-labels">Level</span>
    <span id="level">%LEVEL%</span>
  </p>
</body>
<script>
setInterval(function(){
  window.location.reload();
},2000);
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 10000 ) ;
</script>
</html>)rawliteral";