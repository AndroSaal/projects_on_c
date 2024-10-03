import itertools

print("ok")
flags = ['-e', '-b', '-n', '-s', '-t', '-v', '', '-zkk']

combinations = []
for i in range(1, len(flags) + 1):
    combinations.extend(list(itertools.combinations(flags, i)))

with open("/Users/andro/Desktop/Code/school42/main_education/simple_bash/C3_SimpleBashUtils-1/src/tests/cat_test_combinations_1_for_macos.sh", "a") as testFile:
    for j in range(6):
        testFile.write('\n')
        testFile.write(f'TEST_FILE=test/test_{j+1}.txt')
        for i in range(len(combinations)):
            testFile.write('\n')
            testFile.write(f'CAT_ARGS_FOR_MACOS="{" ".join(list(combinations[i]))}"\n')
            testFile.write(f'assert {(i+1)}\n')
            testFile.write('\n')
