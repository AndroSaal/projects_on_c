TEST_FILE=../tests/test/test_6.txt
SUCC_COUNTS=0
FAIL_COUNTS=0
TEST_QUALITY=0
EXECUTABLE_FILE=./s21_cat
echo " " > log.txt
function assert {

    ((TEST_QUALITY++))
    echo "TEST №$TEST_QUALITY STARTED" >> log.txt
    cat $CAT_ARGS_FOR_MACOS $TEST_FILE > cat_result.txt
    $EXECUTABLE_FILE  $CAT_ARGS_FOR_MACOS $TEST_FILE > s21_cat_result.txt
    diff cat_result.txt s21_cat_result.txt > diff_rusult.txt
    if [ $? -ne 0 ]; then
        echo "TEST $TEST_QUALITY FAILED"
        echo "TEST $TEST_QUALITY FAILED" >> log.txt
        echo "EXPECTED OUTPUT FROM CAT:" >> log.txt
        cat $CAT_ARGS_FOR_MACOS $TEST_FILE >> log.txt
        echo "" >> log.txt
        echo "HAVE OUTPUT FROM s21_CAT:" >> log.txt
        $EXECUTABLE_FILE  $CAT_ARGS_FOR_MACOS $TEST_FILE >> log.txt
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
    rm cat_result.txt s21_cat_result.txt diff_rusult.txt log.txt
}

CAT_ARGS_FOR_MACOS="-e"
assert 1

CAT_ARGS_FOR_MACOS="-b"
assert 2

CAT_ARGS_FOR_MACOS="-n"
assert 3

CAT_ARGS_FOR_MACOS="-s"
assert 4

CAT_ARGS_FOR_MACOS="-t"
assert 5

CAT_ARGS_FOR_MACOS="-v"
assert 6

CAT_ARGS_FOR_MACOS="-e -b"
assert 7

CAT_ARGS_FOR_MACOS="-e -n"
assert 8

CAT_ARGS_FOR_MACOS="-e -s"
assert 9

CAT_ARGS_FOR_MACOS="-e -t"
assert 10

CAT_ARGS_FOR_MACOS="-e -v"
assert 11

CAT_ARGS_FOR_MACOS="-b -n"
assert 12

CAT_ARGS_FOR_MACOS="-b -s"
assert 13

CAT_ARGS_FOR_MACOS="-b -t"
assert 14

CAT_ARGS_FOR_MACOS="-b -v"
assert 15

CAT_ARGS_FOR_MACOS="-n -s"
assert 16

CAT_ARGS_FOR_MACOS="-n -t"
assert 17

CAT_ARGS_FOR_MACOS="-n -v"
assert 18

CAT_ARGS_FOR_MACOS="-s -t"
assert 19

CAT_ARGS_FOR_MACOS="-s -v"
assert 20

CAT_ARGS_FOR_MACOS="-t -v"
assert 21

CAT_ARGS_FOR_MACOS="-e -b -n"
assert 22

CAT_ARGS_FOR_MACOS="-e -b -s"
assert 23

CAT_ARGS_FOR_MACOS="-e -b -t"
assert 24

CAT_ARGS_FOR_MACOS="-e -b -v"
assert 25

CAT_ARGS_FOR_MACOS="-e -n -s"
assert 26

CAT_ARGS_FOR_MACOS="-e -n -t"
assert 27

CAT_ARGS_FOR_MACOS="-e -n -v"
assert 28

CAT_ARGS_FOR_MACOS="-e -s -t"
assert 29

CAT_ARGS_FOR_MACOS="-e -s -v"
assert 30

CAT_ARGS_FOR_MACOS="-e -t -v"
assert 31

CAT_ARGS_FOR_MACOS="-b -n -s"
assert 32

CAT_ARGS_FOR_MACOS="-b -n -t"
assert 33

CAT_ARGS_FOR_MACOS="-b -n -v"
assert 34

CAT_ARGS_FOR_MACOS="-b -s -t"
assert 35

CAT_ARGS_FOR_MACOS="-b -s -v"
assert 36

CAT_ARGS_FOR_MACOS="-b -t -v"
assert 37

CAT_ARGS_FOR_MACOS="-n -s -t"
assert 38

CAT_ARGS_FOR_MACOS="-n -s -v"
assert 39

CAT_ARGS_FOR_MACOS="-n -t -v"
assert 40

CAT_ARGS_FOR_MACOS="-s -t -v"
assert 41

CAT_ARGS_FOR_MACOS="-e -b -n -s"
assert 42

CAT_ARGS_FOR_MACOS="-e -b -n -t"
assert 43

CAT_ARGS_FOR_MACOS="-e -b -n -v"
assert 44

CAT_ARGS_FOR_MACOS="-e -b -s -t"
assert 45

CAT_ARGS_FOR_MACOS="-e -b -s -v"
assert 46

CAT_ARGS_FOR_MACOS="-e -b -t -v"
assert 47

CAT_ARGS_FOR_MACOS="-e -n -s -t"
assert 48

CAT_ARGS_FOR_MACOS="-e -n -s -v"
assert 49

CAT_ARGS_FOR_MACOS="-e -n -t -v"
assert 50

CAT_ARGS_FOR_MACOS="-e -s -t -v"
assert 51

CAT_ARGS_FOR_MACOS="-b -n -s -t"
assert 52

CAT_ARGS_FOR_MACOS="-b -n -s -v"
assert 53

CAT_ARGS_FOR_MACOS="-b -n -t -v"
assert 54

CAT_ARGS_FOR_MACOS="-b -s -t -v"
assert 55

CAT_ARGS_FOR_MACOS="-n -s -t -v"
assert 56

CAT_ARGS_FOR_MACOS="-e -b -n -s -t"
assert 57

CAT_ARGS_FOR_MACOS="-e -b -n -s -v"
assert 58

CAT_ARGS_FOR_MACOS="-e -b -n -t -v"
assert 59

CAT_ARGS_FOR_MACOS="-e -b -s -t -v"
assert 60

CAT_ARGS_FOR_MACOS="-e -n -s -t -v"
assert 61

CAT_ARGS_FOR_MACOS="-b -n -s -t -v"
assert 62

CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v"
assert 63

TEST_FILE=../tests/test/test_1.txt
CAT_ARGS_FOR_MACOS="-e"
assert 1

CAT_ARGS_FOR_MACOS="-b"
assert 2

CAT_ARGS_FOR_MACOS="-n"
assert 3

CAT_ARGS_FOR_MACOS="-s"
assert 4

CAT_ARGS_FOR_MACOS="-t"
assert 5

CAT_ARGS_FOR_MACOS="-v"
assert 6

CAT_ARGS_FOR_MACOS="-e -b"
assert 7

CAT_ARGS_FOR_MACOS="-e -n"
assert 8

CAT_ARGS_FOR_MACOS="-e -s"
assert 9

CAT_ARGS_FOR_MACOS="-e -t"
assert 10

CAT_ARGS_FOR_MACOS="-e -v"
assert 11

CAT_ARGS_FOR_MACOS="-b -n"
assert 12

CAT_ARGS_FOR_MACOS="-b -s"
assert 13

CAT_ARGS_FOR_MACOS="-b -t"
assert 14

CAT_ARGS_FOR_MACOS="-b -v"
assert 15

CAT_ARGS_FOR_MACOS="-n -s"
assert 16

CAT_ARGS_FOR_MACOS="-n -t"
assert 17

CAT_ARGS_FOR_MACOS="-n -v"
assert 18

CAT_ARGS_FOR_MACOS="-s -t"
assert 19

CAT_ARGS_FOR_MACOS="-s -v"
assert 20

CAT_ARGS_FOR_MACOS="-t -v"
assert 21

CAT_ARGS_FOR_MACOS="-e -b -n"
assert 22

CAT_ARGS_FOR_MACOS="-e -b -s"
assert 23

CAT_ARGS_FOR_MACOS="-e -b -t"
assert 24

CAT_ARGS_FOR_MACOS="-e -b -v"
assert 25

CAT_ARGS_FOR_MACOS="-e -n -s"
assert 26

CAT_ARGS_FOR_MACOS="-e -n -t"
assert 27

CAT_ARGS_FOR_MACOS="-e -n -v"
assert 28

CAT_ARGS_FOR_MACOS="-e -s -t"
assert 29

CAT_ARGS_FOR_MACOS="-e -s -v"
assert 30

CAT_ARGS_FOR_MACOS="-e -t -v"
assert 31

CAT_ARGS_FOR_MACOS="-b -n -s"
assert 32

CAT_ARGS_FOR_MACOS="-b -n -t"
assert 33

CAT_ARGS_FOR_MACOS="-b -n -v"
assert 34

CAT_ARGS_FOR_MACOS="-b -s -t"
assert 35

CAT_ARGS_FOR_MACOS="-b -s -v"
assert 36

CAT_ARGS_FOR_MACOS="-b -t -v"
assert 37

CAT_ARGS_FOR_MACOS="-n -s -t"
assert 38

CAT_ARGS_FOR_MACOS="-n -s -v"
assert 39

CAT_ARGS_FOR_MACOS="-n -t -v"
assert 40

CAT_ARGS_FOR_MACOS="-s -t -v"
assert 41

CAT_ARGS_FOR_MACOS="-e -b -n -s"
assert 42

CAT_ARGS_FOR_MACOS="-e -b -n -t"
assert 43

CAT_ARGS_FOR_MACOS="-e -b -n -v"
assert 44

CAT_ARGS_FOR_MACOS="-e -b -s -t"
assert 45

CAT_ARGS_FOR_MACOS="-e -b -s -v"
assert 46

CAT_ARGS_FOR_MACOS="-e -b -t -v"
assert 47

CAT_ARGS_FOR_MACOS="-e -n -s -t"
assert 48

CAT_ARGS_FOR_MACOS="-e -n -s -v"
assert 49

CAT_ARGS_FOR_MACOS="-e -n -t -v"
assert 50

CAT_ARGS_FOR_MACOS="-e -s -t -v"
assert 51

CAT_ARGS_FOR_MACOS="-b -n -s -t"
assert 52

CAT_ARGS_FOR_MACOS="-b -n -s -v"
assert 53

CAT_ARGS_FOR_MACOS="-b -n -t -v"
assert 54

CAT_ARGS_FOR_MACOS="-b -s -t -v"
assert 55

CAT_ARGS_FOR_MACOS="-n -s -t -v"
assert 56

CAT_ARGS_FOR_MACOS="-e -b -n -s -t"
assert 57

CAT_ARGS_FOR_MACOS="-e -b -n -s -v"
assert 58

CAT_ARGS_FOR_MACOS="-e -b -n -t -v"
assert 59

CAT_ARGS_FOR_MACOS="-e -b -s -t -v"
assert 60

CAT_ARGS_FOR_MACOS="-e -n -s -t -v"
assert 61

CAT_ARGS_FOR_MACOS="-b -n -s -t -v"
assert 62

CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v"
assert 63

TEST_FILE=../tests/test/test_2.txt
CAT_ARGS_FOR_MACOS="-e"
assert 1

CAT_ARGS_FOR_MACOS="-b"
assert 2

CAT_ARGS_FOR_MACOS="-n"
assert 3

CAT_ARGS_FOR_MACOS="-s"
assert 4

CAT_ARGS_FOR_MACOS="-t"
assert 5

CAT_ARGS_FOR_MACOS="-v"
assert 6

CAT_ARGS_FOR_MACOS="-e -b"
assert 7

CAT_ARGS_FOR_MACOS="-e -n"
assert 8

CAT_ARGS_FOR_MACOS="-e -s"
assert 9

CAT_ARGS_FOR_MACOS="-e -t"
assert 10

CAT_ARGS_FOR_MACOS="-e -v"
assert 11

CAT_ARGS_FOR_MACOS="-b -n"
assert 12

CAT_ARGS_FOR_MACOS="-b -s"
assert 13

CAT_ARGS_FOR_MACOS="-b -t"
assert 14

CAT_ARGS_FOR_MACOS="-b -v"
assert 15

CAT_ARGS_FOR_MACOS="-n -s"
assert 16

CAT_ARGS_FOR_MACOS="-n -t"
assert 17

CAT_ARGS_FOR_MACOS="-n -v"
assert 18

CAT_ARGS_FOR_MACOS="-s -t"
assert 19

CAT_ARGS_FOR_MACOS="-s -v"
assert 20

CAT_ARGS_FOR_MACOS="-t -v"
assert 21

CAT_ARGS_FOR_MACOS="-e -b -n"
assert 22

CAT_ARGS_FOR_MACOS="-e -b -s"
assert 23

CAT_ARGS_FOR_MACOS="-e -b -t"
assert 24

CAT_ARGS_FOR_MACOS="-e -b -v"
assert 25

CAT_ARGS_FOR_MACOS="-e -n -s"
assert 26

CAT_ARGS_FOR_MACOS="-e -n -t"
assert 27

CAT_ARGS_FOR_MACOS="-e -n -v"
assert 28

CAT_ARGS_FOR_MACOS="-e -s -t"
assert 29

CAT_ARGS_FOR_MACOS="-e -s -v"
assert 30

CAT_ARGS_FOR_MACOS="-e -t -v"
assert 31

CAT_ARGS_FOR_MACOS="-b -n -s"
assert 32

CAT_ARGS_FOR_MACOS="-b -n -t"
assert 33

CAT_ARGS_FOR_MACOS="-b -n -v"
assert 34

CAT_ARGS_FOR_MACOS="-b -s -t"
assert 35

CAT_ARGS_FOR_MACOS="-b -s -v"
assert 36

CAT_ARGS_FOR_MACOS="-b -t -v"
assert 37

CAT_ARGS_FOR_MACOS="-n -s -t"
assert 38

CAT_ARGS_FOR_MACOS="-n -s -v"
assert 39

CAT_ARGS_FOR_MACOS="-n -t -v"
assert 40

CAT_ARGS_FOR_MACOS="-s -t -v"
assert 41

CAT_ARGS_FOR_MACOS="-e -b -n -s"
assert 42

CAT_ARGS_FOR_MACOS="-e -b -n -t"
assert 43

CAT_ARGS_FOR_MACOS="-e -b -n -v"
assert 44

CAT_ARGS_FOR_MACOS="-e -b -s -t"
assert 45

CAT_ARGS_FOR_MACOS="-e -b -s -v"
assert 46

CAT_ARGS_FOR_MACOS="-e -b -t -v"
assert 47

CAT_ARGS_FOR_MACOS="-e -n -s -t"
assert 48

CAT_ARGS_FOR_MACOS="-e -n -s -v"
assert 49

CAT_ARGS_FOR_MACOS="-e -n -t -v"
assert 50

CAT_ARGS_FOR_MACOS="-e -s -t -v"
assert 51

CAT_ARGS_FOR_MACOS="-b -n -s -t"
assert 52

CAT_ARGS_FOR_MACOS="-b -n -s -v"
assert 53

CAT_ARGS_FOR_MACOS="-b -n -t -v"
assert 54

CAT_ARGS_FOR_MACOS="-b -s -t -v"
assert 55

CAT_ARGS_FOR_MACOS="-n -s -t -v"
assert 56

CAT_ARGS_FOR_MACOS="-e -b -n -s -t"
assert 57

CAT_ARGS_FOR_MACOS="-e -b -n -s -v"
assert 58

CAT_ARGS_FOR_MACOS="-e -b -n -t -v"
assert 59

CAT_ARGS_FOR_MACOS="-e -b -s -t -v"
assert 60

CAT_ARGS_FOR_MACOS="-e -n -s -t -v"
assert 61

CAT_ARGS_FOR_MACOS="-b -n -s -t -v"
assert 62

CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v"
assert 63

TEST_FILE=../tests/test/test_3.txt
CAT_ARGS_FOR_MACOS="-e"
assert 1

CAT_ARGS_FOR_MACOS="-b"
assert 2

CAT_ARGS_FOR_MACOS="-n"
assert 3

CAT_ARGS_FOR_MACOS="-s"
assert 4

CAT_ARGS_FOR_MACOS="-t"
assert 5

CAT_ARGS_FOR_MACOS="-v"
assert 6

CAT_ARGS_FOR_MACOS="-e -b"
assert 7

CAT_ARGS_FOR_MACOS="-e -n"
assert 8

CAT_ARGS_FOR_MACOS="-e -s"
assert 9

CAT_ARGS_FOR_MACOS="-e -t"
assert 10

CAT_ARGS_FOR_MACOS="-e -v"
assert 11

CAT_ARGS_FOR_MACOS="-b -n"
assert 12

CAT_ARGS_FOR_MACOS="-b -s"
assert 13

CAT_ARGS_FOR_MACOS="-b -t"
assert 14

CAT_ARGS_FOR_MACOS="-b -v"
assert 15

CAT_ARGS_FOR_MACOS="-n -s"
assert 16

CAT_ARGS_FOR_MACOS="-n -t"
assert 17

CAT_ARGS_FOR_MACOS="-n -v"
assert 18

CAT_ARGS_FOR_MACOS="-s -t"
assert 19

CAT_ARGS_FOR_MACOS="-s -v"
assert 20

CAT_ARGS_FOR_MACOS="-t -v"
assert 21

CAT_ARGS_FOR_MACOS="-e -b -n"
assert 22

CAT_ARGS_FOR_MACOS="-e -b -s"
assert 23

CAT_ARGS_FOR_MACOS="-e -b -t"
assert 24

CAT_ARGS_FOR_MACOS="-e -b -v"
assert 25

CAT_ARGS_FOR_MACOS="-e -n -s"
assert 26

CAT_ARGS_FOR_MACOS="-e -n -t"
assert 27

CAT_ARGS_FOR_MACOS="-e -n -v"
assert 28

CAT_ARGS_FOR_MACOS="-e -s -t"
assert 29

CAT_ARGS_FOR_MACOS="-e -s -v"
assert 30

CAT_ARGS_FOR_MACOS="-e -t -v"
assert 31

CAT_ARGS_FOR_MACOS="-b -n -s"
assert 32

CAT_ARGS_FOR_MACOS="-b -n -t"
assert 33

CAT_ARGS_FOR_MACOS="-b -n -v"
assert 34

CAT_ARGS_FOR_MACOS="-b -s -t"
assert 35

CAT_ARGS_FOR_MACOS="-b -s -v"
assert 36

CAT_ARGS_FOR_MACOS="-b -t -v"
assert 37

CAT_ARGS_FOR_MACOS="-n -s -t"
assert 38

CAT_ARGS_FOR_MACOS="-n -s -v"
assert 39

CAT_ARGS_FOR_MACOS="-n -t -v"
assert 40

CAT_ARGS_FOR_MACOS="-s -t -v"
assert 41

CAT_ARGS_FOR_MACOS="-e -b -n -s"
assert 42

CAT_ARGS_FOR_MACOS="-e -b -n -t"
assert 43

CAT_ARGS_FOR_MACOS="-e -b -n -v"
assert 44

CAT_ARGS_FOR_MACOS="-e -b -s -t"
assert 45

CAT_ARGS_FOR_MACOS="-e -b -s -v"
assert 46

CAT_ARGS_FOR_MACOS="-e -b -t -v"
assert 47

CAT_ARGS_FOR_MACOS="-e -n -s -t"
assert 48

CAT_ARGS_FOR_MACOS="-e -n -s -v"
assert 49

CAT_ARGS_FOR_MACOS="-e -n -t -v"
assert 50

CAT_ARGS_FOR_MACOS="-e -s -t -v"
assert 51

CAT_ARGS_FOR_MACOS="-b -n -s -t"
assert 52

CAT_ARGS_FOR_MACOS="-b -n -s -v"
assert 53

CAT_ARGS_FOR_MACOS="-b -n -t -v"
assert 54

CAT_ARGS_FOR_MACOS="-b -s -t -v"
assert 55

CAT_ARGS_FOR_MACOS="-n -s -t -v"
assert 56

CAT_ARGS_FOR_MACOS="-e -b -n -s -t"
assert 57

CAT_ARGS_FOR_MACOS="-e -b -n -s -v"
assert 58

CAT_ARGS_FOR_MACOS="-e -b -n -t -v"
assert 59

CAT_ARGS_FOR_MACOS="-e -b -s -t -v"
assert 60

CAT_ARGS_FOR_MACOS="-e -n -s -t -v"
assert 61

CAT_ARGS_FOR_MACOS="-b -n -s -t -v"
assert 62

CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v"
assert 63


TEST_FILE=../tests/test/test_4.txt
CAT_ARGS_FOR_MACOS="-e"
assert 1

CAT_ARGS_FOR_MACOS="-b"
assert 2

CAT_ARGS_FOR_MACOS="-n"
assert 3

CAT_ARGS_FOR_MACOS="-s"
assert 4

CAT_ARGS_FOR_MACOS="-t"
assert 5

CAT_ARGS_FOR_MACOS="-v"
assert 6

CAT_ARGS_FOR_MACOS="-e -b"
assert 7

CAT_ARGS_FOR_MACOS="-e -n"
assert 8

CAT_ARGS_FOR_MACOS="-e -s"
assert 9

CAT_ARGS_FOR_MACOS="-e -t"
assert 10

CAT_ARGS_FOR_MACOS="-e -v"
assert 11

CAT_ARGS_FOR_MACOS="-b -n"
assert 12

CAT_ARGS_FOR_MACOS="-b -s"
assert 13

CAT_ARGS_FOR_MACOS="-b -t"
assert 14

CAT_ARGS_FOR_MACOS="-b -v"
assert 15

CAT_ARGS_FOR_MACOS="-n -s"
assert 16

CAT_ARGS_FOR_MACOS="-n -t"
assert 17

CAT_ARGS_FOR_MACOS="-n -v"
assert 18

CAT_ARGS_FOR_MACOS="-s -t"
assert 19

CAT_ARGS_FOR_MACOS="-s -v"
assert 20

CAT_ARGS_FOR_MACOS="-t -v"
assert 21

CAT_ARGS_FOR_MACOS="-e -b -n"
assert 22

CAT_ARGS_FOR_MACOS="-e -b -s"
assert 23

CAT_ARGS_FOR_MACOS="-e -b -t"
assert 24

CAT_ARGS_FOR_MACOS="-e -b -v"
assert 25

CAT_ARGS_FOR_MACOS="-e -n -s"
assert 26

CAT_ARGS_FOR_MACOS="-e -n -t"
assert 27

CAT_ARGS_FOR_MACOS="-e -n -v"
assert 28

CAT_ARGS_FOR_MACOS="-e -s -t"
assert 29

CAT_ARGS_FOR_MACOS="-e -s -v"
assert 30

CAT_ARGS_FOR_MACOS="-e -t -v"
assert 31

CAT_ARGS_FOR_MACOS="-b -n -s"
assert 32

CAT_ARGS_FOR_MACOS="-b -n -t"
assert 33

CAT_ARGS_FOR_MACOS="-b -n -v"
assert 34

CAT_ARGS_FOR_MACOS="-b -s -t"
assert 35

CAT_ARGS_FOR_MACOS="-b -s -v"
assert 36

CAT_ARGS_FOR_MACOS="-b -t -v"
assert 37

CAT_ARGS_FOR_MACOS="-n -s -t"
assert 38

CAT_ARGS_FOR_MACOS="-n -s -v"
assert 39

CAT_ARGS_FOR_MACOS="-n -t -v"
assert 40

CAT_ARGS_FOR_MACOS="-s -t -v"
assert 41

CAT_ARGS_FOR_MACOS="-e -b -n -s"
assert 42

CAT_ARGS_FOR_MACOS="-e -b -n -t"
assert 43

CAT_ARGS_FOR_MACOS="-e -b -n -v"
assert 44

CAT_ARGS_FOR_MACOS="-e -b -s -t"
assert 45

CAT_ARGS_FOR_MACOS="-e -b -s -v"
assert 46

CAT_ARGS_FOR_MACOS="-e -b -t -v"
assert 47

CAT_ARGS_FOR_MACOS="-e -n -s -t"
assert 48

CAT_ARGS_FOR_MACOS="-e -n -s -v"
assert 49

CAT_ARGS_FOR_MACOS="-e -n -t -v"
assert 50

CAT_ARGS_FOR_MACOS="-e -s -t -v"
assert 51

CAT_ARGS_FOR_MACOS="-b -n -s -t"
assert 52

CAT_ARGS_FOR_MACOS="-b -n -s -v"
assert 53

CAT_ARGS_FOR_MACOS="-b -n -t -v"
assert 54

CAT_ARGS_FOR_MACOS="-b -s -t -v"
assert 55

CAT_ARGS_FOR_MACOS="-n -s -t -v"
assert 56

CAT_ARGS_FOR_MACOS="-e -b -n -s -t"
assert 57

CAT_ARGS_FOR_MACOS="-e -b -n -s -v"
assert 58

CAT_ARGS_FOR_MACOS="-e -b -n -t -v"
assert 59

CAT_ARGS_FOR_MACOS="-e -b -s -t -v"
assert 60

CAT_ARGS_FOR_MACOS="-e -n -s -t -v"
assert 61

CAT_ARGS_FOR_MACOS="-b -n -s -t -v"
assert 62

CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v"
assert 63


TEST_FILE=../tests/test/test_5.txt
CAT_ARGS_FOR_MACOS="-e"
assert 1

CAT_ARGS_FOR_MACOS="-b"
assert 2

CAT_ARGS_FOR_MACOS="-n"
assert 3

CAT_ARGS_FOR_MACOS="-s"
assert 4

CAT_ARGS_FOR_MACOS="-t"
assert 5

CAT_ARGS_FOR_MACOS="-v"
assert 6

CAT_ARGS_FOR_MACOS="-e -b"
assert 7

CAT_ARGS_FOR_MACOS="-e -n"
assert 8

CAT_ARGS_FOR_MACOS="-e -s"
assert 9

CAT_ARGS_FOR_MACOS="-e -t"
assert 10

CAT_ARGS_FOR_MACOS="-e -v"
assert 11

CAT_ARGS_FOR_MACOS="-b -n"
assert 12

CAT_ARGS_FOR_MACOS="-b -s"
assert 13

CAT_ARGS_FOR_MACOS="-b -t"
assert 14

CAT_ARGS_FOR_MACOS="-b -v"
assert 15

CAT_ARGS_FOR_MACOS="-n -s"
assert 16

CAT_ARGS_FOR_MACOS="-n -t"
assert 17

CAT_ARGS_FOR_MACOS="-n -v"
assert 18

CAT_ARGS_FOR_MACOS="-s -t"
assert 19

CAT_ARGS_FOR_MACOS="-s -v"
assert 20

CAT_ARGS_FOR_MACOS="-t -v"
assert 21

CAT_ARGS_FOR_MACOS="-e -b -n"
assert 22

CAT_ARGS_FOR_MACOS="-e -b -s"
assert 23

CAT_ARGS_FOR_MACOS="-e -b -t"
assert 24

CAT_ARGS_FOR_MACOS="-e -b -v"
assert 25

CAT_ARGS_FOR_MACOS="-e -n -s"
assert 26

CAT_ARGS_FOR_MACOS="-e -n -t"
assert 27

CAT_ARGS_FOR_MACOS="-e -n -v"
assert 28

CAT_ARGS_FOR_MACOS="-e -s -t"
assert 29

CAT_ARGS_FOR_MACOS="-e -s -v"
assert 30

CAT_ARGS_FOR_MACOS="-e -t -v"
assert 31

CAT_ARGS_FOR_MACOS="-b -n -s"
assert 32

CAT_ARGS_FOR_MACOS="-b -n -t"
assert 33

CAT_ARGS_FOR_MACOS="-b -n -v"
assert 34

CAT_ARGS_FOR_MACOS="-b -s -t"
assert 35

CAT_ARGS_FOR_MACOS="-b -s -v"
assert 36

CAT_ARGS_FOR_MACOS="-b -t -v"
assert 37

CAT_ARGS_FOR_MACOS="-n -s -t"
assert 38

CAT_ARGS_FOR_MACOS="-n -s -v"
assert 39

CAT_ARGS_FOR_MACOS="-n -t -v"
assert 40

CAT_ARGS_FOR_MACOS="-s -t -v"
assert 41

CAT_ARGS_FOR_MACOS="-e -b -n -s"
assert 42

CAT_ARGS_FOR_MACOS="-e -b -n -t"
assert 43

CAT_ARGS_FOR_MACOS="-e -b -n -v"
assert 44

CAT_ARGS_FOR_MACOS="-e -b -s -t"
assert 45

CAT_ARGS_FOR_MACOS="-e -b -s -v"
assert 46

CAT_ARGS_FOR_MACOS="-e -b -t -v"
assert 47

CAT_ARGS_FOR_MACOS="-e -n -s -t"
assert 48

CAT_ARGS_FOR_MACOS="-e -n -s -v"
assert 49

CAT_ARGS_FOR_MACOS="-e -n -t -v"
assert 50

CAT_ARGS_FOR_MACOS="-e -s -t -v"
assert 51

CAT_ARGS_FOR_MACOS="-b -n -s -t"
assert 52

CAT_ARGS_FOR_MACOS="-b -n -s -v"
assert 53

CAT_ARGS_FOR_MACOS="-b -n -t -v"
assert 54

CAT_ARGS_FOR_MACOS="-b -s -t -v"
assert 55

CAT_ARGS_FOR_MACOS="-n -s -t -v"
assert 56

CAT_ARGS_FOR_MACOS="-e -b -n -s -t"
assert 57

CAT_ARGS_FOR_MACOS="-e -b -n -s -v"
assert 58

CAT_ARGS_FOR_MACOS="-e -b -n -t -v"
assert 59

CAT_ARGS_FOR_MACOS="-e -b -s -t -v"
assert 60

CAT_ARGS_FOR_MACOS="-e -n -s -t -v"
assert 61

CAT_ARGS_FOR_MACOS="-b -n -s -t -v"
assert 62

CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v"
assert 63


TEST_FILE=../tests/test/test_6.txt
CAT_ARGS_FOR_MACOS="-e"
assert 1

CAT_ARGS_FOR_MACOS="-b"
assert 2

CAT_ARGS_FOR_MACOS="-n"
assert 3

CAT_ARGS_FOR_MACOS="-s"
assert 4

CAT_ARGS_FOR_MACOS="-t"
assert 5

CAT_ARGS_FOR_MACOS="-v"
assert 6

CAT_ARGS_FOR_MACOS="-e -b"
assert 7

CAT_ARGS_FOR_MACOS="-e -n"
assert 8

CAT_ARGS_FOR_MACOS="-e -s"
assert 9

CAT_ARGS_FOR_MACOS="-e -t"
assert 10

CAT_ARGS_FOR_MACOS="-e -v"
assert 11

CAT_ARGS_FOR_MACOS="-b -n"
assert 12

CAT_ARGS_FOR_MACOS="-b -s"
assert 13

CAT_ARGS_FOR_MACOS="-b -t"
assert 14

CAT_ARGS_FOR_MACOS="-b -v"
assert 15

CAT_ARGS_FOR_MACOS="-n -s"
assert 16

CAT_ARGS_FOR_MACOS="-n -t"
assert 17

CAT_ARGS_FOR_MACOS="-n -v"
assert 18

CAT_ARGS_FOR_MACOS="-s -t"
assert 19

CAT_ARGS_FOR_MACOS="-s -v"
assert 20

CAT_ARGS_FOR_MACOS="-t -v"
assert 21

CAT_ARGS_FOR_MACOS="-e -b -n"
assert 22

CAT_ARGS_FOR_MACOS="-e -b -s"
assert 23

CAT_ARGS_FOR_MACOS="-e -b -t"
assert 24

CAT_ARGS_FOR_MACOS="-e -b -v"
assert 25

CAT_ARGS_FOR_MACOS="-e -n -s"
assert 26

CAT_ARGS_FOR_MACOS="-e -n -t"
assert 27

CAT_ARGS_FOR_MACOS="-e -n -v"
assert 28

CAT_ARGS_FOR_MACOS="-e -s -t"
assert 29

CAT_ARGS_FOR_MACOS="-e -s -v"
assert 30

CAT_ARGS_FOR_MACOS="-e -t -v"
assert 31

CAT_ARGS_FOR_MACOS="-b -n -s"
assert 32

CAT_ARGS_FOR_MACOS="-b -n -t"
assert 33

CAT_ARGS_FOR_MACOS="-b -n -v"
assert 34

CAT_ARGS_FOR_MACOS="-b -s -t"
assert 35

CAT_ARGS_FOR_MACOS="-b -s -v"
assert 36

CAT_ARGS_FOR_MACOS="-b -t -v"
assert 37

CAT_ARGS_FOR_MACOS="-n -s -t"
assert 38

CAT_ARGS_FOR_MACOS="-n -s -v"
assert 39

CAT_ARGS_FOR_MACOS="-n -t -v"
assert 40

CAT_ARGS_FOR_MACOS="-s -t -v"
assert 41

CAT_ARGS_FOR_MACOS="-e -b -n -s"
assert 42

CAT_ARGS_FOR_MACOS="-e -b -n -t"
assert 43

CAT_ARGS_FOR_MACOS="-e -b -n -v"
assert 44

CAT_ARGS_FOR_MACOS="-e -b -s -t"
assert 45

CAT_ARGS_FOR_MACOS="-e -b -s -v"
assert 46

CAT_ARGS_FOR_MACOS="-e -b -t -v"
assert 47

CAT_ARGS_FOR_MACOS="-e -n -s -t"
assert 48

CAT_ARGS_FOR_MACOS="-e -n -s -v"
assert 49

CAT_ARGS_FOR_MACOS="-e -n -t -v"
assert 50

CAT_ARGS_FOR_MACOS="-e -s -t -v"
assert 51

CAT_ARGS_FOR_MACOS="-b -n -s -t"
assert 52

CAT_ARGS_FOR_MACOS="-b -n -s -v"
assert 53

CAT_ARGS_FOR_MACOS="-b -n -t -v"
assert 54

CAT_ARGS_FOR_MACOS="-b -s -t -v"
assert 55

CAT_ARGS_FOR_MACOS="-n -s -t -v"
assert 56

CAT_ARGS_FOR_MACOS="-e -b -n -s -t"
assert 57

CAT_ARGS_FOR_MACOS="-e -b -n -s -v"
assert 58

CAT_ARGS_FOR_MACOS="-e -b -n -t -v"
assert 59

CAT_ARGS_FOR_MACOS="-e -b -s -t -v"
assert 60

CAT_ARGS_FOR_MACOS="-e -n -s -t -v"
assert 61

CAT_ARGS_FOR_MACOS="-b -n -s -t -v"
assert 62

CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v"
assert 63



TEST_FILE=test/test_does_not_exist.txt
CAT_ARGS_FOR_MACOS="-e"
assert 1


CAT_ARGS_FOR_MACOS="-b"
assert 2


CAT_ARGS_FOR_MACOS="-n"
assert 3


CAT_ARGS_FOR_MACOS="-s"
assert 4


CAT_ARGS_FOR_MACOS="-t"
assert 5


CAT_ARGS_FOR_MACOS="-v"
assert 6


CAT_ARGS_FOR_MACOS=""
assert 7


CAT_ARGS_FOR_MACOS="-zkk"
assert 8


CAT_ARGS_FOR_MACOS="-e -b"
assert 9


CAT_ARGS_FOR_MACOS="-e -n"
assert 10


CAT_ARGS_FOR_MACOS="-e -s"
assert 11


CAT_ARGS_FOR_MACOS="-e -t"
assert 12


CAT_ARGS_FOR_MACOS="-e -v"
assert 13


CAT_ARGS_FOR_MACOS="-e "
assert 14


CAT_ARGS_FOR_MACOS="-e -zkk"
assert 15


CAT_ARGS_FOR_MACOS="-b -n"
assert 16


CAT_ARGS_FOR_MACOS="-b -s"
assert 17


CAT_ARGS_FOR_MACOS="-b -t"
assert 18


CAT_ARGS_FOR_MACOS="-b -v"
assert 19


CAT_ARGS_FOR_MACOS="-b "
assert 20


CAT_ARGS_FOR_MACOS="-b -zkk"
assert 21


CAT_ARGS_FOR_MACOS="-n -s"
assert 22


CAT_ARGS_FOR_MACOS="-n -t"
assert 23


CAT_ARGS_FOR_MACOS="-n -v"
assert 24


CAT_ARGS_FOR_MACOS="-n "
assert 25


CAT_ARGS_FOR_MACOS="-n -zkk"
assert 26


CAT_ARGS_FOR_MACOS="-s -t"
assert 27


CAT_ARGS_FOR_MACOS="-s -v"
assert 28


CAT_ARGS_FOR_MACOS="-s "
assert 29


CAT_ARGS_FOR_MACOS="-s -zkk"
assert 30


CAT_ARGS_FOR_MACOS="-t -v"
assert 31


CAT_ARGS_FOR_MACOS="-t "
assert 32


CAT_ARGS_FOR_MACOS="-t -zkk"
assert 33


CAT_ARGS_FOR_MACOS="-v "
assert 34


CAT_ARGS_FOR_MACOS="-v -zkk"
assert 35


CAT_ARGS_FOR_MACOS=" -zkk"
assert 36


CAT_ARGS_FOR_MACOS="-e -b -n"
assert 37


CAT_ARGS_FOR_MACOS="-e -b -s"
assert 38


CAT_ARGS_FOR_MACOS="-e -b -t"
assert 39


CAT_ARGS_FOR_MACOS="-e -b -v"
assert 40


CAT_ARGS_FOR_MACOS="-e -b "
assert 41


CAT_ARGS_FOR_MACOS="-e -b -zkk"
assert 42


CAT_ARGS_FOR_MACOS="-e -n -s"
assert 43


CAT_ARGS_FOR_MACOS="-e -n -t"
assert 44


CAT_ARGS_FOR_MACOS="-e -n -v"
assert 45


CAT_ARGS_FOR_MACOS="-e -n "
assert 46


CAT_ARGS_FOR_MACOS="-e -n -zkk"
assert 47


CAT_ARGS_FOR_MACOS="-e -s -t"
assert 48


CAT_ARGS_FOR_MACOS="-e -s -v"
assert 49


CAT_ARGS_FOR_MACOS="-e -s "
assert 50


CAT_ARGS_FOR_MACOS="-e -s -zkk"
assert 51


CAT_ARGS_FOR_MACOS="-e -t -v"
assert 52


CAT_ARGS_FOR_MACOS="-e -t "
assert 53


CAT_ARGS_FOR_MACOS="-e -t -zkk"
assert 54


CAT_ARGS_FOR_MACOS="-e -v "
assert 55


CAT_ARGS_FOR_MACOS="-e -v -zkk"
assert 56


CAT_ARGS_FOR_MACOS="-e  -zkk"
assert 57


CAT_ARGS_FOR_MACOS="-b -n -s"
assert 58


CAT_ARGS_FOR_MACOS="-b -n -t"
assert 59


CAT_ARGS_FOR_MACOS="-b -n -v"
assert 60


CAT_ARGS_FOR_MACOS="-b -n "
assert 61


CAT_ARGS_FOR_MACOS="-b -n -zkk"
assert 62


CAT_ARGS_FOR_MACOS="-b -s -t"
assert 63


CAT_ARGS_FOR_MACOS="-b -s -v"
assert 64


CAT_ARGS_FOR_MACOS="-b -s "
assert 65


CAT_ARGS_FOR_MACOS="-b -s -zkk"
assert 66


CAT_ARGS_FOR_MACOS="-b -t -v"
assert 67


CAT_ARGS_FOR_MACOS="-b -t "
assert 68


CAT_ARGS_FOR_MACOS="-b -t -zkk"
assert 69


CAT_ARGS_FOR_MACOS="-b -v "
assert 70


CAT_ARGS_FOR_MACOS="-b -v -zkk"
assert 71


CAT_ARGS_FOR_MACOS="-b  -zkk"
assert 72


CAT_ARGS_FOR_MACOS="-n -s -t"
assert 73


CAT_ARGS_FOR_MACOS="-n -s -v"
assert 74


CAT_ARGS_FOR_MACOS="-n -s "
assert 75


CAT_ARGS_FOR_MACOS="-n -s -zkk"
assert 76


CAT_ARGS_FOR_MACOS="-n -t -v"
assert 77


CAT_ARGS_FOR_MACOS="-n -t "
assert 78


CAT_ARGS_FOR_MACOS="-n -t -zkk"
assert 79


CAT_ARGS_FOR_MACOS="-n -v "
assert 80


CAT_ARGS_FOR_MACOS="-n -v -zkk"
assert 81


CAT_ARGS_FOR_MACOS="-n  -zkk"
assert 82


CAT_ARGS_FOR_MACOS="-s -t -v"
assert 83


CAT_ARGS_FOR_MACOS="-s -t "
assert 84


CAT_ARGS_FOR_MACOS="-s -t -zkk"
assert 85


CAT_ARGS_FOR_MACOS="-s -v "
assert 86


CAT_ARGS_FOR_MACOS="-s -v -zkk"
assert 87


CAT_ARGS_FOR_MACOS="-s  -zkk"
assert 88


CAT_ARGS_FOR_MACOS="-t -v "
assert 89


CAT_ARGS_FOR_MACOS="-t -v -zkk"
assert 90


CAT_ARGS_FOR_MACOS="-t  -zkk"
assert 91


CAT_ARGS_FOR_MACOS="-v  -zkk"
assert 92


CAT_ARGS_FOR_MACOS="-e -b -n -s"
assert 93


CAT_ARGS_FOR_MACOS="-e -b -n -t"
assert 94


CAT_ARGS_FOR_MACOS="-e -b -n -v"
assert 95


CAT_ARGS_FOR_MACOS="-e -b -n "
assert 96


CAT_ARGS_FOR_MACOS="-e -b -n -zkk"
assert 97


CAT_ARGS_FOR_MACOS="-e -b -s -t"
assert 98


CAT_ARGS_FOR_MACOS="-e -b -s -v"
assert 99


CAT_ARGS_FOR_MACOS="-e -b -s "
assert 100


CAT_ARGS_FOR_MACOS="-e -b -s -zkk"
assert 101


CAT_ARGS_FOR_MACOS="-e -b -t -v"
assert 102


CAT_ARGS_FOR_MACOS="-e -b -t "
assert 103


CAT_ARGS_FOR_MACOS="-e -b -t -zkk"
assert 104


CAT_ARGS_FOR_MACOS="-e -b -v "
assert 105


CAT_ARGS_FOR_MACOS="-e -b -v -zkk"
assert 106


CAT_ARGS_FOR_MACOS="-e -b  -zkk"
assert 107


CAT_ARGS_FOR_MACOS="-e -n -s -t"
assert 108


CAT_ARGS_FOR_MACOS="-e -n -s -v"
assert 109


CAT_ARGS_FOR_MACOS="-e -n -s "
assert 110


CAT_ARGS_FOR_MACOS="-e -n -s -zkk"
assert 111


CAT_ARGS_FOR_MACOS="-e -n -t -v"
assert 112


CAT_ARGS_FOR_MACOS="-e -n -t "
assert 113


CAT_ARGS_FOR_MACOS="-e -n -t -zkk"
assert 114


CAT_ARGS_FOR_MACOS="-e -n -v "
assert 115


CAT_ARGS_FOR_MACOS="-e -n -v -zkk"
assert 116


CAT_ARGS_FOR_MACOS="-e -n  -zkk"
assert 117


CAT_ARGS_FOR_MACOS="-e -s -t -v"
assert 118


CAT_ARGS_FOR_MACOS="-e -s -t "
assert 119


CAT_ARGS_FOR_MACOS="-e -s -t -zkk"
assert 120


CAT_ARGS_FOR_MACOS="-e -s -v "
assert 121


CAT_ARGS_FOR_MACOS="-e -s -v -zkk"
assert 122


CAT_ARGS_FOR_MACOS="-e -s  -zkk"
assert 123


CAT_ARGS_FOR_MACOS="-e -t -v "
assert 124


CAT_ARGS_FOR_MACOS="-e -t -v -zkk"
assert 125


CAT_ARGS_FOR_MACOS="-e -t  -zkk"
assert 126


CAT_ARGS_FOR_MACOS="-e -v  -zkk"
assert 127


CAT_ARGS_FOR_MACOS="-b -n -s -t"
assert 128


CAT_ARGS_FOR_MACOS="-b -n -s -v"
assert 129


CAT_ARGS_FOR_MACOS="-b -n -s "
assert 130


CAT_ARGS_FOR_MACOS="-b -n -s -zkk"
assert 131


CAT_ARGS_FOR_MACOS="-b -n -t -v"
assert 132


CAT_ARGS_FOR_MACOS="-b -n -t "
assert 133


CAT_ARGS_FOR_MACOS="-b -n -t -zkk"
assert 134


CAT_ARGS_FOR_MACOS="-b -n -v "
assert 135


CAT_ARGS_FOR_MACOS="-b -n -v -zkk"
assert 136


CAT_ARGS_FOR_MACOS="-b -n  -zkk"
assert 137


CAT_ARGS_FOR_MACOS="-b -s -t -v"
assert 138


CAT_ARGS_FOR_MACOS="-b -s -t "
assert 139


CAT_ARGS_FOR_MACOS="-b -s -t -zkk"
assert 140


CAT_ARGS_FOR_MACOS="-b -s -v "
assert 141


CAT_ARGS_FOR_MACOS="-b -s -v -zkk"
assert 142


CAT_ARGS_FOR_MACOS="-b -s  -zkk"
assert 143


CAT_ARGS_FOR_MACOS="-b -t -v "
assert 144


CAT_ARGS_FOR_MACOS="-b -t -v -zkk"
assert 145


CAT_ARGS_FOR_MACOS="-b -t  -zkk"
assert 146


CAT_ARGS_FOR_MACOS="-b -v  -zkk"
assert 147


CAT_ARGS_FOR_MACOS="-n -s -t -v"
assert 148


CAT_ARGS_FOR_MACOS="-n -s -t "
assert 149


CAT_ARGS_FOR_MACOS="-n -s -t -zkk"
assert 150


CAT_ARGS_FOR_MACOS="-n -s -v "
assert 151


CAT_ARGS_FOR_MACOS="-n -s -v -zkk"
assert 152


CAT_ARGS_FOR_MACOS="-n -s  -zkk"
assert 153


CAT_ARGS_FOR_MACOS="-n -t -v "
assert 154


CAT_ARGS_FOR_MACOS="-n -t -v -zkk"
assert 155


CAT_ARGS_FOR_MACOS="-n -t  -zkk"
assert 156


CAT_ARGS_FOR_MACOS="-n -v  -zkk"
assert 157


CAT_ARGS_FOR_MACOS="-s -t -v "
assert 158


CAT_ARGS_FOR_MACOS="-s -t -v -zkk"
assert 159


CAT_ARGS_FOR_MACOS="-s -t  -zkk"
assert 160


CAT_ARGS_FOR_MACOS="-s -v  -zkk"
assert 161


CAT_ARGS_FOR_MACOS="-t -v  -zkk"
assert 162


CAT_ARGS_FOR_MACOS="-e -b -n -s -t"
assert 163


CAT_ARGS_FOR_MACOS="-e -b -n -s -v"
assert 164


CAT_ARGS_FOR_MACOS="-e -b -n -s "
assert 165


CAT_ARGS_FOR_MACOS="-e -b -n -s -zkk"
assert 166


CAT_ARGS_FOR_MACOS="-e -b -n -t -v"
assert 167


CAT_ARGS_FOR_MACOS="-e -b -n -t "
assert 168


CAT_ARGS_FOR_MACOS="-e -b -n -t -zkk"
assert 169


CAT_ARGS_FOR_MACOS="-e -b -n -v "
assert 170


CAT_ARGS_FOR_MACOS="-e -b -n -v -zkk"
assert 171


CAT_ARGS_FOR_MACOS="-e -b -n  -zkk"
assert 172


CAT_ARGS_FOR_MACOS="-e -b -s -t -v"
assert 173


CAT_ARGS_FOR_MACOS="-e -b -s -t "
assert 174


CAT_ARGS_FOR_MACOS="-e -b -s -t -zkk"
assert 175


CAT_ARGS_FOR_MACOS="-e -b -s -v "
assert 176


CAT_ARGS_FOR_MACOS="-e -b -s -v -zkk"
assert 177


CAT_ARGS_FOR_MACOS="-e -b -s  -zkk"
assert 178


CAT_ARGS_FOR_MACOS="-e -b -t -v "
assert 179


CAT_ARGS_FOR_MACOS="-e -b -t -v -zkk"
assert 180


CAT_ARGS_FOR_MACOS="-e -b -t  -zkk"
assert 181


CAT_ARGS_FOR_MACOS="-e -b -v  -zkk"
assert 182


CAT_ARGS_FOR_MACOS="-e -n -s -t -v"
assert 183


CAT_ARGS_FOR_MACOS="-e -n -s -t "
assert 184


CAT_ARGS_FOR_MACOS="-e -n -s -t -zkk"
assert 185


CAT_ARGS_FOR_MACOS="-e -n -s -v "
assert 186


CAT_ARGS_FOR_MACOS="-e -n -s -v -zkk"
assert 187


CAT_ARGS_FOR_MACOS="-e -n -s  -zkk"
assert 188


CAT_ARGS_FOR_MACOS="-e -n -t -v "
assert 189


CAT_ARGS_FOR_MACOS="-e -n -t -v -zkk"
assert 190


CAT_ARGS_FOR_MACOS="-e -n -t  -zkk"
assert 191


CAT_ARGS_FOR_MACOS="-e -n -v  -zkk"
assert 192


CAT_ARGS_FOR_MACOS="-e -s -t -v "
assert 193


CAT_ARGS_FOR_MACOS="-e -s -t -v -zkk"
assert 194


CAT_ARGS_FOR_MACOS="-e -s -t  -zkk"
assert 195


CAT_ARGS_FOR_MACOS="-e -s -v  -zkk"
assert 196


CAT_ARGS_FOR_MACOS="-e -t -v  -zkk"
assert 197


CAT_ARGS_FOR_MACOS="-b -n -s -t -v"
assert 198


CAT_ARGS_FOR_MACOS="-b -n -s -t "
assert 199


CAT_ARGS_FOR_MACOS="-b -n -s -t -zkk"
assert 200


CAT_ARGS_FOR_MACOS="-b -n -s -v "
assert 201


CAT_ARGS_FOR_MACOS="-b -n -s -v -zkk"
assert 202


CAT_ARGS_FOR_MACOS="-b -n -s  -zkk"
assert 203


CAT_ARGS_FOR_MACOS="-b -n -t -v "
assert 204


CAT_ARGS_FOR_MACOS="-b -n -t -v -zkk"
assert 205


CAT_ARGS_FOR_MACOS="-b -n -t  -zkk"
assert 206


CAT_ARGS_FOR_MACOS="-b -n -v  -zkk"
assert 207


CAT_ARGS_FOR_MACOS="-b -s -t -v "
assert 208


CAT_ARGS_FOR_MACOS="-b -s -t -v -zkk"
assert 209


CAT_ARGS_FOR_MACOS="-b -s -t  -zkk"
assert 210


CAT_ARGS_FOR_MACOS="-b -s -v  -zkk"
assert 211


CAT_ARGS_FOR_MACOS="-b -t -v  -zkk"
assert 212


CAT_ARGS_FOR_MACOS="-n -s -t -v "
assert 213


CAT_ARGS_FOR_MACOS="-n -s -t -v -zkk"
assert 214


CAT_ARGS_FOR_MACOS="-n -s -t  -zkk"
assert 215


CAT_ARGS_FOR_MACOS="-n -s -v  -zkk"
assert 216


CAT_ARGS_FOR_MACOS="-n -t -v  -zkk"
assert 217


CAT_ARGS_FOR_MACOS="-s -t -v  -zkk"
assert 218


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v"
assert 219


CAT_ARGS_FOR_MACOS="-e -b -n -s -t "
assert 220


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -zkk"
assert 221


CAT_ARGS_FOR_MACOS="-e -b -n -s -v "
assert 222


CAT_ARGS_FOR_MACOS="-e -b -n -s -v -zkk"
assert 223


CAT_ARGS_FOR_MACOS="-e -b -n -s  -zkk"
assert 224


CAT_ARGS_FOR_MACOS="-e -b -n -t -v "
assert 225


CAT_ARGS_FOR_MACOS="-e -b -n -t -v -zkk"
assert 226


CAT_ARGS_FOR_MACOS="-e -b -n -t  -zkk"
assert 227


CAT_ARGS_FOR_MACOS="-e -b -n -v  -zkk"
assert 228


CAT_ARGS_FOR_MACOS="-e -b -s -t -v "
assert 229


CAT_ARGS_FOR_MACOS="-e -b -s -t -v -zkk"
assert 230


CAT_ARGS_FOR_MACOS="-e -b -s -t  -zkk"
assert 231


CAT_ARGS_FOR_MACOS="-e -b -s -v  -zkk"
assert 232


CAT_ARGS_FOR_MACOS="-e -b -t -v  -zkk"
assert 233


CAT_ARGS_FOR_MACOS="-e -n -s -t -v "
assert 234


CAT_ARGS_FOR_MACOS="-e -n -s -t -v -zkk"
assert 235


CAT_ARGS_FOR_MACOS="-e -n -s -t  -zkk"
assert 236


CAT_ARGS_FOR_MACOS="-e -n -s -v  -zkk"
assert 237


CAT_ARGS_FOR_MACOS="-e -n -t -v  -zkk"
assert 238


CAT_ARGS_FOR_MACOS="-e -s -t -v  -zkk"
assert 239


CAT_ARGS_FOR_MACOS="-b -n -s -t -v "
assert 240


CAT_ARGS_FOR_MACOS="-b -n -s -t -v -zkk"
assert 241


CAT_ARGS_FOR_MACOS="-b -n -s -t  -zkk"
assert 242


CAT_ARGS_FOR_MACOS="-b -n -s -v  -zkk"
assert 243


CAT_ARGS_FOR_MACOS="-b -n -t -v  -zkk"
assert 244


CAT_ARGS_FOR_MACOS="-b -s -t -v  -zkk"
assert 245


CAT_ARGS_FOR_MACOS="-n -s -t -v  -zkk"
assert 246


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v "
assert 247


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v -zkk"
assert 248


CAT_ARGS_FOR_MACOS="-e -b -n -s -t  -zkk"
assert 249


CAT_ARGS_FOR_MACOS="-e -b -n -s -v  -zkk"
assert 250


CAT_ARGS_FOR_MACOS="-e -b -n -t -v  -zkk"
assert 251


CAT_ARGS_FOR_MACOS="-e -b -s -t -v  -zkk"
assert 252


CAT_ARGS_FOR_MACOS="-e -n -s -t -v  -zkk"
assert 253


CAT_ARGS_FOR_MACOS="-b -n -s -t -v  -zkk"
assert 254


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v  -zkk"
assert 255


TEST_FILE=../tests/test/test_2.txt
CAT_ARGS_FOR_MACOS="-e"
assert 1


CAT_ARGS_FOR_MACOS="-b"
assert 2


CAT_ARGS_FOR_MACOS="-n"
assert 3


CAT_ARGS_FOR_MACOS="-s"
assert 4


CAT_ARGS_FOR_MACOS="-t"
assert 5


CAT_ARGS_FOR_MACOS="-v"
assert 6


CAT_ARGS_FOR_MACOS=""
assert 7


CAT_ARGS_FOR_MACOS="-zkk"
assert 8


CAT_ARGS_FOR_MACOS="-e -b"
assert 9


CAT_ARGS_FOR_MACOS="-e -n"
assert 10


CAT_ARGS_FOR_MACOS="-e -s"
assert 11


CAT_ARGS_FOR_MACOS="-e -t"
assert 12


CAT_ARGS_FOR_MACOS="-e -v"
assert 13


CAT_ARGS_FOR_MACOS="-e "
assert 14


CAT_ARGS_FOR_MACOS="-e -zkk"
assert 15


CAT_ARGS_FOR_MACOS="-b -n"
assert 16


CAT_ARGS_FOR_MACOS="-b -s"
assert 17


CAT_ARGS_FOR_MACOS="-b -t"
assert 18


CAT_ARGS_FOR_MACOS="-b -v"
assert 19


CAT_ARGS_FOR_MACOS="-b "
assert 20


CAT_ARGS_FOR_MACOS="-b -zkk"
assert 21


CAT_ARGS_FOR_MACOS="-n -s"
assert 22


CAT_ARGS_FOR_MACOS="-n -t"
assert 23


CAT_ARGS_FOR_MACOS="-n -v"
assert 24


CAT_ARGS_FOR_MACOS="-n "
assert 25


CAT_ARGS_FOR_MACOS="-n -zkk"
assert 26


CAT_ARGS_FOR_MACOS="-s -t"
assert 27


CAT_ARGS_FOR_MACOS="-s -v"
assert 28


CAT_ARGS_FOR_MACOS="-s "
assert 29


CAT_ARGS_FOR_MACOS="-s -zkk"
assert 30


CAT_ARGS_FOR_MACOS="-t -v"
assert 31


CAT_ARGS_FOR_MACOS="-t "
assert 32


CAT_ARGS_FOR_MACOS="-t -zkk"
assert 33


CAT_ARGS_FOR_MACOS="-v "
assert 34


CAT_ARGS_FOR_MACOS="-v -zkk"
assert 35


CAT_ARGS_FOR_MACOS=" -zkk"
assert 36


CAT_ARGS_FOR_MACOS="-e -b -n"
assert 37


CAT_ARGS_FOR_MACOS="-e -b -s"
assert 38


CAT_ARGS_FOR_MACOS="-e -b -t"
assert 39


CAT_ARGS_FOR_MACOS="-e -b -v"
assert 40


CAT_ARGS_FOR_MACOS="-e -b "
assert 41


CAT_ARGS_FOR_MACOS="-e -b -zkk"
assert 42


CAT_ARGS_FOR_MACOS="-e -n -s"
assert 43


CAT_ARGS_FOR_MACOS="-e -n -t"
assert 44


CAT_ARGS_FOR_MACOS="-e -n -v"
assert 45


CAT_ARGS_FOR_MACOS="-e -n "
assert 46


CAT_ARGS_FOR_MACOS="-e -n -zkk"
assert 47


CAT_ARGS_FOR_MACOS="-e -s -t"
assert 48


CAT_ARGS_FOR_MACOS="-e -s -v"
assert 49


CAT_ARGS_FOR_MACOS="-e -s "
assert 50


CAT_ARGS_FOR_MACOS="-e -s -zkk"
assert 51


CAT_ARGS_FOR_MACOS="-e -t -v"
assert 52


CAT_ARGS_FOR_MACOS="-e -t "
assert 53


CAT_ARGS_FOR_MACOS="-e -t -zkk"
assert 54


CAT_ARGS_FOR_MACOS="-e -v "
assert 55


CAT_ARGS_FOR_MACOS="-e -v -zkk"
assert 56


CAT_ARGS_FOR_MACOS="-e  -zkk"
assert 57


CAT_ARGS_FOR_MACOS="-b -n -s"
assert 58


CAT_ARGS_FOR_MACOS="-b -n -t"
assert 59


CAT_ARGS_FOR_MACOS="-b -n -v"
assert 60


CAT_ARGS_FOR_MACOS="-b -n "
assert 61


CAT_ARGS_FOR_MACOS="-b -n -zkk"
assert 62


CAT_ARGS_FOR_MACOS="-b -s -t"
assert 63


CAT_ARGS_FOR_MACOS="-b -s -v"
assert 64


CAT_ARGS_FOR_MACOS="-b -s "
assert 65


CAT_ARGS_FOR_MACOS="-b -s -zkk"
assert 66


CAT_ARGS_FOR_MACOS="-b -t -v"
assert 67


CAT_ARGS_FOR_MACOS="-b -t "
assert 68


CAT_ARGS_FOR_MACOS="-b -t -zkk"
assert 69


CAT_ARGS_FOR_MACOS="-b -v "
assert 70


CAT_ARGS_FOR_MACOS="-b -v -zkk"
assert 71


CAT_ARGS_FOR_MACOS="-b  -zkk"
assert 72


CAT_ARGS_FOR_MACOS="-n -s -t"
assert 73


CAT_ARGS_FOR_MACOS="-n -s -v"
assert 74


CAT_ARGS_FOR_MACOS="-n -s "
assert 75


CAT_ARGS_FOR_MACOS="-n -s -zkk"
assert 76


CAT_ARGS_FOR_MACOS="-n -t -v"
assert 77


CAT_ARGS_FOR_MACOS="-n -t "
assert 78


CAT_ARGS_FOR_MACOS="-n -t -zkk"
assert 79


CAT_ARGS_FOR_MACOS="-n -v "
assert 80


CAT_ARGS_FOR_MACOS="-n -v -zkk"
assert 81


CAT_ARGS_FOR_MACOS="-n  -zkk"
assert 82


CAT_ARGS_FOR_MACOS="-s -t -v"
assert 83


CAT_ARGS_FOR_MACOS="-s -t "
assert 84


CAT_ARGS_FOR_MACOS="-s -t -zkk"
assert 85


CAT_ARGS_FOR_MACOS="-s -v "
assert 86


CAT_ARGS_FOR_MACOS="-s -v -zkk"
assert 87


CAT_ARGS_FOR_MACOS="-s  -zkk"
assert 88


CAT_ARGS_FOR_MACOS="-t -v "
assert 89


CAT_ARGS_FOR_MACOS="-t -v -zkk"
assert 90


CAT_ARGS_FOR_MACOS="-t  -zkk"
assert 91


CAT_ARGS_FOR_MACOS="-v  -zkk"
assert 92


CAT_ARGS_FOR_MACOS="-e -b -n -s"
assert 93


CAT_ARGS_FOR_MACOS="-e -b -n -t"
assert 94


CAT_ARGS_FOR_MACOS="-e -b -n -v"
assert 95


CAT_ARGS_FOR_MACOS="-e -b -n "
assert 96


CAT_ARGS_FOR_MACOS="-e -b -n -zkk"
assert 97


CAT_ARGS_FOR_MACOS="-e -b -s -t"
assert 98


CAT_ARGS_FOR_MACOS="-e -b -s -v"
assert 99


CAT_ARGS_FOR_MACOS="-e -b -s "
assert 100


CAT_ARGS_FOR_MACOS="-e -b -s -zkk"
assert 101


CAT_ARGS_FOR_MACOS="-e -b -t -v"
assert 102


CAT_ARGS_FOR_MACOS="-e -b -t "
assert 103


CAT_ARGS_FOR_MACOS="-e -b -t -zkk"
assert 104


CAT_ARGS_FOR_MACOS="-e -b -v "
assert 105


CAT_ARGS_FOR_MACOS="-e -b -v -zkk"
assert 106


CAT_ARGS_FOR_MACOS="-e -b  -zkk"
assert 107


CAT_ARGS_FOR_MACOS="-e -n -s -t"
assert 108


CAT_ARGS_FOR_MACOS="-e -n -s -v"
assert 109


CAT_ARGS_FOR_MACOS="-e -n -s "
assert 110


CAT_ARGS_FOR_MACOS="-e -n -s -zkk"
assert 111


CAT_ARGS_FOR_MACOS="-e -n -t -v"
assert 112


CAT_ARGS_FOR_MACOS="-e -n -t "
assert 113


CAT_ARGS_FOR_MACOS="-e -n -t -zkk"
assert 114


CAT_ARGS_FOR_MACOS="-e -n -v "
assert 115


CAT_ARGS_FOR_MACOS="-e -n -v -zkk"
assert 116


CAT_ARGS_FOR_MACOS="-e -n  -zkk"
assert 117


CAT_ARGS_FOR_MACOS="-e -s -t -v"
assert 118


CAT_ARGS_FOR_MACOS="-e -s -t "
assert 119


CAT_ARGS_FOR_MACOS="-e -s -t -zkk"
assert 120


CAT_ARGS_FOR_MACOS="-e -s -v "
assert 121


CAT_ARGS_FOR_MACOS="-e -s -v -zkk"
assert 122


CAT_ARGS_FOR_MACOS="-e -s  -zkk"
assert 123


CAT_ARGS_FOR_MACOS="-e -t -v "
assert 124


CAT_ARGS_FOR_MACOS="-e -t -v -zkk"
assert 125


CAT_ARGS_FOR_MACOS="-e -t  -zkk"
assert 126


CAT_ARGS_FOR_MACOS="-e -v  -zkk"
assert 127


CAT_ARGS_FOR_MACOS="-b -n -s -t"
assert 128


CAT_ARGS_FOR_MACOS="-b -n -s -v"
assert 129


CAT_ARGS_FOR_MACOS="-b -n -s "
assert 130


CAT_ARGS_FOR_MACOS="-b -n -s -zkk"
assert 131


CAT_ARGS_FOR_MACOS="-b -n -t -v"
assert 132


CAT_ARGS_FOR_MACOS="-b -n -t "
assert 133


CAT_ARGS_FOR_MACOS="-b -n -t -zkk"
assert 134


CAT_ARGS_FOR_MACOS="-b -n -v "
assert 135


CAT_ARGS_FOR_MACOS="-b -n -v -zkk"
assert 136


CAT_ARGS_FOR_MACOS="-b -n  -zkk"
assert 137


CAT_ARGS_FOR_MACOS="-b -s -t -v"
assert 138


CAT_ARGS_FOR_MACOS="-b -s -t "
assert 139


CAT_ARGS_FOR_MACOS="-b -s -t -zkk"
assert 140


CAT_ARGS_FOR_MACOS="-b -s -v "
assert 141


CAT_ARGS_FOR_MACOS="-b -s -v -zkk"
assert 142


CAT_ARGS_FOR_MACOS="-b -s  -zkk"
assert 143


CAT_ARGS_FOR_MACOS="-b -t -v "
assert 144


CAT_ARGS_FOR_MACOS="-b -t -v -zkk"
assert 145


CAT_ARGS_FOR_MACOS="-b -t  -zkk"
assert 146


CAT_ARGS_FOR_MACOS="-b -v  -zkk"
assert 147


CAT_ARGS_FOR_MACOS="-n -s -t -v"
assert 148


CAT_ARGS_FOR_MACOS="-n -s -t "
assert 149


CAT_ARGS_FOR_MACOS="-n -s -t -zkk"
assert 150


CAT_ARGS_FOR_MACOS="-n -s -v "
assert 151


CAT_ARGS_FOR_MACOS="-n -s -v -zkk"
assert 152


CAT_ARGS_FOR_MACOS="-n -s  -zkk"
assert 153


CAT_ARGS_FOR_MACOS="-n -t -v "
assert 154


CAT_ARGS_FOR_MACOS="-n -t -v -zkk"
assert 155


CAT_ARGS_FOR_MACOS="-n -t  -zkk"
assert 156


CAT_ARGS_FOR_MACOS="-n -v  -zkk"
assert 157


CAT_ARGS_FOR_MACOS="-s -t -v "
assert 158


CAT_ARGS_FOR_MACOS="-s -t -v -zkk"
assert 159


CAT_ARGS_FOR_MACOS="-s -t  -zkk"
assert 160


CAT_ARGS_FOR_MACOS="-s -v  -zkk"
assert 161


CAT_ARGS_FOR_MACOS="-t -v  -zkk"
assert 162


CAT_ARGS_FOR_MACOS="-e -b -n -s -t"
assert 163


CAT_ARGS_FOR_MACOS="-e -b -n -s -v"
assert 164


CAT_ARGS_FOR_MACOS="-e -b -n -s "
assert 165


CAT_ARGS_FOR_MACOS="-e -b -n -s -zkk"
assert 166


CAT_ARGS_FOR_MACOS="-e -b -n -t -v"
assert 167


CAT_ARGS_FOR_MACOS="-e -b -n -t "
assert 168


CAT_ARGS_FOR_MACOS="-e -b -n -t -zkk"
assert 169


CAT_ARGS_FOR_MACOS="-e -b -n -v "
assert 170


CAT_ARGS_FOR_MACOS="-e -b -n -v -zkk"
assert 171


CAT_ARGS_FOR_MACOS="-e -b -n  -zkk"
assert 172


CAT_ARGS_FOR_MACOS="-e -b -s -t -v"
assert 173


CAT_ARGS_FOR_MACOS="-e -b -s -t "
assert 174


CAT_ARGS_FOR_MACOS="-e -b -s -t -zkk"
assert 175


CAT_ARGS_FOR_MACOS="-e -b -s -v "
assert 176


CAT_ARGS_FOR_MACOS="-e -b -s -v -zkk"
assert 177


CAT_ARGS_FOR_MACOS="-e -b -s  -zkk"
assert 178


CAT_ARGS_FOR_MACOS="-e -b -t -v "
assert 179


CAT_ARGS_FOR_MACOS="-e -b -t -v -zkk"
assert 180


CAT_ARGS_FOR_MACOS="-e -b -t  -zkk"
assert 181


CAT_ARGS_FOR_MACOS="-e -b -v  -zkk"
assert 182


CAT_ARGS_FOR_MACOS="-e -n -s -t -v"
assert 183


CAT_ARGS_FOR_MACOS="-e -n -s -t "
assert 184


CAT_ARGS_FOR_MACOS="-e -n -s -t -zkk"
assert 185


CAT_ARGS_FOR_MACOS="-e -n -s -v "
assert 186


CAT_ARGS_FOR_MACOS="-e -n -s -v -zkk"
assert 187


CAT_ARGS_FOR_MACOS="-e -n -s  -zkk"
assert 188


CAT_ARGS_FOR_MACOS="-e -n -t -v "
assert 189


CAT_ARGS_FOR_MACOS="-e -n -t -v -zkk"
assert 190


CAT_ARGS_FOR_MACOS="-e -n -t  -zkk"
assert 191


CAT_ARGS_FOR_MACOS="-e -n -v  -zkk"
assert 192


CAT_ARGS_FOR_MACOS="-e -s -t -v "
assert 193


CAT_ARGS_FOR_MACOS="-e -s -t -v -zkk"
assert 194


CAT_ARGS_FOR_MACOS="-e -s -t  -zkk"
assert 195


CAT_ARGS_FOR_MACOS="-e -s -v  -zkk"
assert 196


CAT_ARGS_FOR_MACOS="-e -t -v  -zkk"
assert 197


CAT_ARGS_FOR_MACOS="-b -n -s -t -v"
assert 198


CAT_ARGS_FOR_MACOS="-b -n -s -t "
assert 199


CAT_ARGS_FOR_MACOS="-b -n -s -t -zkk"
assert 200


CAT_ARGS_FOR_MACOS="-b -n -s -v "
assert 201


CAT_ARGS_FOR_MACOS="-b -n -s -v -zkk"
assert 202


CAT_ARGS_FOR_MACOS="-b -n -s  -zkk"
assert 203


CAT_ARGS_FOR_MACOS="-b -n -t -v "
assert 204


CAT_ARGS_FOR_MACOS="-b -n -t -v -zkk"
assert 205


CAT_ARGS_FOR_MACOS="-b -n -t  -zkk"
assert 206


CAT_ARGS_FOR_MACOS="-b -n -v  -zkk"
assert 207


CAT_ARGS_FOR_MACOS="-b -s -t -v "
assert 208


CAT_ARGS_FOR_MACOS="-b -s -t -v -zkk"
assert 209


CAT_ARGS_FOR_MACOS="-b -s -t  -zkk"
assert 210


CAT_ARGS_FOR_MACOS="-b -s -v  -zkk"
assert 211


CAT_ARGS_FOR_MACOS="-b -t -v  -zkk"
assert 212


CAT_ARGS_FOR_MACOS="-n -s -t -v "
assert 213


CAT_ARGS_FOR_MACOS="-n -s -t -v -zkk"
assert 214


CAT_ARGS_FOR_MACOS="-n -s -t  -zkk"
assert 215


CAT_ARGS_FOR_MACOS="-n -s -v  -zkk"
assert 216


CAT_ARGS_FOR_MACOS="-n -t -v  -zkk"
assert 217


CAT_ARGS_FOR_MACOS="-s -t -v  -zkk"
assert 218


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v"
assert 219


CAT_ARGS_FOR_MACOS="-e -b -n -s -t "
assert 220


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -zkk"
assert 221


CAT_ARGS_FOR_MACOS="-e -b -n -s -v "
assert 222


CAT_ARGS_FOR_MACOS="-e -b -n -s -v -zkk"
assert 223


CAT_ARGS_FOR_MACOS="-e -b -n -s  -zkk"
assert 224


CAT_ARGS_FOR_MACOS="-e -b -n -t -v "
assert 225


CAT_ARGS_FOR_MACOS="-e -b -n -t -v -zkk"
assert 226


CAT_ARGS_FOR_MACOS="-e -b -n -t  -zkk"
assert 227


CAT_ARGS_FOR_MACOS="-e -b -n -v  -zkk"
assert 228


CAT_ARGS_FOR_MACOS="-e -b -s -t -v "
assert 229


CAT_ARGS_FOR_MACOS="-e -b -s -t -v -zkk"
assert 230


CAT_ARGS_FOR_MACOS="-e -b -s -t  -zkk"
assert 231


CAT_ARGS_FOR_MACOS="-e -b -s -v  -zkk"
assert 232


CAT_ARGS_FOR_MACOS="-e -b -t -v  -zkk"
assert 233


CAT_ARGS_FOR_MACOS="-e -n -s -t -v "
assert 234


CAT_ARGS_FOR_MACOS="-e -n -s -t -v -zkk"
assert 235


CAT_ARGS_FOR_MACOS="-e -n -s -t  -zkk"
assert 236


CAT_ARGS_FOR_MACOS="-e -n -s -v  -zkk"
assert 237


CAT_ARGS_FOR_MACOS="-e -n -t -v  -zkk"
assert 238


CAT_ARGS_FOR_MACOS="-e -s -t -v  -zkk"
assert 239


CAT_ARGS_FOR_MACOS="-b -n -s -t -v "
assert 240


CAT_ARGS_FOR_MACOS="-b -n -s -t -v -zkk"
assert 241


CAT_ARGS_FOR_MACOS="-b -n -s -t  -zkk"
assert 242


CAT_ARGS_FOR_MACOS="-b -n -s -v  -zkk"
assert 243


CAT_ARGS_FOR_MACOS="-b -n -t -v  -zkk"
assert 244


CAT_ARGS_FOR_MACOS="-b -s -t -v  -zkk"
assert 245


CAT_ARGS_FOR_MACOS="-n -s -t -v  -zkk"
assert 246


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v "
assert 247


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v -zkk"
assert 248


CAT_ARGS_FOR_MACOS="-e -b -n -s -t  -zkk"
assert 249


CAT_ARGS_FOR_MACOS="-e -b -n -s -v  -zkk"
assert 250


CAT_ARGS_FOR_MACOS="-e -b -n -t -v  -zkk"
assert 251


CAT_ARGS_FOR_MACOS="-e -b -s -t -v  -zkk"
assert 252


CAT_ARGS_FOR_MACOS="-e -n -s -t -v  -zkk"
assert 253


CAT_ARGS_FOR_MACOS="-b -n -s -t -v  -zkk"
assert 254


CAT_ARGS_FOR_MACOS="-e -b -n -s -t -v  -zkk"
assert 255

