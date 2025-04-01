make systolic_array ROWS=4 COLS=4 K=2 NUM_TESTS=100
mv results.log results_4_4_2_100_1.log

make systolic_array ROWS=8 COLS=8 K=2 NUM_TESTS=50
mv results.log results_8_8_2_100_1.log


echo "Bonus expect 2 passes"
cat results_4_4_2_100_1.log | grep PASSED 
cat results_8_8_2_100_1.log | grep PASSED 
make clean