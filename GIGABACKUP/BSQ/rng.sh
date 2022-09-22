x=1
while [ $x -le 1000 ]
do 
	perl txtgen.perl $(( $RANDOM % 100 )) $(( $RANDOM % 100 )) $(( $RANDOM % 50 )) > map$x.txt
	echo "- "map$x.txt" created"
	x=$(( $x + 1 ))
done
	while [ $x -le 1200 ]
	do 
		perl txtgen.perl $(( $RANDOM % 1000 )) $(( $RANDOM % 300)) $(( $RANDOM % 500)) > map$x.txt
		echo "- "map$x.txt" created"
		x=$(( $x + 1 ))
	done
		echo "\n -- Finish --" 
