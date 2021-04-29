<?php 

$toc = 3;
$ooad = 4;
$osp = 4;
$os = 4;
$dm = 4;
$ala = 4;
$sts = 1;

echo "SUJAL GERA<br>";
echo "4th Semester Credits Details: <br>";
echo "<br>";
echo "ITE1006 - Theory Of Computation - ",$toc, " Credits<br>";
echo "ITE1007 - Object Oriented Analysis and Design - ",$ooad, " Credits<br>";
echo "ITE1008 - Open Source programming - ",$osp, " Credits<br>";
echo "ITE2002 - operating System - ",$os, " Credits<br>";
echo "ITE2006 - Data Mining Techniques - ",$dm, " Credits<br>";
echo "MAT3004 - Applied Linear Algebra - ",$ala, " Credits<br>";
echo "STS2102 - Applied Linear Algebra - ",$sts, " Credits<br>";

$total = $toc+$ooad+$osp+$os+$dm+$ala+$sts;
echo "<br>";
echo "Total Credits this sem : ",$total;

 ?>