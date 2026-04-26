#!/bin/bash

TEST1=(
    "2 2 +"
    "3 4 + 2 *"
    "5 6 * 7 +"
	"3 4 + 2 * 5 -"
	"5 1 - 4 * 2 /"
	"3 6 - 3 / 9 4 + *"
	"5 1 - 4 * 0 /"
	"3 6 - 0 / 9 4 + *"
)

TEST2=(
	"7 2 3 4 5 1 + * / - +"
	"9 8 7 6 5 4 / / / / /"
	"3 9 1 4 2 5 + - * / +"
	"8 2 4 1 5 1 * * * * /"
	"8 7 6 5 4 3 / * / * /"
	"4 3 2 0 5 1 - * / - +"
	"5 1 - 4 * 0 /"
	"3 6 - 0 / 9 4 + *"
	"4 3 2 4 5 1 - - / - +"
)

TESTERR=(
	""
	"    "
	"2 + 2"
	"8 2 4 1 5 1 * * * * / a"
	"8 2 4 1 5 1 * * * */ "
	"3 6 - 3 / 9 4  + *"
	"3 6 - 3 / * 4 + *"
	"36 - 3 / 9 4 + *"
)

TESTSPACE=(
	"8 7 6 5 4 3 / * / * /"
	" 8 7 6 5 4 3 / * / * /"
	"8 7 6 5 4 3 / * / * / "
	" 8 7 6 5 4 3 / * / * / "
	"  8 7 6 5 4 3 / * / * / "
	" 8 7 6 5 4 3 / * / * /  "
	"  8 7 6 5 4 3 / * / * /  "
)

TEST42=(
	"8 9 * 9 - 9 - 9 - 4 - 1 +"
	"8 5 * 4 3 * + 2 5 * -"
	"7 5 * 6 3 * + 2 9 + -"
)

show_usage() {
    echo "Usage: $0 [test_name]"
    echo "Available tests:"
    echo "  easy       - Test basic expressions"
    echo "  advanced   - Test sophisticated expressions"
    echo "  errors     - Test wrong expressions"
    echo "  spaces     - Test space handling"
    echo "  answer     - Get the answer to everything"
    echo "  all        - Run all tests"
	exit
}

check_directory() {
if [[ $(basename "$PWD") == "tester" ]]; then 
cd ..
fi
}

run_easy() {
make -s
# Run 1st set of tests
for ARG in "${TEST1[@]}"; do
    echo $'\n'"Testing: \"$ARG\""
    ./RPN "$ARG"
done
}

run_sophis() {
echo $'\n'Running more sophisticated expresions in Verbose mode:
make -s verbo
# Run 2nd set of tests
for ARG in "${TEST2[@]}"; do
    echo $'\n'"Testing: \"$ARG\""
    ./RPN "$ARG"
done
}

run_errors() {
echo $'\n'Running incomplete or wrong expresions in silent mode:
make -s
# Run 3rd set of tests
for ARG in "${TESTERR[@]}"; do
    echo $'\n'"Testing: \"$ARG\""
    ./RPN "$ARG"
done

echo $'\n'"Testing: $ARG (more than 1 argument)"
./RPN $ARG
echo $'\n'"Testing: (no argument)"
./RPN

echo $'\n'Running incomplete or wrong expresions in verbose mode:
make -s verbo
# Run 3rd set of tests
for ARG in "${TESTERR[@]}"; do
    echo $'\n'"Testing: \"$ARG\""
    ./RPN "$ARG"
done

echo $'\n'Running incomplete or wrong expresions in silent mode:
make -s verbo
# Run 3rd set of tests
for ARG in "${TESTERR[@]}"; do
    echo $'\n'"Testing: \"$ARG\""
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./RPN "$ARG"
done
}

run_spaces() {
make -s verbo
echo $'\n'Handling initial spaces in verbose mode:
for ARG in "${TESTSPACE[@]}"; do
    echo $'\n'"Testing: \"$ARG\""
    ./RPN "$ARG"
done
}

run_answer() {
echo $'\n'"Any doubt?"
make -s
for ARG in "${TEST42[@]}"; do
	echo -e $'\n'"If \e[3;34m$ARG\e[0m"
	echo -n -e $'\n'"Then, the answer is: \e[32m";./RPN "$ARG"
    echo -e -n "\e[0m"
done
}

run_all() {
run_easy
run_sophis
run_errors
run_spaces
run_answer
}

check_directory

case "${1:-help}" in
    "easy")
        run_easy
        ;;
    "advanced")
        run_sophis
        ;;
    "errors")
        run_errors
        ;;
    "spaces")
        run_spaces
        ;;
    "answer")
        run_answer
        ;;
    "all")
        run_all
        ;;
    "-h"|"--help"|"help")
        show_usage
        ;;
    *)
        echo "Unknown test: $1"
        show_usage
        exit 1
        ;;
esac
make -s fclean

