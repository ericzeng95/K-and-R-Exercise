/* exercise 5-10: implement reverse polish expression */

#include <stdio.h>
#define MAX_LENGTH 100

int isOperator(char *);
double toNumber(char *);

int main(int argc, char *argv[]) {
    double to_process[MAX_LENGTH]; // to store to process
    int toProcess = 0;
    /* printf("is operator?: %d\n", isOperator("123")); */
    /* printf("is operator?: %d\n", isOperator("-")); */
    /* printf("is operator?: %d\n", isOperator("+")); */
    /* printf("is operator?: %d\n", isOperator("+1")); */
    /* printf("tonumber: %f\n", toNumber("123")); */
    /* printf("tonumber: %f\n", toNumber("012")); */
    /* printf("tonumber: %f\n", toNumber("010")); */
    while (--argc > 0) {
		argv++;
        double calculation = 0;
        // evaluate the to_process array
        if (toProcess < 2 && isOperator(*argv) > 0) {
            printf("Invalid format\n");
            return -1;
        }
        if (isOperator(*argv) == -1) {
            printf("Invalid format\n");
            return -1;
        }
        if (isOperator(*argv) == 0) {
            *(to_process + toProcess++) = toNumber(*argv);
        } else {
            switch (isOperator(*argv)) {
            case 1:
                calculation =
                    *(to_process + toProcess - 2) + *(to_process + toProcess-1);
                break;
            case 2:
                calculation =
                    *(to_process + toProcess - 2) - *(to_process + toProcess-1);
                break;
            case 3:
                calculation =
                    *(to_process + toProcess - 2) * *(to_process + toProcess-1);
                break;
            case 4:
                calculation =
                    *(to_process + toProcess - 2) / *(to_process + toProcess-1);
                break;
            }
            *(to_process + toProcess-- - 2) = calculation;
        }
    }
	printf("Result: %f\n", *to_process);
}
int isOperator(char *input) {
    // to determine if an input is operator or not
    // to return:
    // invalid input (eg. +12)
    // 0 if number (123)
    // 1 if +
    // 2 if -
    // 3 if *
    // 4 if /

    // before going into loop, first validate
    // if the input argument is a valid input
    for (int i = 0; *(input + i); i++) {
        if (*(input + i) >= '0' && *(input + i) <= '9') {
            continue;
        } else if ((i == 0) &&
                   (*input == '+' || *input == '-' || *input == '*' ||
                    *input == '/') &&
                   !*(input + 1)) {
            break;
        } else {
            return -1;
        }
    }

    int res = 0;
    switch (input[0]) {
    case '+':
        res = 1;
        break;
    case '-':
        res = 2;
        break;
    case '*':
        res = 3;
        break;
    case '/':
        res = 4;
        break;
    default:
        break;
    }
    return res;
}

double toNumber(char *input) {
    // (try to) convert a string to number
    // *input is assured to be a number string
    double res = 0;
    while (*input) {
        res = res * 10 + (*(input++) - '0');
    }
    return res;
}

