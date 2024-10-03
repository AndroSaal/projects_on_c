TEST_FILE=../tests/test/test_5.txt
SUCC_COUNTS=0
FAIL_COUNTS=0
EXECUTABLE_FILE=./s21_cat
echo " " > log.txt
function assert {

    echo "TEST №$1 STARTED" >> log.txt
    cat $CAT_ARGS $TEST_FILE > cat_result.txt
    $EXECUTABLE_FILE $S21_CAT_ARGS $TEST_FILE > s21_cat_result.txt
    diff cat_result.txt s21_cat_result.txt > cat_rusult.txt
    if [ $? -ne 0 ]; then
        echo "TEST $1 FAILED"
        echo "TEST $1 FAILED" >> log.txt
        echo "EXPECTED OUTPUT FROM CAT:" >> log.txt
        cat $CAT_ARGS $TEST_FILE >> log.txt
        echo "" >> log.txt
        echo "HAVE OUTPUT FROM s21_CAT:" >> log.txt
        $EXECUTABLE_FILE $CAT_ARGS $TEST_FILE >> log.txt
        ((FAIL_COUNTS++))
        exit
    else
        echo "TEST $1 OK"
        echo "TEST $1 OK" >> log.txt
        ((SUCC_COUNTS++))

    fi
    rm cat_result.txt s21_cat_result.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo "SUCCESS $SUCC_COUNTS/$1"
    echo "FAIL $FAIL_COUNTS/$1"

}

CAT_ARGS=""
S21_CAT_ARGS=""
assert 1

CAT_ARGS="-n"
S21_CAT_ARGS="-n"
assert 2

S21_CAT_ARGS="--number"
CAT_ARGS="-n"
assert 3

S21_CAT_ARGS="--number-nonblank"
CAT_ARGS="-b"
assert 4

S21_CAT_ARGS="--squeeze-blank"
CAT_ARGS="-s"
assert 5

S21_CAT_ARGS="--number -b"
CAT_ARGS="-n -b"
assert 6

S21_CAT_ARGS="--number-nonblank -v"
CAT_ARGS="-b -v"
assert 7

CAT_ARGS="-v -e -t -b"
S21_CAT_ARGS="-v -e -t -b"
assert 8

CAT_ARGS="-e -s"
S21_CAT_ARGS="-e -s"
assert 9

S21_CAT_ARGS="-b --squeeze-blank -b"
CAT_ARGS="-b -s -b"
assert 10

CAT_ARGS="-t"
S21_CAT_ARGS="-t"
assert 11

CAT_ARGS="-e -s"
S21_CAT_ARGS="-E -v -s"
assert 12

CAT_ARGS="-t -n -n -n -t -s"
S21_CAT_ARGS="-t -n -n -n -t -s"
assert 13
