echo $FT_NBR1 $FT_NBR2 | awk  '{ 
	gsub("’", "0", $1);
	gsub("\\", "1", $1);
	gsub("\"", "2", $1);
	gsub("?", "3", $1);
	gsub("!", "4", $1);
	gsub("m", "0",  $2);
	gsub("r", "1",  $2);
	gsub("d", "2",  $2);
	gsub("o", "3",  $2);
	gsub("c", "4",  $2);
	sum = $1 + $2;
	gsub("0", "g",  $2);
	gsub("1", "t",  $2);
	gsub("2", "a",  $2);
	gsub("3", "i",  $2);
	gsub("4", "o",  $2);
	gsub("5", "l",  $2);
	gsub("6", "u",  $2);
	gsub("7", "S",  $2);
	gsub("8", "n",  $2);
	gsub("9", "m",  $2);
	
 gtaio luSnemf
}'