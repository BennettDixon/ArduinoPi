<html>
<head>
<title>ArduinoPi Relay Network</title>
</head>

  <!-- THIS FILE IS OUR PHP WEB SERVER THAT EXECUTES THE PYTHON SCRIPTS-->

<body>

<?php
  $relay_node = $_POST['relay_node'];
  $relay_status = 'default';

  //Execute Python-relay-shutoff/turnon script and pass it RELAY_ON or RELAY_OFF, and relay_node
  if (isset($_POST['relay_on']))
  {
    exec('sudo python /var/www/html/pyt/serial_controller.py 1 RELAY_ON');
    $relay_status = 'relay_up';
  }
  elseif (isset($_POST['relay_off']))
  {
    exec('sudo python /var/www/html/pyt/serial_controller.py 1 RELAY_OFF');
    $relay_status = 'relay_down';
  }

  if ($relay_status == 'relay_up'){
    echo "<h1>Light : <bold>On</bold></h1>";
  }
  elseif ($relay_status == 'relay_down') {
    echo "<h1>Light : <bold>Off</bold></h1>";
  }
  sleep(2);
 ?>

<form action ="index.php" method ="post">
  <select name ="relay_node">
    <option value ="1">Relay 1</option>
    <option value ="2">Relay 2</option>
  </select>
  <br />
  <input type ="submit" name ="relay_on" value ="On" />
  <br />
  <input type ="submit" name ="relay_off" value ="Off" />
</form>
</body>
</html>
