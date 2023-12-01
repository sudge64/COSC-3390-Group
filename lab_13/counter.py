"""
This program is for taking in a C++ file,
counting the classes, lines, and comments, and outputing the results
"""
import sys
import getopt
import re


def open_file(file_input):
    """
    Function to open a file and save each line to a list
    """
    with open(file_input, 'r', encoding='UTF-8') as file_one:
        list_of_lines = file_one.readlines()
    file_one.close()

    num_lines = 0
    num_class = 0
    num_comments = 0
    class_lines = 0
    class_comments = 0
    for current in list_of_lines:
        if re.search('^class.*', current):
            class_lines += class_counter_line(current, list_of_lines)
            print(class_lines)
            class_comments += class_counter_comment(current, list_of_lines)
            print(class_comments)
            num_class += 1
        if re.search(' *//.*', current):
            num_comments += 1
            num_lines -= 1
        if re.search('^\s*$', current):
            num_lines -= 1
        if re.search('^int main.*', current):
            print("FOUND! Main")
            num_lines -= 1
            break
        num_lines += 1

    print("\nTotals:\n")
    print(F"\tClasses:\t\t{num_class}")
    print(F"\tLines Count:\t\t{num_lines}")
    print(F"\tComments Count:\t\t{num_comments}")
    print(F"\tComments density:\t{(num_comments / num_lines) * 100} %")
    print(F"\tLines Avg:\t\t{(class_lines / num_class)}")
    print(F"\tComments Avg:\t\t{class_comments / num_class}")


def class_counter_line(current, list_of_lines):
    """
    Function to count lines of classes and return the number of lines
    """
    class_name = current
    class_lines = 0
    class_comments = 0

    for current in list_of_lines:
        if re.search(' *//.*', current):
            class_comments += 1
            class_lines -= 1
        if re.search('^\s*$', current):
            class_lines -= 1
        if re.search('^};*', current):
            break
        class_lines += 1

    print(F"\n{class_name}")
    print(F"\tLines Count: {class_lines}", end="")
    print(F", Comments Count: {class_comments}", end="")
    print(F", Comments density: {(class_comments / class_lines) * 100} %")
    return class_lines


def class_counter_comment(current, list_of_lines):
    """
    Function to count lines of classes and return the number of comments
    """
    class_name = current
    class_lines = 0
    class_comments = 0

    for current in list_of_lines:
        if re.search(' *//.*', current):
            class_comments += 1
            class_lines -= 1
        if re.search('^\s*$', current):
            class_lines -= 1
        if re.search('^};*', current):
            break
        class_lines += 1

    print(F"\n{class_name}")
    print(F"\tLines Count: {class_lines}", end="")
    print(F", Comments Count: {class_comments}", end="")
    print(F", Comments density: {(class_comments / class_lines) * 100} %")
    return class_comments


def main(argv):
    """
    Main Function, handles reading arguments passed in from command line
    """
    input_file = ''
    opts, arg = getopt.getopt(argv, "hi:", ["ifile="])
    for opt, arg in opts:
        if opt == '-h':
            print('<filename>.py -i <inputfile>')
            sys.exit()
        elif opt in ("-i", "--ifile"):
            input_file = arg
        else:
            print('Correct usage is: <filename>.py -i <inputfile>')
    print('Input file is', input_file)
    open_file(input_file)


if __name__ == "__main__":
    main(sys.argv[1:])
