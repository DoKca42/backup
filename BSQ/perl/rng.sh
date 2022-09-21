x=1
while [ $x -le 30 ]
do 
	perl txtgen.perl $(( $RANDOM % 100 )) $(( $RANDOM % 100 )) $(( $RANDOM % 100 )) > map$x.txt
	echo "- "map$x.txt" created"
	x=$(( $x + 1 ))
done
	while [ $x -le 35 ]
	do 
		perl txtgen.perl $(( $RANDOM % 1000 )) $(( $RANDOM % 300)) $(( $RANDOM % 500)) > map$x.txt
		echo "- "map$x.txt" created"
		x=$(( $x + 1 ))
	done
		echo "\n -- Finish --" 
