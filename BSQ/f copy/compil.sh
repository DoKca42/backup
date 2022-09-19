rm res.txt
make
x=0
while [ $x -le 35 ]
do
    ./bsq map$x.txt >> res.txt
    echo "- "map$x.txt" runned"
    x=$(( $x + 1 ))
done
    echo "\n -- Finish --"
