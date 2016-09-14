echo "test err 1 - ligne trop longue (9e)"
../workingdir/testerr1.sh
echo

echo "test err 2 : signe bizare (-)"
../workingdir/testerr1.sh
echo 

echo "test err 3 : ligne en trop (10e)"
../workingdir/testerr1.sh
echo 

echo "test err 4 : ligne en moins"
../workingdir/testerr1.sh
echo 

echo "test err 5 : ligne trop courte (6)"
../workingdir/testerr1.sh
echo 

echo "test err 6 :  caractere espace (3e ligne)"
../workingdir/testerr1.sh
echo 
