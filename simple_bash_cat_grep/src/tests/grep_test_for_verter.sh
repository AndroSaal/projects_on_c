SUCC_COUNTS=0
FAIL_COUNTS=0
TEST_QUALITY=0

TEST_FILE=../tests/test/test_3.txt
GREP_PATTERN="KKKK"

echo " " > log.txt

function assert {

    ((TEST_QUALITY++))
    echo "TEST №$TEST_QUALITY STARTED" >> log.txt
    grep $GREP_ARGS $GREP_PATTERN $TEST_FILE > grep_result.txt
    ./s21_grep $GREP_ARGS $GREP_PATTERN $TEST_FILE > s21_grep_result.txt
    diff grep_result.txt s21_grep_result.txt > diff_rusult.txt
    if [ $? -ne 0 ]; then
        echo "TEST $TEST_QUALITY FAILED"
        echo "TEST $TEST_QUALITY FAILED" >> log.txt
        echo "EXPECTED OUTPUT FROM GREP:" >> log.txt
        grep $GREP_ARGS $GREP_PATTERN $TEST_FILE >> log.txt
        echo " " >> log.txt
        echo "HAVE OUTPUT FROM s21_GREP:" >> log.txt
        ./s21_grep $GREP_ARGS $GREP_PATTERN $TEST_FILE >> log.txt
        ((FAIL_COUNTS++))
        exit
    else
        echo "TEST $TEST_QUALITY OK"
        echo "TEST $TEST_QUALITY OK" >> log.txt
        ((SUCC_COUNTS++))

    fi
    echo "\n\n\n" >> log.txt

    echo "SUCCESS $SUCC_COUNTS/$TEST_QUALITY"
    echo "FAIL $FAIL_COUNTS/$TEST_QUALITY"
    rm grep_result.txt s21_grep_result.txt diff_rusult.txt log.txt
}

GREP_ARGS="-i"
assert 1

GREP_ARGS="-v"
assert 2

GREP_ARGS="-c"
assert 3

GREP_ARGS="-l"
assert 4

GREP_ARGS="-n"
assert 5

GREP_ARGS="-h"
assert 6

GREP_ARGS="-s"
assert 7

GREP_ARGS="-o"
assert 8

GREP_ARGS="-e AAA"
GREP_PATTERN=""
assert 9

GREP_ARGS="-e AAA"
GREP_PATTERN="attemp_to_give_one_more_pattern"
assert 10

GREP_ARGS="-e AAA -e VVV -e SSS"
GREP_PATTERN=""
assert 11

GREP_ARGS="-f does_not_exist_file"
GREP_PATTERN="attemp_to_give_one_more_pattern"
assert 12

GREP_ARGS="-f does_not_exist_file"
GREP_PATTERN=""
assert 13

GREP_ARGS="-f"
GREP_PATTERN="../tests/test/test_1.txt"
assert 14