<?php

// gettype and settype

$num1 = 10;
echo gettype($num1);
settype($num1, 'string');
echo gettype($num1);
echo "<br>";

$num2 = 5.23;
echo gettype($num2);
echo "\n";
settype($num2, 'integer');
echo $num2;
echo "\n";
echo gettype($num2);
echo "<br>";

$num3 = true;
echo gettype($num3);
echo "<br>";

$num4 = false;
echo gettype($num4);
echo "<br>";

$num5 = array('sujal','anmol');
echo gettype($num5);
echo "<br>";

$num6 = 'Hello';
echo gettype($num6);
echo "<br>";

$num7 = Null;
echo gettype($num7);
echo "<br>";

// Conditional Statement
// if- else

$slot = 'A1';
if($slot == 'A1'){
	echo "OSP";
}
else{
	echo "Other Subject";
}
echo "<br>";

// if - elseif

$s1 = 'B1';
if ($s1 == 'A1') {
	echo "OSP - Jayakumar S";
}
elseif ($s1 == 'B1') {
	echo "OS - Senthil Kumar";
}
elseif ($s1 == 'B2') {
	echo "ALA - Bala Anki";
}
echo "<br>";

// Switch Statements
$semester = 'Win2021';
switch ($semester) {
	case 'Fall2020':
		echo "Courses are: <br> Chem, Eng, Ethics..";
		break;

	case 'Fall2021':
		echo "Courses are: <br> DBMS, Stats, Discrete..";
		break;

	case 'Win2020':
		echo "Courses are: <br> Phy, OOPS, DSA..";
		break;

	case 'Win2021':
		echo "Courses are: <br> OS, OSP, ALA..";
		break;

	default:
		echo "Enter valid details";
		break;
}


?>