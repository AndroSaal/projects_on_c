import itertools
import subprocess

flags = ['-e', '-E', '-b', '--number-nonblank', '-n', '--number', '-s', '--squeeze-blank', '-t', '-T', '-v']

combinations = []
for i in range(1, len(flags) + 1):
    combinations.extend(list(itertools.combinations(flags, i)))

with open("cat_test_combinations.sh", "w") as testFile:
    for i in range(len(combinations)):
        # testFile.write(f'CAT_ARGS="{" ".join(list(combinations[i]))}"\nassert {i+1}\n\n')

        testFile.write(f'CAT_ARGS="{" ".join(list(combinations[i]))}"\n')
        testFile.write('TEST_FILE="../../datasets/synthetic_file.txt ../../datasets/Lem-Eden.txt"\n')
        testFile.write(f'assert {(i+1)*2-1}\n')
        testFile.write('TEST_FILE="../../datasets/Lem-Eden.txt ../../datasets/synthetic_file.txt"\n')
        testFile.write(f'assert {(i+1)*2}\n\n')
