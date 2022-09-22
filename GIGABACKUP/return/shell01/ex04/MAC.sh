ifconfig -a | grep 'ether' | sed 's/[[:space:]]//g' | sed 's/ether//g'
